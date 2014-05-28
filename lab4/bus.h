#ifndef BUS_H_
#define BUS_H_

#include "enum.h"
#include <vector>

class CacheController;

class Bus {
	public:
		void addCacheController(CacheController *);
		void notify();
		
		AddressType getAddress() const
		{
			return address;
		}

		BusTransaction getBusTransaction() const
		{
			return busTransaction;
		}

		void setBus(BusTransaction bt, AddressType addr)
		{
			address = addr;
			busTransaction = bt;
		}

	private:
		AddressType address;
		BusTransaction busTransaction;
		std::vector<CacheController *>cacheControllers;

};

#endif  // BUS_H_
