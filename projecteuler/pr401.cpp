// project Euler 401 - Ondrej Budac
//
//The divisors of 6 are 1,2,3 and 6.
//The sum of the squares of these numbers is 1+4+9+36=50.
//
//Let sigma2(n) represent the sum of the squares of the divisors of n. Thus sigma2(6)=50.
//
//Let SIGMA2 represent the summatory function of sigma2, that is SIGMA2(n)=sum of sigma2(i) for i=1 to n.
//The first 6 values of SIGMA2 are: 1,6,16,37,63 and 113.
//Find SIGMA2(10^15) modulo 10^9.

// SOLUTION:
// We use that 
// SIGMA2(n) = sum_{k <= n} k^2 * (n // k)
// there is approximately O(sqrt(n)) different values of (n // k) when 
// k ranges 1..n. For each such value we compute its contribution to the sum in O(1)
// which makes it an O(1) algorithm
#include<iostream>

long long sumSquares(long long k, long long M) {
	// returns the value 1^2+2^2+...+k^2 mod M
	// it uses 1^2+2^2+...+k^2 = k*(k+1)*(2*k+1)/6
	// and avoids overflow by carefully dividing and taking modulus.
 
	long long a1 = k;
	long long a2 = k+1;
	long long a3 = 2*k+1;
	if (a1 % 2 == 0) a1 /= 2;
	else a2 /= 2;
	if (a1 % 3 == 0) a1 /= 3;
	else if (a2 % 3 == 0) a2 /= 3;
	else a3 /= 3;
	return ((((a1 % M) * (a2 % M)) % M) * (a3 % M)) % M;
}

long long Sigma(const long long N, const long long M) {
	// Evaluation of SIGMA2(N) modulo M
	long long kstart = 1;
	long long res = 0;
	
	while (k <= N) {
		long long mult = N/kstart;
		long long kend = N/mult;
		long long ss = sumSquares(kend, M) - sumSquares((kstart-1), M);
		ss = (ss + M) % M;

		res += ((mult % M) * ss) % M;
		res %= M;			
		kstart = kend + 1; 	
	}
	return res;
}

int main() {
	const long long N = 1e15, M = 1e9;
	std::cout << Sigma(N,M) << "\n";
}
