#include <vector>
#include <algorithm>
using namespace std;

class CatsOnTheLineDiv1 {
public:
	int getNumber(vector <int> position, vector <int> count, int time) {
		int n = position.size();
		vector< pair<int, int> > cats(n);
		for (int i=0; i<n; ++i)
			cats[i] = make_pair(position[i], count[i]);
		sort(cats.begin(), cats.end());
		int lastCat = cats[0].first-time-1;
		int lastBad = lastCat;
		int badCount = 0;
		for (int i=0; i<n; ++i) {
			if (cats[i].first - time > lastBad) { 
				int minpos = max(lastCat+1, cats[i].first-time);
				int lastpos = cats[i].first+time;
				int num = lastpos-minpos+1;
				if (num >= cats[i].second) {
					lastCat = minpos + cats[i].second - 1;
				} else {
					badCount++;
					lastCat = lastpos;
					lastBad = lastpos;
				}
			} 			
		}
		return badCount;		
	}
};
