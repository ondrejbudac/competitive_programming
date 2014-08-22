#include<vector>
#include<algorithm>

class RectangleCovering{
	public:
		int minimumNumber(int holeH, int holeW, std::vector<int> boardH, std::vector<int> boardW) {
			std::vector<int> h, w;
			int s = boardH.size();
			int max = s+1;
			for (int i=0; i<s; i++) {
				int x = boardH[i];
				int y = boardW[i];
				if (x>y) {
					int pom = x;
					x=y;
					y=pom;
				}
				if (x > holeH) {	// add y to W
					w.push_back(y);
				} else if (y > holeH) {	// add x to W
					w.push_back(x);
				}
				if (x > holeW) {	// add y to H
					h.push_back(y);
				} else if (y > holeW) {	// add x to H
					h.push_back(x);
				}
			}	
			std::sort(w.begin(), w.end(), std::greater<int>());
			std::sort(h.begin(), h.end(), std::greater<int>());
			int h1 = 0;
			int count = 0;
			for (auto &m : h) {
				h1 = h1 + m;
				count++;
				if ((h1 >= holeH) && (count < max)) {
					max = count;
				}
			}
			count = 0;
			int w1=0;
			for (auto &m : w) {
				w1 = w1 + m;
				count++;
				if ((w1 >= holeW) && (count < max)) {
					max = count;
				}
			}
			if (max == s+1) {
				return -1;
			} else {
				return max;
			}
			
		}
};
