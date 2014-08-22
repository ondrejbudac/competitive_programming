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


class HappyLetterDiv2 {
public:
	char getHappyLetter(string letters) {
		int n = letters.size();
		for (char x='a'; x<='z'; x++) {
			int count=0;
			for (char y : letters)
				if (y==x)
					count++;
					
			if (2*count>n)
				return x;
		}
		return '.';
		
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
