// browse all subsets of {0, 1, ..., N-1}

int N = 10;

for (int mask = 0; mask < (1 << N); ++mask) 
	for (int i = 0; i < N; ++i)
		if (mask & (1 << i))  
			// if true then i is in this subset