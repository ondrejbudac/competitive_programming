// project Euler 402 - Ondrej Budac
//
// It can be shown that the polynomial n^4 + 4*n^3 + 2*n^2 + 5*n is a multiple of 6 for every integer n. 
// It can also be shown that 6 is the largest integer satisfying this property.
// Define M(a, b, c) as the maximum m such that n^4 + a*n^3 + b*n^2 + c*n is a multiple of m for all integers n. 
// For example, M(4, 2, 5) = 6.
// Also, define S(N) as the sum of M(a, b, c) for all 0 < a, b, c <= N.
// We can verify that S(10) = 1972 and S(10000) = 2024258331114.
// Let F(k) be the Fibonacci sequence:
// Find the last 9 digits of sum(S(F(k))) for 2 <= k <= 1234567890123.

// SOLUTION:
// One can find out that S(n) is a polynomial of order 3 in n, where the coefficients
// depend on n % 24. Then, one can do fancy tricks to get a very good speed.
// I took it by brute-force and got the solution in a few hours.

#include<iostream>
#include<cmath>

int gcd(int a, int b) {
	a = std::abs(a);
	b = std::abs(b);
	while (a!=0) {
		int r = b % a;
		b = a;
		a = r;	
	}
	return b;
}

int maxDiv(int a, int b, int c) {
	return gcd(gcd(gcd(1+a+b+c, 16+8*a+4*b+2*c), 81+27*a+9*b+3*c), 256+64*a+16*b+4*c);
}

int main() {
	// precompute M(a,b,c)
	constexpr int per = 24;
	int div[per+1][per+1][per+1];
	for (int i=0; i <= per; ++i) 
		for (int j=0; j <= per; ++j) 
			for (int k=0; k <= per; ++k) 
				 div[i][j][k] = maxDiv(i,j,k);			

	// precompute coefficients
	long long s2[per+1], s1[per+1], s0[per+1];
	long long s3=0;
	for (int i=0; i<=per; ++i)
		s2[i] = s1[i] = s0[i] = 0;
	for (int z=0; z<per+1; ++z) {
		for (int i=1; i <= per; ++i) {
			for (int j=1; j <= per; ++j) { 
				for (int k=1; k <= per; ++k) {
					if (z==0) s3 += div[i][j][k];
					int cnt = (i <= z) + (j <= z) + (k <= z);
					if (cnt == 3) {
						s0[z] += div[i][j][k];
						s1[z] += 3*div[i][j][k];
						s2[z] += 3*div[i][j][k];
					}
					if (cnt == 2) {
						s1[z] += div[i][j][k];
						s2[z] += 2*div[i][j][k];
					}
					if (cnt == 1) {
						s2[z] += div[i][j][k];
					}
				}
			}
		}
	}

	// S(N) = s0[N % per] + (N/per)*(s1[N % per] + (N/per)*(s2[N % per] + (N/per)*s3));
	long long indmax = 1234567890123;
	long long M = 1e9;
	long long perM = per * M;
	long long f = 1, fprev = 1;
	long long ans = 0;
	for (long long i = 2; i <= indmax; ++i) {		
		long long mult = f / per;
		int res = f % per;
		long long toadd = (s2[res] + mult * s3) % M;
		toadd = (s1[res] + mult * toadd) % M;
		toadd = (s0[res] + mult * toadd) % M;
		ans = (ans + toadd) % M;
		
		if (i % 100000000==0) { // see progress
			std::cout << ((double)i/(double)indmax)*100 << "%" << "\n";		
		}

		long long fnew = (f + fprev) % perM;
		fprev = f;
		f = fnew;
	}
	std::cout << ans << "\n";
}
