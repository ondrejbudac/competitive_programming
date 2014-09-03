// project Euler 443 - Ondrej Budac
//
// Let g(n) be a sequence defined as follows:
// g(4) = 13,
// g(n) = g(n-1) + gcd(n, g(n-1)) for n > 4.
// Find g(10^15).
//
// One can notice that g(n) is arithmetic with difference 1 for large intervals of n.
// knowing g(n) for some n, one can easily find the largest k such that g(n+k) = g(n)+k,
// then compute g(n+k+1) by definition and repeat.

#include<iostream>
#include<vector>

long long gcd(long long a, long long b) {
	// assume they are nonnegative
	while (a > 0) {
		long long r = b % a;
		b = a;
		a = r;
	}
	return b;
}

std::vector<long long> getFactors(long long n) {
	std::vector<long long> a;
	long long p = 2;
	while ((n > 1) && (p*p <= n)) {
		if (n % p == 0) {
			a.push_back(p);
			while (n % p == 0)
				n /= p;
		}
		p = p + 1;
	}
	if (n > 1)
		a.push_back(n);
	return a;
}

int main() {
	long long N = 1e15;

	long long val = 13;
	long long n = 4;
	while (true) {
		std::cout << n << " " << val << "primes: ";
		std::vector<long long> factors = getFactors(val - n - 1);
		long long k = 9223372036854775807; // max LONG
		for (auto &p : factors) {
			std::cout << p << " ";
			if ((n + 1) % p == 0)
				k = 0;
			else {
				long long newk = p - ((n + 1) % p);
				if (newk < k) {
					k = newk;
				}
			}
		}

		std::cout << k << "\n";

		if (n + k >= N) {
			std::cout << val + N - n;
			break;
		}
		else {
			n = n + k + 1;
			val = val + k + gcd(n, val + k);
		}
	}

	int aaaa;
	std::cin >> aaaa;
}
