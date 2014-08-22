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


class BracketExpressions {
private:
	int getNum(char ch) {
		if (ch == 'X') return 0;
		else if (ch == '(') return 1; 
		else if (ch == '{') return 2;
		else if (ch == '[') return 3;
		else if (ch == ')') return -1; 
		else if (ch == '}') return -2;
		else if (ch == ']') return -3;
		return 100;
	}
	bool check(string &expr, int from, vector<int> status) {
		for (int i=from; i<expr.size(); i++) {
			int tc = getNum(expr[i]);
			if (tc>0) status.push_back(tc);
			if (tc<0) {
				if (status.empty()) return false;
				if ((status.back() == -tc) || (status.back() ==0 )) {
					status.pop_back();
				} else {
					return false;
				}
			}
			if (tc == 0) {
				status.push_back(0);
				bool t1 = check(expr, i+1, status);
				status.pop_back();
				bool t2 {false};
				if (!status.empty()) {
					status.pop_back();
					t2 = check(expr, i+1, status);
				}
				return (t1 || t2);
			}	
		}
		return status.empty();
		
	}
public:
	string ifPossible(string expression) {
		vector<int> status;
		bool ch = check(expression, 0, status);
		if (ch) return "possible"; 
		else return "impossible";
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
