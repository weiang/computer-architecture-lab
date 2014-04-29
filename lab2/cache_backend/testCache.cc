/*************************************************************************
	> File Name: testCache.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月10日 星期四 15时46分44秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "cache.h"

using namespace std;

int main(void)
{
	UNICache uc = UNICache();
	uc.showConfig();
	
	cout << endl;
	Cache c2 = Cache(64, 4, RANDOM, PM_USE, WT, BFM_NOUSE);
	UNICache uc2 = UNICache(c2, 64);
	uc2.showConfig();

	Cache c3 = Cache(32, 512, FIFO, PM_NOUSE, WB, BFM_USE);
	UNICache uc3 = UNICache(c3, 16);
	uc3.showConfig();
	return 0;
}
