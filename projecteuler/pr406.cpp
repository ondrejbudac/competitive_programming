// project Euler 406 - Ondrej Budac
//
// We are trying to find a hidden number selected from the set of integers {1, 2, ..., n} by asking questions. 
// Each number (question) we ask, we get one of three possible answers:
// - "Your guess is lower than the hidden number" (and you incur a cost of a), or
// - "Your guess is higher than the hidden number" (and you incur a cost of b), or
// - "Yes, that's it!" (and the game ends).
//
// Given the value of n, a, and b, an optimal strategy minimizes the total cost for the worst possible case.
// For example, if n = 5, a = 2, and b = 3, then we may begin by asking "2" as our first question.
// 
// Let C(n, a, b) be the worst-case cost achieved by an optimal strategy for the given values of n, a, and b.
// Let F(k) be the Fibonacci numbers: F(k) = F(k-1) + F(k-2) with base cases F(1) = F(2) = 1.
// Find sum_{k=1..30} C(10^12, sqrt(k), sqrt(F(k))), and give your answer rounded to 8 decimal places behind the decimal point.
//
// SOLUTION:
// For a given (a, b), one can use dynamic programming to get the worst-case cost.
// trying smaller samples, it is obvious that there are large intervals of n such that C(n,a,b) is constant
// One can than simplify the storage in the dynamic programming by storing intervals
// and also it increases the speed.

#include<iostream>
#include<cmath>
#include<unordered_map>
#include<algorithm>
#include<vector>

double getWorstCost(long long nmax, double a, double b) {
	if (a > b) 
		std::swap(a,b);

	std::vector<int> x, y;
	std::vector<long long> s, e;

	// initialization
	x.push_back(0);
	y.push_back(0);
	s.push_back(0);
	e.push_back(1);

	// building the values
	long long n = e.back();
	while (n < nmax) {
		n++;
		int num = x.size();

		int newx = x.back() + 1;
		int newy = y.back();
		double newval = a*newx + b*newy;

		int j = num - 1;
		int opti = -1;
		int optj = -1;
		for (int i = 0; i < num; ++i) {
			while ((e[i] + s[j] + 1 > n) && (j > 0)) j--;
			if ((s[i] + s[j] + 1 <= n) && (e[i] + e[j] + 1 >= n)) {
				// check if the coordinates are new
				int canditx1 = x[i] + 1;
				int candity1 = y[i];
				double canditval1 = a*canditx1 + b*candity1;
				int canditx2 = x[j];
				int candity2 = y[j] + 1;
				double canditval2 = a*canditx2 + b*candity2;

				if ((!((canditx1 == newx) && (candity1 == newy))) && (canditval1 < newval)) {
					if ((!((canditx2 == newx) && (candity2 == newy))) && (canditval2 < newval)) {
						opti = i;
						optj = j;
						if (canditval1 > canditval2) {
							newx = canditx1;
							newy = candity1;
							newval = canditval1;
						}
						else {
							newx = canditx2;
							newy = candity2;
							newval = canditval2;
						}
					}
				}
			}
		}

		long long newn = n;
		if (opti >= 0) {
			newn = e[opti] + e[optj] + 1;
		}
		if ((newval == a*x.back() + b*y.back()) || ((newx == x.back()) && (newy == y.back()))) {
			e[num - 1] = newn;
		}
		else {
			e.push_back(newn);
			s.push_back(n);
			x.push_back(newx);
			y.push_back(newy);
		}
		n = e.back();
	}
	return a*x.back() + b*y.back();
}

int main() {
	long long nmax = 1e12;
	long long f = 1;
	long long fprev = 0;
	double answer = 0;
	for (int i = 1; i <= 30; ++i) {
		std::cout << "processing fib(" << i << ") = " << f << "\n";
		answer += getWorstCost(nmax, std::sqrt(i), std::sqrt(f));
		long long fnew = f + fprev;
		fprev = f;
		f = fnew;
	}
	std::cout.precision(15);
	std::cout << "Answer = " << answer << "\n";
}




