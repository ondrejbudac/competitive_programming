#include <vector>

std::vector<int> a,b,p,r;
int      rep(int x)        { return p[x] = ((p[x] == x) ? x : rep(p[x])); }
bool    same(int x, int y) { return rep(x) == rep(y);                     }
void connect(int x, int y) { 
	if (r[rep(x)] <  r[rep(y)]) p[rep(x)] = p[rep(y)]; 
	else 												p[rep(y)] = p[rep(x)]; 
	if (r[rep(x)] == r[rep(y)]) r[rep(x)]++;           
}

int main() {
	// input data
	int N = 10;												
	a = std::vector<int>({1,2,7,1,9});
	b = std::vector<int>({2,5,3,7,3});
	
	// initialize - only singleton sets
	p.resize(N); r.resize(N);
	for (int i=0; i<N; ++i) { p[i] = i; r[i] = 0; }
	
	// run unions
	for (int i = 0; i < a.size(); ++i) connect(a[i],b[i]);						
}
