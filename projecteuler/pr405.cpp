// project Euler 405 - Ondrej Budac
//
// see: http://projecteuler.net/problem=405
//
// It is possible to find an explicit formula for f(n) using this recurrence:
// f(n) = 4*f(n-1) + 2*floor(2^n/3) + 4*floor(2^(n-1)/3)
//
// For even n we get
// f(n) = (6*2^(2*n) - 20*2^n +14)/15
//
// SOLUTION: 
// let M = 17^7. We have
// 2^(10^(10^18)) % M = 2^(10^(10^18) % phi(M)) % M
// this can be evaluated very fast and we get f(10^(10^18)) % M easily.   

#include<iostream>
#include<cmath>

long long powerResidual(long long a, long long b, long long n) {
	// computes a^b mod n
	long long ans = 1;
	long long mult = a % n;
	while (b > 0) {
		if (b & 1)
			ans = (ans * mult) % n;
		mult = (mult * mult) % n;
		b = b >> 1;
	}
	return ans;
}

int main() {
	long long exponent = std::pow(10,18);
	long long M = std::pow(17,7);
	long long phiM = 16*std::pow(17,6);

	long long power = powerResidual(2,powerResidual(10,exponent,phiM),M);
	long long res = (6*((power*power) % M)-20*pow+14) % M;
	while (res % 15 != 0)
		res += M;
	res /= 15;
	std::cout << res;
}




