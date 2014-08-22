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
 
 
class DoubleLetter {
public:
  string ableToSolve(string S) {
    for (int i=0; i<50; i++) {
      if (S.empty())
        return "Possible";
      int n = S.size();
      for (int j=0; j<n-1; j++) {
        if (S[j]==S[j+1]) {
          S = S.substr(0,j) + S.substr(j+2,n);
          break;
        }
      }
    }
    return "Impossible";
  }
};
 
 
 
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
