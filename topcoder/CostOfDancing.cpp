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


class CostOfDancing {
public:
	int minimum(int K, vector <int> danceCost) {
		sort(danceCost.begin(), danceCost.end());
		int cost = 0;
		for (int i=0; i< K; i++) {
			cost += danceCost[i];
		}
		return cost;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
