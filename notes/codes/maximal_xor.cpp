int highestBit(__int64 a) {
	int res = 0;
	while (a >>= 1) 
		res++;
	return res;
}

__int64 maxXor(std::vector<__int64> &v) {
	int N = v.size();
	std::vector<__int64> elim, combination, original;
	std::vector<int> bit;
	for (auto &orig : v) {
		__int64 m = orig, comb = 0;
		for (int i = 0; i < elim.size(); ++i) {
			if (m & (1LL << bit[i])) {
				m ^= elim[i];
				comb ^= combination[i];
			}
		}
		if (m) {
			combination.push_back(comb ^ (1LL << elim.size()));
			original.push_back(orig);
			bit.push_back(highestBit(m));
			for (int i = 0; i < elim.size(); ++i) {
				if (elim[i] & (1LL << bit.back())) {
					elim[i] ^= m;
					combination[i] ^= combination.back();
				}
			}
			elim.push_back(m);
		}
	}

	__int64 maximum = std::accumulate(elim.begin(), elim.end(), 0, std::bit_xor<__int64>());
	__int64 maxBitmask = std::accumulate(combination.begin(), combination.end(), 0, std::bit_xor<__int64>());

	std::cout << "Maximal xor value: " << maximum << "\n";
	std::cout << "A possible maximizing subset: ";
	for (int i = 0; i < original.size(); ++i)
		if (maxBitmask & (1LL << i))
			std::cout << original[i] << " ";

	return maximum;
}