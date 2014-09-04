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


class Egalitarianism3 {
public:
	int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
		// Floyd-Warshall with path
		int dist[n][n];
		int next[n][n];
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				dist[i][j] = 100000000;
				next[i][j] = -1;
			}
			dist[i][i] = 0;
		}
		for (int i=0; i<n-1; ++i) {
			dist[a[i]-1][b[i]-1] = dist[b[i]-1][a[i]-1] = len[i];
			next[a[i]-1][b[i]-1] = b[i]-1;
			next[b[i]-1][a[i]-1] = a[i]-1;
		}
		
		for (int k=0; k<n; ++k) 
		for (int i=0; i<n; ++i) 
		for (int j=0; j<n; ++j)
		if (dist[i][k]+dist[k][j] < dist[i][j]) {
			dist[i][j] = dist[i][k]+dist[k][j];
			next[i][j] = next[i][k];
		} 
		
		// for every node, check all nodes
		int res = min(2,n);
		for (int i=0; i<n; ++i) {
			set< pair<int, int> > p;
			for (int j=0; j<n; ++j) {
				if (j==i) continue;
				p.insert(make_pair(dist[i][j],next[i][j]));
			}
			int d=0, num = 0;
			for (auto& m : p)
				if (m.first == d) {
					num++;
					res = max(res,num);
				} else {
					d = m.first;
					num = 1;
				}
		}
		return res;		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
