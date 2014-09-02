int maxFlow[N][N]; 

// INITIALIZE: 
// dist[i][j] = flow constraint over the directed edge (i,j)
// dist[i][j] = MININT if there is no edge (i,j)

for(int k = 0; k < N; ++k)
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if (maxFlow[i][j] < std::min(maxFlow[i][k], maxFlow[k][j]))
				maxFlow[i][j] = std::min(maxFlow[i][k], maxFlow[k][j]);