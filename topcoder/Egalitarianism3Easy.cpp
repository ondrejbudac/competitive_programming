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
 
 
class Egalitarianism3Easy {
public:
  int maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
    int dist[n][n];
    const int INF = 10000000;
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
        dist[i][j] = INF;
    for (int i=0; i<n; i++)
      dist[i][i] = 0;
    for (int i=0; i<a.size(); ++i) {
      dist[a[i]-1][b[i]-1] = len[i];
      dist[b[i]-1][a[i]-1] = len[i];
    }
    
      
    // Floyd
    for (int k=0; k<n; k++)
      for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    
    int res = 1;
    // bit masks
    for (int mask = 1; mask < (1<<n); ++mask) {
      bool works = true;
      int len = 0;
      int numv = 0;
      for (int i=0; i<n; ++i) {
        if (mask & (1<<i)) {
          numv++;
          for (int j=0; j<i; ++j) {
            if (mask & (1<<j)) {
              if (len == 0) {
                len = dist[i][j];
              } else {
                if (len != dist[i][j]) {
                  works = false;
                }
              }
            }
          }        
        }
      }
      if (works) {
        if (numv > res) {
          res = numv;  
        }    
      }       
    }
    return res;      
          
  }
};
 
 
 
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
