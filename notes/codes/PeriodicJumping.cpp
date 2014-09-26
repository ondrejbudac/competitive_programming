#include <vector>
#include <algorithm>
using namespace std;

class PeriodicJumping {
public:
	int minimalTime(int x, vector <int> jumpLengths) {
		x = max(x,-x);
		int n = jumpLengths.size();
		long long sumAll = 0;
		int maxJump = 0;
		for (int i=0; i<n; ++i) {
			sumAll += (long long)jumpLengths[i];
			maxJump = max(jumpLengths[i], maxJump);
		}

		int res = n * (x / sumAll);
		int maxSide = (res == 0) ? x : max(x, maxJump);
		long long perim = (x / sumAll) * sumAll + x;
		int j=0;
        while (2*maxSide > perim) {
			perim += jumpLengths[j%n];
			maxSide = max(maxSide, jumpLengths[j%n]);
			res++;
			j++;
        }
        return res;
	}
};
