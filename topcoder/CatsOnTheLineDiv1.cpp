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

class CatsOnTheLineDiv1 {
public:
	int getNumber(vector <int> position, vector <int> count, int time) {
		int n = position.size();
		
		// convert to vector of pairs
		vector< pair<int, int> > cats(n);
		for (int i=0; i<n; ++i)
			cats[i] = make_pair(position[i], count[i]);
			
		// sort based on position
		sort(cats.begin(), cats.end());
		
		// greedy placing
		int lastCat = cats[0].first-time-1;
		int lastBad = lastCat;
		int badPos = 0;
		for (int i=0; i<n; ++i) {
			if (cats[i].first - time > lastBad) { 
				int minpos = max(lastCat+1, cats[i].first-time);
				int lastpos = cats[i].first+time;
				int num = lastpos-minpos+1;
				if (num >= cats[i].second) {
					lastCat = minpos + cats[i].second - 1;
				} else {
					badPos++;
					lastCat = lastpos;
					lastBad = lastpos;
				}
			} 			
		}
		return badPos;		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
