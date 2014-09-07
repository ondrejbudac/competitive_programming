#include<vector>
#include<iostream>
#include<algorithm>

int main() {
	// input
	std::vector<int> a{ 2, 3, 5, 1, 6 };
	std::vector<int> b{ 1, 6, 2, 1, 3, 5, 6 };
	int sa = a.size(), sb = b.size();

	// dynamic programming approach to LCS
	std::vector< std::vector<int> > L(sa, std::vector<int>(sb, 0));
	for (int i = 1; i < sa; ++i)
		for (int j = 1; j < sb; ++j)
			L[i][j] = (a[i] == b[j]) ? L[i - 1][j - 1] + 1 : std::max(L[i - 1][j], L[i][j - 1])

	// reconstruct one of the possible LCS, in reversed order!
	int i = sa - 1, j = sb - 1;
	std::vector<int> lcs;
	while (i>0 && j>0 && L[i][j] > 0) {
		if (a[i] == b[j]) {
			lcs.push_back(a[i]);
			i--;
			j--;
		}
		else if (L[i - 1][j] == L[i][j])
			i--;
		else
			j--;
	}

	// output
	std::cout << "longest common subsequence (LCS) length: " << L[sa - 1][sb - 1] << "\n";
	std::cout << "reconstructed LCS: ";
	for (auto it = lcs.rbegin(); it != lcs.rend(); ++it)
		std::cout << *it << " ";
	std::cout << "\n";
}