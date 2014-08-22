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


class ConundrumReloaded {
public:
	int minimumLiars(string answers) {
		int N = answers.size();
		bool isdet = true;
		for (int i=0; i<N; i++) {
			if (answers[i] == '?') {
				isdet = false;
				break;
			}
		}
		
		if (isdet) {
			int numL = 0;
			for (int i=0; i<N; i++) {
				if (answers[i] == 'L')
					numL++;
			}
			if (numL % 2 == 1)
				return -1;
			int res = 0;
			bool guess = false;
			for (int i=0; i<N; i++) {
				if (guess) res++;
				if (answers[i] == 'L')
					guess = !guess;
			}
			return min(res,N-res);
		}
		
		int rescomp = 0;
		for (int i=0; i<N; i++) {
			cout << (i-1) % N;
			cout <<((answers[i] != '?') && (answers[(N+i-1) % N] == '?'));
			if ((answers[i] != '?') && (answers[(N+i-1) % N] == '?')) {
				int j = i;
				while (answers[j] != '?') {
					j = (j+1) % N;
				}
				int res = 0;
				bool guess = false;
				for (int k=i; k!=j; k=(k+1)%N) {
					if (guess) res++;
					if (answers[k] == 'L')
						guess = !guess;				
				}
				if (guess) res++;
				rescomp = rescomp + min(res,((N+j-i)%N)+1-res);
			}
		}
	
		return rescomp;
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
