#include<vector>
#include<iostream>

int main() {
	// input
	std::vector<int> a{ 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	int sa = a.size();
	std::vector<int> p(sa, -1), m(sa + 1, 0);

	int L = 0;
	for (int i = 0; i < sa; ++i) {
		// binary search
		int lo = 1, hi = L;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (a[m[mid]] < a[i])
				lo = mid + 1;
			else
				hi = mid - 1;
		}

		//update
		p[i] = m[lo - 1];
		if (lo > L) {
			m[lo] = i;
			L = lo;
		}
		else if (a[i] < a[m[lo]]) {
			m[lo] = i;
		}
	}

	// reconstruction
	std::vector<int> s(L);
	int k = m[L];
	for (int i = L - 1; i >= 0; --i) {
		s[i] = a[k];
		k = p[k];
	}

	// output
	std::cout << "Longest increasing subsequence (LIS) length: " << L << "\n";
	std::cout << "LIS: " << L << "\n";
	for (auto &m : s) std::cout << m << " ";
	std::cout << "\n";
}