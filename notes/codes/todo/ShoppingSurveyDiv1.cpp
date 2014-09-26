#include <vector>
#include <algorithm>
using namespace std;

class ShoppingSurveyDiv1 {
public:
	int minValue(int N, int K, vector <int> s) {
        for (int i=0; i<N; ++i) {
			// test if i can be an answer
			int c = 0;
			for (auto &m : s) {
				c += max(0, m-i);
			}
			if (c <= (K-1)*(N-i)) {
				return i;
			}
        }
        return N;
	}
};
