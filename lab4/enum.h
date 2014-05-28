#ifndef ENUM_H_
#define ENUM_H_

typedef int AddressType;

enum CacheState {
	Invalid,
	Shared,
	Modified
};

enum ProcessorAccessType {
	RD, 
	WT
};

enum BusTransaction {
	Rd,
	Rdx,
	Flush
};

#endif // ENUM_H_