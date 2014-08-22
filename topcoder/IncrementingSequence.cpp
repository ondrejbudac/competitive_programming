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


class IncrementingSequence {
public:
	string canItBeDone(int k, vector <int> A) {
		int N = A.size();
		bool used[N];
		for (int i=0; i<N; i++)
			used[i] = false;
		for (int i =1; i<=N; i++) {
			for (int j=0; j<N; j++) {
				if (!used[j] &&  (A[j] <= i) && (((i-A[j]) % k) == 0)) {
					A[j] = i;
					used[j] = true;
					break;
				}
				if (j==N-1)
					return "IMPOSSIBLE";
			}
		}
		return "POSSIBLE";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
