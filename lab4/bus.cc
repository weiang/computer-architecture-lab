#include "bus.h"
#include "cache_controller.h"

void Bus::addCacheController(CacheController* cc)
{
	cacheControllers.push_back(cc);
}

void Bus::notify()
{
	BusTransaction bs = busTransaction;
	AddressType addr = address;
	for (int i = 0; i < cacheControllers.size(); i ++) {
		cacheControllers[i]->accessFromBus(bs, addr);
	}
}

