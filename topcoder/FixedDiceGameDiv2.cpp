#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class FixedDiceGameDiv2 {
public:
	double getExpectation(int a, int b) {
		long pos = 0;
		double res = 0;
		for (int i=2; i <= a; i++) {
			if (i-1 < b) {
				res += i*(i-1);
				pos += i-1;
			} else {
				res = res + i*b;
				pos += b;
			}
		}
		return res/pos;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
