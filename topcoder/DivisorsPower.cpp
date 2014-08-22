#include<vector>
#include <math.h>
#include <cmath>

class DivisorsPower{
	private:
		std::vector<int> getexp(long long s) {
			std::vector<int> m;
			long long divisor = 2;
			while ((divisor*divisor) <= s) {
				if (s % divisor == 0) {
					int count = 0;
					while (s % divisor == 0) {
						count++;
						s = s/divisor;
					}
					m.push_back(2*count);
				}
				divisor++;
			}
			if (s>1) {
			m.push_back(2);
			}
			return m;
		}
	public:
		long long findArgument(long long n) {
			long long s = round(sqrt(n));
			if ((s*s) != n) return -1;
			std::vector<int> e = getexp(s);
			int maxexp = 0;
			for (auto m : e) {
				if (m > maxexp) {
					maxexp = m;
				}
			}
			for (int i=maxexp; i>0; --i) {
				bool good = true;
				for (auto &m : e) {
					if (m % i != 0) {
						good = false;
					}
				}
				if (good) {
					int prod = 1;
					for (auto &m : e) {
						prod = prod * (1 + (m/i));
					}
					if (prod == i) {
						long long res = round(std::pow(n, 1.0/i));
						return res;
					}
				}
			}
			return -1;
		}
		
};
