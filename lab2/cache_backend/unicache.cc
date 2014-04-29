/*************************************************************************
	> File Name: unicache.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月10日 星期四 20时30分55秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include "unicache.h"

using namespace std;

int UNICache::cycle = 0;

void UNICache::createUNICache()
{
	timeStamp = new int*[sizeSet];
	for (int i = 0; i != sizeSet; i ++) {
		timeStamp[i] = new int[sizeWay];
		for (int j = 0; j != sizeWay; j ++) {
			timeStamp[i][j] = -1;
		}
	}
    tag = new ADDRESSBITS*[sizeSet];
	valid = new bool*[sizeSet];
	for (int i = 0; i != sizeSet; i ++) {
        tag[i] = new ADDRESSBITS[sizeWay];
		valid[i] = new bool[sizeWay];
		for (int j = 0; j != sizeWay; j ++)
			valid[i][j] = false;
	}
}

void UNICache::destroyUNICache()
{
	for (int i = 0; i != sizeSet; i ++) {
		delete[] timeStamp[i];
		delete[] valid[i];
		delete[] tag[i];
	}
	delete[] timeStamp;
	delete[] valid;
	delete[] tag;
}

void UNICache::replaceBlock(ADDRESSBITS accessTag, ADDRESSBITS setNum)
{
	int min = 0;
	int rb;
	for (int i = 0; i != sizeWay; i ++) {
		if (valid[setNum][i] == false) {
			valid[setNum][i] = true;
			tag[setNum][i] = accessTag;
			timeStamp[setNum][i] = cycle;
			return;
		}
	}
	switch (replaceMethod) {
		case LRU:
		case FIFO:
			for (int i = 1;i != sizeWay; i ++) {
				if (timeStamp[setNum][min] > timeStamp[setNum][i])
					min = i;
			}
			timeStamp[setNum][min] = cycle;
			tag[setNum][min] = accessTag;
			break;
		case RANDOM:
            rb = rand() % sizeWay;
			tag[setNum][rb] = accessTag;
			break;
	}
}

bool UNICache::singleCacheAccessAux(int kind, ADDRESSBITS address)
{
    ADDRESSBITS maskIndex = 0;
    for (int i = 0; i != bitsOfIndex; i ++)
        maskIndex += (1 << i);

//	cout << "maskIndex = " <<  maskIndex << endl;
    ADDRESSBITS accessTag = address >> (bitsOfOffset + bitsOfIndex);
    ADDRESSBITS accessIndex = (address >> bitsOfOffset) & maskIndex;

	cycle ++; 

	bool result;
	if (kind == 0) {	// Read data
			readDNum ++;
            if ((result = cacheRead(accessTag, accessIndex)))
				readDHitNum ++;
			else 
				readDMissNum ++;
	}
	else if (kind == 1) { // Write data
		writeNum ++;
        if ((result = cacheWrite(accessTag, accessIndex)))
			writeHitNum ++;
		else 
			writeMissNum ++;
	}
	else {	// Read Instruction
		readINum ++;
        if ((result = cacheRead(accessTag, accessIndex)))
				readIHitNum ++;
		else 
			readIMissNum ++;
	}
    return result;
}

bool UNICache::singleCacheAccess(int kind, ADDRESSBITS address)
{
    bool result;
    result = singleCacheAccessAux(kind, address);
    if (!result && prefetchMethod == PM_USE) {
        ADDRESSBITS newAddress = address + sizeBlock;
        if (newAddress <= MAXADDRESS)
            singleCacheAccessAux(kind, newAddress);
    }
    return result;
}

bool UNICache::cacheRead(ADDRESSBITS readTag, int readIndex)
{
	for (int i = 0; i != sizeWay; i ++) {
		if (valid[readIndex] && tag[readIndex][i] == readTag) {
			readHit(readIndex, i);
			return true;
		}
	}
	readMiss(readTag, readIndex);
	return false;
}

void UNICache::readHit(int setNum, int blockNum)
{
	switch (replaceMethod) {
		case LRU:
			timeStamp[setNum][blockNum] = cycle;
			break;
        case FIFO:
		case RANDOM:
			break;
	}
}


void UNICache::readMiss(ADDRESSBITS readTag, int setNum)
{
	replaceBlock(readTag, setNum);
	
	// Prefetch
//	if (prefetchMethod == PM_USE && (setNum + 1) < sizeSet)
//		replaceBlock(readTag, setNum + 1);
}

bool UNICache::cacheWrite(ADDRESSBITS writeTag, int writeIndex)
{
//	cout << "In cacheWrite" << endl;
	for (int i = 0; i != sizeWay; i ++) {
		if (tag[writeIndex][i] == writeTag && valid[writeIndex][i] == true) {
			writeHit(writeIndex, i);
			return true;
		}
	}
	writeMiss(writeTag, writeIndex);
	return false;
}

void UNICache::writeHit(int setNum, int blockNum)
{
	switch (replaceMethod) {
		case LRU:
			timeStamp[setNum][blockNum] = cycle;
			break;
		case FIFO:
		case RANDOM:
			break;
	}
}

void UNICache::writeMiss(ADDRESSBITS writeTag, int setNum)
{	
	// 写不命中时调块策略
	if (blockFetchMethod == BFM_NOUSE) {	// 不按写分配

	}
	else {	// 按写分配
		replaceBlock(writeTag, setNum);
        // 不命中预取
 //       if (prefetchMethod == PM_USE && (setNum + 1) < sizeSet)
 //           replaceBlock(writeTag, setNum + 1);

	}
}


void UNICache::showConfig() const
{
	cout << string(25, '*') << endl;
	cout << "Unified Cache" << endl; 
	cout << "Cache Size: " << sizeCache / 1024<< "k" << endl;
	cout << "Tag bits: " << bitsOfTag << endl;
	cout << "Block size: " << sizeBlock << "b" << endl; 
	cout << "Block bits: " << bitsOfOffset << endl;
	cout << "Way size: " << sizeWay << endl;
	cout << "Index bits: " << bitsOfIndex << endl;

	cout << "Map method: ";
	if (sizeWay == 1)
		cout << "Direct mapped" << endl;
	else if (sizeWay == sizeCache / sizeBlock)
		cout << "Full mapped" << endl;
	else
		cout << "Set associativity" << endl;

	cout << "Replace method: ";
	switch (replaceMethod) {
		case LRU:
			cout << "LRU" << endl;
			break;
		case FIFO:
			cout << "FIFO" << endl;
			break;
		case RANDOM:
			cout << "RANDOM" << endl;
			break;
		default:
			cout << "UNKNOWN" << endl;
	}

	cout << "Prefetch method: ";
	if (prefetchMethod == PM_NOUSE)
		cout << "NO" << endl;
	else 
		cout << "YES" << endl;

	cout << "Write method: ";
	if (writeMethod == WB)
		cout << "Write Back" << endl;
	else
		cout << "Write Through" << endl;
	cout << "Block fetch method: ";
	if (blockFetchMethod == BFM_NOUSE)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	cout << string(25, '*') << endl;
}

void UNICache::cacheAccess(const string& filename)
{
	ifstream infile(filename.c_str());

	while (!infile.eof()) {
		string cmd;
		getline(infile, cmd);
		vector<string> fields;
		fields = split(cmd, string(" "));
		if (fields[0] == string(""))
			break;
		int cmdKind = atoi(fields[0].c_str());
        ADDRESSBITS address = hexStrToDec(fields[1]);
		singleCacheAccess(cmdKind, address);	
	}

}

void UNICache::printResult() const
{
	int totalAccess = readINum + readDNum + writeNum; 
	int totalMiss = readIMissNum + readDMissNum + writeMissNum; 
	int totalHit = readIHitNum + readDHitNum + writeHitNum;
	cout << "Total Access:     " << totalAccess 
		 << " Total Miss:     " << totalMiss
		 << " Total Hit:     " <<  totalHit
		 << " Miss Rate: " << static_cast<double>(totalMiss) / totalAccess
		 << endl;
	cout << "Read Inst Access: " << readINum
		 << " Read Inst Miss: " << readIMissNum
		 << " Read Inst Hit: " << readIHitNum
		 << " Miss Rate: " << static_cast<double>(readIMissNum) / readINum
		 << endl;
	cout << "Read Data Access: " << readDNum 
		 << " Read Data Miss: " << readDMissNum
		 << " Read Data Hit: " << readDHitNum
		 << " Miss Rate: " << static_cast<double>(readDMissNum) / readDNum
		 << endl;
	cout << "Write Access:     " << writeNum
		 << " Write Miss:     " << writeMissNum
		 << " Write Hit:     " << writeHitNum
		 << " Miss Rate: " << static_cast<double>(writeMissNum) / writeNum
		 << endl;
}

