#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class UniformBoard {
public:
	int getBoard(vector <string> board, int K) {
		int n = board.size();

		// precompute cumulative counts
        vector< vector<int> > cumA(n+1, vector<int>(n+1,0)), \
			cumP(n+1, vector<int>(n+1,0)), cumF(n+1, vector<int>(n+1,0));
        for(int i=1; i<=n; ++i) {
			for (int j=1; j<=n; ++j) {
                cumA[i][j] = cumA[i-1][j]+cumA[i][j-1]-cumA[i-1][j-1];
                cumP[i][j] = cumP[i-1][j]+cumP[i][j-1]-cumP[i-1][j-1];
                cumF[i][j] = cumF[i-1][j]+cumF[i][j-1]-cumF[i-1][j-1];
                if (board[i-1][j-1] == 'A') {
					cumA[i][j]++;
                }
                if (board[i-1][j-1] == 'P') {
					cumP[i][j]++;
                }
                if (board[i-1][j-1] == '.') {
					cumF[i][j]++;
                }

			}
        }
        int numA{cumA[n][n]}, numP{cumP[n][n]}, numF{cumF[n][n]};

		// border case 1
		if (numA ==0) {
			return 0;
		}

		// real case (special attention if (numF == 0))
		int maxRec = 0;
		// test all possible rectangles
		for (int i1=0; i1<n; ++i1) {
			for (int i2=i1+1; i2<=n; ++i2) {
				for (int j1=0; j1<n; ++j1) {
					for (int j2=j1+1; j2<=n; ++j2) {
                        int recSize = (i2-i1)*(j2-j1);
                        if (recSize > numA) {
							continue;
                        }
                        int inApple = cumA[i2][j2] - cumA[i1][j2] - cumA[i2][j1] + cumA[i1][j1];
                        if (numF == 0) {
							if (inApple == recSize) {
								maxRec = max(maxRec, recSize);
							}
							continue;
                        }
                        int inPear = cumP[i2][j2] - cumP[i1][j2] - cumP[i2][j1] + cumP[i1][j1];
                        int inFree = recSize - inApple - inPear;
                        int numSteps = 2*inPear + inFree;
                        if (numSteps <= K) {
							maxRec = max(maxRec, recSize);
                        }
					}
				}
			}
		}
		return maxRec;
	}
};
