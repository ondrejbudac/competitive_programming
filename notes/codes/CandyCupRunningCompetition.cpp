#include <vector>
#include <iostream>

using namespace std;


class CandyCupRunningCompetition {
private:
    long long mod = 1000000007;
    vector<int> p;

    // union find procedures:
    int rep(int x) {
        return p[x] = (p[x] == x) ? x : rep(p[x]);
    }
    bool same(int x, int y) {
        return rep(x) == rep(y);
    }
    void connect(int x, int y) {
        p[rep(x)] = rep(y);
    }

public:
	int findMaximum(int N, vector <int> A, vector <int> B) {
		int M = A.size();
		long long res = 0;

		if (M == 0)
            return res;

		// powers of 3
		vector<long long> powers(M);
		powers[0] = 1;
		for (int i=1; i<M; ++i) {
            powers[i] = (3*powers[i-1]) % mod;
		}

        // initialization of sets
        p = vector<int>(N);
        for (int i=0; i<N; ++i)
            p[i] = i;

        // greedy adding of edges
        for (int i=M-1; i>=0; --i) {
            if ((same(0,A[i]) && same(N-1,B[i])) || (same(N-1,A[i]) && same(0,B[i]))) {
                res = (res + powers[i]) % mod;
            } else {
                connect(A[i], B[i]);
            }
        }
        return res;
	}
};
