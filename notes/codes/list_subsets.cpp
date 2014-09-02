// print all subsets of {0, 1, ..., N-1}
int N = 10;
for (int mask = 0; mask < (1 << N); ++mask) {
	std::cout << "subset " << mask + 1 << ":";
	for (int i = 0; i < N; ++i)
		if (mask & (1 << i))
			std::cout << " " << i;
	std::cout << "\n";
}