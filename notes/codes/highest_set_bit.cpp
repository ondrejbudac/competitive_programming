int highestBit(__int64 bitmask) {
	int res = 0;
	while (bitmask >>= 1) 
		res++;
	return res;
}