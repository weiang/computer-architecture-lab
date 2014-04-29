/*************************************************************************
	> File Name: test.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月10日 星期四 12时01分11秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <ios>
#include "unicache.h"
#include "cache.h"
#include "idcache.h"

using namespace std;


int main(int argc, char *argv[])
{
	/*
	 * Test log2(x)
	 */
//	for (int i = 1; i < 2049; i *= 2)
//		printf("log2(%d) = %d\n", i, log2(i));
//	UNICache uc = UNICache(defaultCache);

	Cache c = Cache(32, 1, FIFO, PM_NOUSE, WB, BFM_USE);
	UNICache uc = UNICache(c);
	if (argc != 2) {
		cout << "Usage:" << argv[0] << " <filename>" << endl;
		return -1;
	}

	cout << "Unified Cache: " << endl;
	uc.cacheAccess(argv[1]);
	uc.printResult();

	cout << "ID Cache: " << endl;
	IDCache idc = IDCache(c, 32, 32);
	idc.cacheAccess(argv[1]);
	idc.printResult();
	
	return 0;
}
