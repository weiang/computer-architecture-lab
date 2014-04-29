/*************************************************************************
	> File Name: idcache.h
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月10日 星期四 20时23分37秒
    > Describition: 
 ************************************************************************/
#ifndef IDCACHE_H_
#define IDCACHE_H_

#include <iostream>
#include "cache.h"
#include "unicache.h"

using namespace std;

class IDCache 
{
	public:
		IDCache(const Cache& dc = defaultCache, int sic = 32, int sdc = 32) 
		: iCache(dc, sic), dCache(dc, sdc)
		{
			readINum = readIHitNum = readIMissNum = 0;
			readDNum = readDHitNum = readDMissNum = 0;
			writeNum =  writeHitNum = writeMissNum = 0;

		}

		int getICacheSize() const
		{
			return iCache.getCacheSize();
		}
		int getDCacheSize() const
		{
			return dCache.getCacheSize();
		}
		void setICacheSize(int ics)
		{
			iCache.setCacheSize(ics);
		}
		void setDCacheSize(int dcs)
		{
			dCache.setCacheSize(dcs);
		}
		
        void singleCacheAccess(int, ADDRESSBITS);
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
	private:
		UNICache iCache, dCache;
		int readINum, readIHitNum, readIMissNum;
		int readDNum, readDHitNum, readDMissNum;
		int writeNum, writeHitNum, writeMissNum;
        bool singleCacheAccessAux(int kind, ADDRESSBITS address);
				
};

#endif // IDCACHE_H_
