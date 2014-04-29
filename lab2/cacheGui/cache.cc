#include <cstdlib>
#include <iostream>
#include "cache.h"

using namespace std;

int log2(int x)
{
	int k = 0;
	while (x > 1) {
		k ++;
		x /= 2;
	}
	return k;
}

int iExp(int x)
{
    int result = 1;
    for (int i = 0; i != x; i ++)
        result *= 2;
    return result;
}

vector<string> split(string str, string pattern)
{
	string::size_type pos;
	vector<string> result;
	str += pattern;
    unsigned int size = str.size();

    for (unsigned int i = 0; i != size; i ++) {
		pos = str.find(pattern, i);
		if (pos < size) {
			string s = str.substr(i, pos-i);
			result.push_back(s);
			i = pos + pattern.size() - 1;
		}
	}
	return result;
}

int hexStrToDec(const string& str)
{
	int result = 0;
    for (unsigned int i = 0; i != str.size(); i ++) {
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 16 + (str[i] - '0');
		else if (str[i] >= 'a' && str[i] <= 'f')
			result = result * 16 + (str[i] - 'a' + 10);
		else if (str[i] >= 'A' && str[i] <= 'F')
			result = result * 16 + (str[i] - 'A' + 10);
		else {
		}
	}
	return result;
}

Cache defaultCache = Cache(
	32, 1,
	LRU,
	PM_NOUSE,
	WB,
	BFM_USE);

