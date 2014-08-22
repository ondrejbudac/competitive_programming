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

// I first read the solution in the Topcoder editorial
// now I try to implement it withou looking back

class NegativeGraphDiv2 {
public:
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
		// First do the Floyd-Warshal
		
		// initialize the distance Field
		const int INF = 1000000000;
		int dist[N][N];
		for (int i=0; i<N; ++i) 
			for (int j=0; j<N; ++j)
				dist[i][j] = INF;
		for (int i=0; i<N; ++i) 
			dist[i][i] = 0;
		
		for (int i=0; i<weight.size(); i++) {
			int ss = s[i]-1, tt = t[i]-1, ww = weight[i];
			dist[ss][tt] = min(dist[ss][tt], ww);
		}
		
		// Floyd
		for (int k=0; k<N; ++k) 
			for (int i=0; i<N; ++i)
				for (int j=0; j<N; ++j) 
					dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
		
		// xdist[c][k] gives the shortest distance from k to N with at most c tricks
		int xdist[charges+1][N];
		for (int i=0; i<N; i++)
			xdist[0][i] = dist[i][N-1];
			
		for (int c=1; c<= charges; c++) {
			for (int i=0; i<N; i++) {
				xdist[c][i] = xdist[c-1][i];
				for (int j=0; j<weight.size(); j++) {
					int ss = s[j]-1, tt = t[j]-1, ww = weight[j];
					xdist[c][i] = min(xdist[c][i], dist[i][ss] - ww + xdist[c-1][tt]);				
				}
			}
		}
		return xdist[charges][0];		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
