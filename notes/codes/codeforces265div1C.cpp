#include<stdio.h>
#include<vector>
#include<iostream>
#include<string>
using namespace std;

const int N = 100000;
char foo[N], dig[N];
vector<string> to;
string s;
long long mod[10];
long long len[10];

const long long MOD = 1000000007;
const long long PHI = 1000000006;

long long myPower(long long e) {
	e %= PHI;
	long long res = 1;
	long long p = 10;
	while (e) {
		if (e % 2 == 1) {
			res = (res * p) % MOD;
		}
		p = (p * p) % MOD;
		e = e >> 1;
	}
	return res;
}

void update(int ind, string & str) {
	long long newres = 0, newlen = 0;
	for (int j = str.size() - 1; j >= 0; --j) {
		int procDig = str[j] - '0';
		newres = (newres + mod[procDig] * myPower(newlen)) % MOD;
		newlen = (newlen + len[procDig]) % PHI;
	}
	mod[ind] = newres;
	len[ind] = newlen;
}

int main() {
	gets(foo);
	s = foo;
	int n = s.size();
	int m;
	scanf("%d\n", &m);
	to.resize(m);
	for (int i = 0; i < m; ++i) {
		gets(foo);
		dig[i] = foo[0];
		to[i] = foo;
		to[i] = to[i].substr(3);
	}

	for (int i = 0; i < 10; ++i) {
		mod[i] = i;
		len[i] = 1;
	}
	for (int i = m - 1; i >= 0; --i)
		update(dig[i] - '0', to[i]);

	update(0, s);
	cout << mod[0];
	return 0;
}