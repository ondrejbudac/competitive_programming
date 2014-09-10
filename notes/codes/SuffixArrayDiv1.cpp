#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class SuffixArrayDiv1 {
public:
	int minimalCharacters(vector <int> SA) {
	    int N = SA.size();
		vector< pair<int, int> > p(N);
		for (int i=0; i<N; ++i)
            p[i] = make_pair(SA[i], i);
        sort(p.begin(), p.end());

        int res = 1;
        for (int i=1; i<N; ++i) {
            if (SA[i] == N-1) {
                res++;
                continue;
            }
            if (SA[i-1] == N-1) {
                continue;
            }
            if (p[SA[i]+1].second < p[SA[i-1]+1].second)
                res++;
        }
        return res;
	}
};
