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


class PotentialArithmeticSequence {

private:
	bool isGoodSequence(vector <int> d, int s, int e, int step) {
		if (s+step > e) {
			if (d[s] >= 0) return true;
			else return false;
		} //&& (d[s] >= 0)) { return true; }
		if (d[s] == 0) {
			bool good = true;
			for (int i=s; i<=e; i+=2*step)
				if (d[i] != 0) good = false;
			if (!good) {return false; }
			if (s+step <= e) {
				for (int i=s+step; i<=e; i+=2*step)
					d[i] = d[i]-1;
				good = good && isGoodSequence(d,s+step,e,2*step);
			}
			return good;
		} else if (d[s+step] == 0) {
			bool good = true;
			for (int i=s+step; i<=e; i+=2*step)
				if (d[i] != 0) good = false;
			if (!good) {return false; }
			for (int i=s; i<=e; i+=2*step)
				d[i] = d[i]-1;
			good = good && isGoodSequence(d,s,e,2*step);
			return good;
		} else {return false; }
	}

public:
	int numberOfSubsequences(vector <int> d) {
		int count = 0;
		int n=d.size();
		for (int i=0; i<n; ++i)
			for (int j=i; j<n; ++j) {
				// test subsequence i to j
				if (isGoodSequence(d,i,j,1)) {
				count++;
				//cout << i << " " << j << " " << "\n"; 
				}								
			}
		return count;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
