/*************************************************************************
	> File Name: idcache.cc
	> Author: Weiang
	> Mail: weiang@mail.ustc.edu.cn 
	> Created Time: 2014年04月10日 星期四 20时26分22秒
    > Describition: 
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "unicache.h"
#include "idcache.h"

using namespace std;

bool IDCache::singleCacheAccessAux(int kind, ADDRESSBITS address)
{
	bool result;
	if (kind == 0) {	// Read data 
        if ((result = dCache.singleCacheAccess(kind, address)))
			readDHitNum ++;
		else 
			readDMissNum ++;
		readDNum ++;
	}
	else if (kind == 1) { // Write data
        if ((result = dCache.singleCacheAccess(kind, address)))
			writeHitNum ++;
		else
			writeMissNum ++;
		writeNum ++;
	}
	else {
        if ((result = iCache.singleCacheAccess(kind, address)))
			readIHitNum ++;
		else 
			readIMissNum ++;
		readINum ++;
	}
    return result;
} 

void IDCache::singleCacheAccess(int kind, ADDRESSBITS address)
{
    bool result;
    result = singleCacheAccessAux(kind, address);
    if (!result && iCache.getPrefetchMethod() == PM_USE) {
        ADDRESSBITS newAddress = address + iCache.getBlockSize();
        if (newAddress < MAXADDRESS)
            singleCacheAccessAux(kind, newAddress);
    }
}

void IDCache::cacheAccess(const string& filename)
{
	ifstream infile(filename.c_str());

	while (!infile.eof()) {
		string cmd;
		getline(infile, cmd);
		vector<string> fields;
		fields = split(cmd, string(" "));
		if (fields[0] == string(""))
			break;
		int cmdKind = atoi(fields[0].c_str());
        ADDRESSBITS address = hexStrToDec(fields[1]);
		singleCacheAccess(cmdKind, address);
	}
}

void IDCache::printResult() const
{
	int totalAccess = readINum + readDNum + writeNum; 
	int totalMiss = readIMissNum + readDMissNum + writeMissNum; 
	int totalHit = readIHitNum + readDHitNum + writeHitNum;
	cout << "Total Access:     " << totalAccess 
		 << " Total Miss:     " << totalMiss
		 << " Total Hit:     " <<  totalHit
		 << " Miss Rate: " << static_cast<double>(totalMiss) / totalAccess
		 << endl;
	cout << "Read Inst Access: " << readINum
		 << " Read Inst Miss: " << readIMissNum
		 << " Read Inst Hit: " << readIHitNum
		 << " Miss Rate: " << static_cast<double>(readIMissNum) / readINum
		 << endl;
	cout << "Read Data Access: " << readDNum 
		 << " Read Data Miss: " << readDMissNum
		 << " Read Data Hit: " << readDHitNum
		 << " Miss Rate: " << static_cast<double>(readDMissNum) / readDNum
		 << endl;
	cout << "Write Access:     " << writeNum
		 << " Write Miss:     " << writeMissNum
		 << " Write Hit:     " << writeHitNum
		 << " Miss Rate: " << static_cast<double>(writeMissNum) / writeNum
		 << endl;
}

