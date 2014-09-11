#include <iostream>
using namespace std;

long long s[8][3], t[8][3], dist[8][8];
const int perm[6][3] {{0,1,2},{0,2,1},{1,0,2},{1,2,0},{2,0,1},{2,1,0}};
const int pos = 6*6*6*6*6*6*6;

int main()
{
    for (int i=0; i<8; ++i)
        scanf("%I64d %I64d %I64d", &s[i][0], &s[i][1], &s[i][2]);
	for (int i=0; i<3; ++i)
		t[0][i] = s[0][i];
    for (int i=0; i<pos; ++i)
    {
		// 1. construct cube
        int m = i;
        for (int j=1; j<8; ++j)
        {
			for (int l=0; l<3; ++l)
				t[j][l] = s[j][perm[m%6][l]];
			m = m/6;
        }

		// 2. check cube
		// 2.1. get all distances
        long long minimum = (long long)1e18;
        for (int k=0; k<8; ++k)
			for (int l=k+1; l<8; ++l) {
				dist[k][l] = 0;
				for (int z=0; z<3 ;++z)
					dist[k][l] += (t[k][z]-t[l][z])*(t[k][z]-t[l][z]);
				if (dist[k][l] < minimum)
					minimum = dist[k][l];
		}

		// 2.2 check distance counts
		bool good = true;
		int a[3] {0,0,0};
		for(int k=0; k<8; ++k) {
			for (int l=k+1; l<8; ++l) {
                if (dist[k][l] == minimum) a[0]++;
                else if (dist[k][l] == 2*minimum) a[1]++;
                else if (dist[k][l] == 3*minimum) a[2]++;
                else { good = false; break; }
			}
			if (!good) break;
		}
		if (!good) continue;
		if (!(a[0] == 12 && a[1] == 12 && a[2] == 4)) continue;

		// 3. found a cube
		cout << "YES\n";
		for(int k=0; k<8; ++k) {
			for (int l=0; l<3; ++l) {
				cout << t[k][l] << " ";
			}
			cout << "\n";
		}
		return 0;
    }
    cout << "NO";
    return 0;
}
