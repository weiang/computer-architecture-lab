/*************************************************************************
	> File Name: main.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年05月27日 星期二 23时56分58秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include "bus.h"
#include "cache_controller.h"
#include "enum.h"

using namespace std;

int main()
{
	Bus bus;
	CacheController cc1(&bus);
	CacheController cc2(&bus);
	CacheController cc3(&bus);
	CacheController cc4(&bus);
	
	bus.addCacheController(&cc1);
	bus.addCacheController(&cc2);
	bus.addCacheController(&cc3);
	bus.addCacheController(&cc4);

	cc1.accessFromProcessor(RD, 5);
	cc2.accessFromProcessor(RD, 5);
	cc3.accessFromProcessor(RD, 5);
	cc2.accessFromProcessor(WT, 5);
	cc4.accessFromProcessor(RD, 5);
	cc2.accessFromProcessor(WT, 21);
	cc1.accessFromProcessor(WT, 23);
	cc3.accessFromProcessor(WT, 23);
	cc2.accessFromProcessor(RD, 29);
	cc2.accessFromProcessor(WT, 5);

	return 0;
}
