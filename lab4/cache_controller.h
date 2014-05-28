#ifndef CACHE_CONTROLLER_H_
#define CACHE_CONTROLLER_H_

#include "enum.h"
#include <cstdlib>
#include <iostream>

class Bus;

class CacheController {
	public:
		CacheController(Bus *bus, int cacheSize = 4, int waySize = 1, int blockSize = 1);
		~CacheController();
		void accessFromProcessor(ProcessorAccessType pat, AddressType address);
		void accessFromBus(BusTransaction bt, AddressType address);

	private:
		int cacheSize;
		int waySize;
		int blockSize;
		int setSize;
		Bus *bus;
		CacheState *states;
		AddressType *tags;

		void readHit(int index, AddressType address);
		void readMiss(int index, AddressType address);
		void writeHit(int index, AddressType address);
		void writeMiss(int index, AddressType address);

};

#endif // CACHE_CONTROLLER_H_
