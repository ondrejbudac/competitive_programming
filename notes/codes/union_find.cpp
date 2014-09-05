#include <vector>

std::vector<int> a,b,p;
int      rep(int x)        { return p[x] = ((p[x] == x) ? x : rep(p[x])); }
bool    same(int x, int y) { return rep(x) == rep(y);                     }
void connect(int x, int y) { p[rep(x)] = p[rep(y)];                       }

int main() {
	// input data
	int N = 10;
	a = std::vector<int>({1,2,7,1,9});
	b = std::vector<int>({2,5,3,7,3});
	
	// initialize - only singleton sets
	p.resize(N); for (int i=0; i<N; ++i) p[i] = i;
	
	// run unions
	for (int i = 0; i < a.size(); ++i) connect(a[i],b[i]);						
}
