#include<vector>
#include<iostream>
#include<algorithm>

int main() {
	// input
	std::vector<int> a{ 2, 3, 5, 1, 6 };
	std::vector<int> b{ 1, 6, 2, 1, 3, 5, 6 };
	// we can swap the arrays to decreasy memory cost if necessary: 
	//   if (a.size() > b.size()) a.swap(b);
	int sa = a.size(), sb = b.size();

	// dynamic programming approach to LCS
	std::vector<int> L(sb, 0);
	for (int i = 1; i < sa; ++i) {
		int Lj, Ljm = L[0]; // store values of L[j] and L[j-1] from previous cycle
		for (int j = 1; j < sb; ++j) {
			Lj = L[j];
			L[j] = (a[i] == b[j]) ? Ljm + 1 : std::max(Lj, L[j]);
			Ljm = Lj;
		}
	}

	// output
	std::cout << "longest common subsequence (LCS) length: " << L[sb - 1] << "\n";
}