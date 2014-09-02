int dist[N][N]; 
int next[N][N];

// INITIALIZE: 
// dist[i][j] = weight of the directed edge (i,j)
// dist[i][j] = MAXINT if there is no edge (i,j)
// next[i][j] = j if the edge (i,j) exists 
// next[i][j] = -1 if there is no edge (i,j)

for(int k = 0; k < N; ++k)
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if (dist[i][j] > dist[i][k] + dist[k][j]) {
				dist[i][j] = dist[i][k] + dist[k][j];
				next[i][j] = next[i][k];
			}

// path reconstruction given 0 <= i, j < N
int k=i;
while (k != j) {
	std::cout << k << " ";
	k = next[k][j];
}
std::cout << j << "\n";