#include "cache_controller.h"
#include "bus.h"

using namespace std;

CacheController::CacheController(Bus *bus, int cacheSize, int waySize, int blockSize) 
	: bus(bus), cacheSize(cacheSize), waySize(waySize), blockSize(blockSize)
{
	states = new CacheState[cacheSize / blockSize];
	tags = new AddressType[cacheSize / blockSize];

	setSize = cacheSize / blockSize / waySize;

	for (int i = 0; i < cacheSize; i ++) {
		states[i] = Invalid;
	}
}

CacheController::~CacheController() 
{
	if (cacheSize > 0) {
		delete[] states;
		delete[] tags;
	}
}

void CacheController::accessFromProcessor(ProcessorAccessType pat, AddressType address)
{
	AddressType tag;
	int setNum = (address / blockSize) % setSize;	// Set Number
	tag = address / blockSize / setSize;

	int index = setNum * waySize;
	int i;
	for (i = 0; i < waySize; i ++) {
		cout << "states: " << states[index + i] << endl;
		if (tags[index + i] == tag && states[index + i] != Invalid) {
			index += i;
			break;
		}
	}

	if (i != waySize) {
		if (pat == WT) {	// Write hit
			writeHit(index, address);
		}
		else if (pat == RD) {	// Read hit
			readHit(index, address);
		}
	}
	else {	// Access miss
		if (pat == WT) {	// Write miss
			writeMiss(index, address);
		}
		else if (pat == RD) {	// Read miss
			readMiss(index, address);
		}
	}
}

void CacheController::readHit(int index, AddressType address)
{
	cout << "Read Hit: " << address << endl;
	// Normal hit: Read data in local cache
}

void CacheController::writeHit(int index, AddressType address)
{
	cout << "Write Hit: ";
	if (states[index] == Modified) { 
		// Normal hit: write data in local cache
		cout << "(Modified) " << endl;
	}
	else {		
		cout << "(Shared) ";
		cout << "Put Rdx transaction on bus" << endl;
		bus->setBus(Rdx, address);	// Put "Rdx" on bus
		bus->notify();
		states[index] = Modified;	// Change state
	}
}

void CacheController::readMiss(int index, AddressType address)
{
	cout << "Read Miss: ";
	cout << "Put Rd transaction on bus" << endl;
	bus->setBus(Rd, address);	// Put "Rd" on bus
	bus->notify();

	address /= (blockSize * setSize);
	int i;
	for (i = 0; i < waySize; i ++) {
		if (states[index + i] == Invalid) {
			tags[index + i] = address;
			states[index + i] = Shared;
			break;
		}
	}
	if (i == waySize) {
		// Random replace method
		cout << "Replace happened!" << endl;
		i = rand() % waySize;
		if (states[index + i] == Modified) {
			AddressType tmp = tags[index + i] * blockSize * setSize;
			bus->setBus(Flush, tmp);	// Put "Flush" on bus, write dirty block back to memory
			bus->notify();
		}
		else if (states[index + i] == Shared) {
			cout << "Shared" << endl;
			tags[index + i] = address;
			states[index + i] = Shared;
		}
	}
}

void CacheController::writeMiss(int index, AddressType address)
{
	cout << "Write Miss: ";
	cout << "Put Rdx transaction on Bus" << endl;
	bus->setBus(Rdx, address);	// Put "Rdx" on bus
	bus->notify();

	int i;
	address /= (blockSize * setSize);
	for (i = 0; i < waySize; i ++) {
		if (states[index + i] == Invalid) {
			tags[index + i] = address;
			states[index + i] = Modified;
			break;
		}	
	}
	if (i == waySize) {
		cout << "Replace happened!" << endl;
		i = rand() % waySize;
		if (states[index + i] == Modified) {
			AddressType tmp = tags[index + i] * blockSize * setSize;
			bus->setBus(Flush, tmp);	// Put "Flush" on bus, write back dirty block
			bus->notify();
			states[index + i] = Modified;
			tags[index + i] = address;
		}
	}
}

void CacheController::accessFromBus(BusTransaction bt, AddressType address)
{
	AddressType tag = address / blockSize / setSize;
	int index = (address / blockSize) % setSize;
	index *= waySize;
	int i;
	switch (bt) {
		case Rd:
			cout << "Snoop Rd transaction" << endl;
			for (i = 0; i < waySize; i ++) {
				if (tags[index + i] == tag && states[index + i] == Modified) {
					AddressType tmp = tags[index + i] * (blockSize * setSize);
					bus->setBus(Flush, tmp);
					bus->notify();
					states[index + i] = Shared;
				}
			}
			break;

		case Rdx:
			cout << "Snoop Rdx transaction" << endl;
			for (i = 0; i < waySize; i ++) {
				if (tags[index + i] == tag) {
					if (states[index + i] == Shared) {
						states[index + i] = Invalid;
					}
					else if (states[index + i] == Modified) {
						cout << "Write Back to Memory" << endl;
						AddressType tmp = tags[index + i] * blockSize * setSize;
						bus->setBus(Flush, tmp);	// Put "Flush" on bus, write dirty block back to memory
						bus->notify();
						states[index + i] = Invalid;
					}
					else {
						// No action
					}
				}
			}
			break;
		case Flush:
			cout << "Snoop Flush transaction" << endl;
			break;
		default:
			;
	}
}

