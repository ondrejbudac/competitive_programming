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


class BuildingHeightsEasy {
public:
	int minimum(int M, vector <int> heights) {
		sort(heights.begin(), heights.end());
		int N = heights.size();
		int ls = 0;
		for (int i=0; i<M; i++) {
			ls += heights[i];
		}
		int mymin = M*heights[M-1];
		for (int j=M-1; j<N; j++) {
			int t = M*heights[j]-ls;
			if (t < mymin) {
				mymin = t;
			}
			ls = ls + heights[j+1] - heights[j-(M-1)];
		}
		return mymin;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
