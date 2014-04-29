/*************************************************************************
	> File Name: unicache.h
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月10日 星期四 20时27分55秒
    > Describition: 
 ************************************************************************/
#ifndef UNICACHE_H_
#define UNICACHE_H_

#include <iostream>
#include <string>
#include "cache.h"

using namespace std;

class UNICache : public Cache
{
	public:
		UNICache(const Cache& dc = defaultCache, int cs = 64) 
			: Cache(dc), sizeCache(cs * 1024)
		{	
			readINum = readIHitNum = readIMissNum = 0;
			readDNum = readDHitNum = readDMissNum = 0;
			writeNum =  writeHitNum = writeMissNum = 0;

			sizeSet = sizeCache / sizeBlock / sizeWay;
			bitsOfOffset = log2(sizeBlock);
			bitsOfIndex = log2(sizeSet);
			bitsOfTag = 32 - bitsOfOffset - bitsOfIndex;
		
			createUNICache();
		}
		
		~UNICache() 
		{
			destroyUNICache();
		}

		int getCacheSize() const
		{
			return sizeCache;
		}

		void setCacheSize(int cs)
		{
			sizeCache = cs * 1024;
		}
	
		void showConfig() const;
        bool singleCacheAccess(int, ADDRESSBITS);
		void cacheAccess(const std::string& filename);
		void printResult() const;
	
		/* Access member functions */
		int getReadINum() const
		{
			return readINum;
		}
		int getReadIHitNum() const 
		{
			return readIHitNum;
		}
		int getReadIMissNum() const
		{
			return readIMissNum;
		}
		int getReadDNum() const
		{
			return readDNum;
		}
		int getReadDHitNum() const
		{
			return readDHitNum;
		}
		int getReadDMissNum() const
		{
			return readDMissNum;
		}
		int getWriteNum() const
		{
			return writeNum;
		}
		int getWriteHitNum() const
		{
			return writeHitNum;
		}
		int getWriteMissNum() const
		{
			return writeMissNum;
		}
        int getTotalAccessNum() const
        {
            return readINum + readDNum + writeNum;
        }
        int getTotalMissNum() const
        {
            return readIMissNum + readDMissNum + writeMissNum;
        }
        int getTotalHitNum() const
        {
            return readIHitNum + readDHitNum + writeHitNum;
        }
        double getTotalMissRate() const
        {
            if (getTotalAccessNum() == 0)
                return 0;
            return static_cast<double>(getTotalMissNum())/ getTotalAccessNum();
        }
        double getReadIMissRate() const
        {
            if (getReadINum() == 0)
                return 0;
            return static_cast<double>(getReadIMissNum()) / getReadINum();
        }
        double getReadDMissRate() const
        {
            if (getReadDNum() == 0)
                return 0;
            return static_cast<double>(getReadDMissNum()) / getReadDNum();
        }
        double getWriteMissRate() const
        {
            if (getWriteNum() == 0)
                return 0;
            return static_cast<double>(getWriteMissNum()) / getWriteNum();
        }
        int getBitsOfOffset() const
        {
            return bitsOfOffset;
        }
        PrefetchMethod getPrefetchMethod() const
        {
            return prefetchMethod;
        }
	private:
		static int cycle;
		int sizeCache;
		int sizeSet;
        ADDRESSBITS **tag;
		bool **valid;
		int **timeStamp;	// Record when a block is acce
		int bitsOfOffset;
		int bitsOfIndex;
		int bitsOfTag;
		int readINum, readIHitNum, readIMissNum;
		int readDNum, readDHitNum, readDMissNum;
		int writeNum, writeHitNum, writeMissNum;
	
	//	UNICache(const UNICache& c);
		void createUNICache();
        bool cacheRead(ADDRESSBITS, int);
		void readHit(int, int);
        void readMiss(ADDRESSBITS, int);
        bool cacheWrite(ADDRESSBITS, int);
		void writeHit(int, int);
        void writeMiss(ADDRESSBITS, int);
        void replaceBlock(ADDRESSBITS, ADDRESSBITS);
		void destroyUNICache();
        bool singleCacheAccessAux(int kind, ADDRESSBITS address);

};

#endif // UNI_CACHE_H_
