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


class ManySquares {
public:
	int howManySquares(vector <int> sticks) {
		sort(sticks.begin(), sticks.end());
		int n = sticks.size();
		int j = 0;
		int count = 0;
		for (int i=0; i<n; ++i) {
			if (sticks[i]!=sticks[j]) {
				count = count + (i-j)/4;
				j=i;
			}
		}
		count = count + (n-j)/4;
		return count;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
