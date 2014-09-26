#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class GUMIAndSongsDiv1 {
public:
	int maxSongs(vector <int> duration, vector <int> tone, int T) {
		vector< pair<int,int> > songs;
		int n= duration.size();
		for (int i=0; i<n; ++i) {
			songs.push_back({tone[i], duration[i]});
		}
        sort(songs.begin(),songs.end());

        int ans = 0;
        for (int i=0; i<n; ++i) {
            if (songs[i].second <= T) {
				ans = max(ans,1);
            }
			for (int j=i+1; j<n; ++j) {
				int thisT = songs[i].second + songs[j].second + (songs[j].first - songs[i].first);
				if (thisT > T)
					continue;
				vector< int > mid;
				for (int k=i+1; k<j; ++k) {
					mid.push_back(songs[k].second);
				}
				sort(mid.begin(), mid.end());
				int thisAns = 2;
				for (auto &m : mid) {
					if (thisT + m <= T) {
						thisT += m;
						thisAns++;
					}
				}
				ans = max(ans, thisAns);
			}
        }
        return ans;
	}
};
