/*************************************************************************
	> File Name: cache.h
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月08日 星期二 22时54分24秒
    > Describition: 
 ************************************************************************/
#ifndef CACHE_H_
#define CACHE_H_

#include <iostream>
#include <vector>
#include <string>

typedef long ADDRESSBITS;
const ADDRESSBITS MAXADDRESS = 0xffffffff;

int log2(int x);
int iExp(int x);
std::vector<std::string> split(std::string, std::string);
int hexStrToDec(const std::string&);

/*
 * Cache kind
 */
enum CacheKind {
    UNI,
    ID
};

/*
 * Replacement algorithms used when cache missing happens
 */
enum ReplaceMethod {
	RANDOM,
	FIFO,
	LRU
};

/*
 * Cache mapping method 
 */
enum MappingMethod {
	DIRECT,		// Direct-mapped
	SET,		// Set associativity
	FULL		// Fully associativity
};

/*
 * Prefecth algorithms used 
 */
enum PrefetchMethod {
	PM_NOUSE,		// Not be used
	PM_USE
};

/*
 * Write method used when store instruction is executed
 */
enum WriteMethod {
	WB,		// Write back
	WT		// Write through
};

/*
 * Fetch block method when writing to memory is not hit
 */
enum BlockFetchMethod {
	BFM_NOUSE,	// Not be used
	BFM_USE
};

/*
 * Physical Address Structure
 *
 ****************************************
 *	tag		*	set index	*	offset	*	
 ****************************************
 */

class Cache
{
	public:
		Cache(int sb = 32, int sw = 1,
			ReplaceMethod rm = LRU,
			PrefetchMethod pm = PM_NOUSE,
			WriteMethod wm = WB,
			BlockFetchMethod bfm = BFM_NOUSE)
		  : sizeBlock(sb), sizeWay(sw),
			replaceMethod(rm),
			prefetchMethod(pm),
			writeMethod(wm),
			blockFetchMethod(bfm) {}

		Cache(const Cache& cc)
		{
			clone(cc);
		}
		
  //      virtual bool cacheAccess(int kind, int address)

		/*
		 * Access method
		 */
		int getBlockSize() const
		{
			return sizeBlock;
		}
		int getWaySize() const
		{
			return sizeWay;
		}
		ReplaceMethod getReplaceMethod () const
		{
			return replaceMethod;
		}
		PrefetchMethod getPrefetchMethod() const
		{
			return prefetchMethod;
		}
		WriteMethod getWriteMethod() const
		{
			return writeMethod;
		}
		BlockFetchMethod getBlockFetchMethod() const
		{
			return blockFetchMethod;
		}
		
		void setBlockSize(int bs)
		{
			sizeBlock = bs;
		}
		void setWaySize(int ws)
		{
			sizeWay = ws;
		}
		void setReplaceMethod(ReplaceMethod rm)
		{
			replaceMethod = rm;
		}
		void setPrefetchMethod(PrefetchMethod pm)
		{
			prefetchMethod = pm;
		}
		void setWriteMethod(WriteMethod wm)
		{
			writeMethod = wm;
		}
		void setBlockFetchMethod(BlockFetchMethod bfm)
		{
			blockFetchMethod = bfm;
		}

//		virtual void showConfig() const { }
	protected:
		int sizeBlock;	// Block size
		int sizeWay;	// When direct-mapped, set to 1
						// When set associativity, set to n
						// When fully associativity, set to sizeCache/sizeBlock
		ReplaceMethod replaceMethod;
//		MappingMethod mappingMethod;
		PrefetchMethod prefetchMethod;
		WriteMethod	writeMethod;
		BlockFetchMethod blockFetchMethod;
	
	private:	
		void clone(const Cache& cc)
		{
			if (this != &cc) {
				sizeBlock = cc.sizeBlock;
				sizeWay = cc.sizeWay;
				replaceMethod = cc.replaceMethod;
				prefetchMethod = cc.prefetchMethod;
				writeMethod = cc.writeMethod;
				blockFetchMethod = cc.blockFetchMethod;
			}
		}
};

extern Cache defaultCache;


#endif // CACHE_H_
