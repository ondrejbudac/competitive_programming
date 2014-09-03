int dist[N][N]; 

// INITIALIZE: 
// dist[i][j] = weight of the directed edge (i,j)
// dist[i][j] = MAXINT if there is no edge (i,j)

for (int k = 0; k < N; ++k)
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (dist[i][j] > dist[i][k] + dist[k][j])
				dist[i][j] = dist[i][k] + dist[k][j];