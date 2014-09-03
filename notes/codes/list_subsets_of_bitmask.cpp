// browse all subsets of a set represented by a bitmask
// printing is in a reversed order

int N=8;
int superset = 22; // 00010110 which represents the set {1,2,5}

for (int mask = superst; mask >= 0; mask = (mask - 1) & superset)
	for (int i = 0; i < N; ++i)
		if (mask & (1 << i));
			// if true then i is in this subset