#include <vector>
#include <iostream>
using namespace std;

// DFS
int ti;
vector<bool> visited;
vector<int> in, out;
vector< vector<int> >graph;

void dfs(int x) {
    if (!visited[x]) {
		visited[x] = true;
        in[x] = ++ti;
        for (auto &m: graph[x])
			dfs(m);
        out[x] = ++ti;
    }
}

// UF
vector<int> uf;
int ufFind(int x) {
	return uf[x] = (uf[x] == x) ? x : ufFind(uf[x]);
}
void ufConnect(int x, int y) {
    uf[ufFind(x)] = ufFind(y);
}

int main() {
	int n,m;
	cin >> n >> m;

	vector< pair<int, int> > con; // connections
	vector< pair<int, int> > relpac; // + related packages after this connection (from to)
	vector< pair< int, vector<int> > > pac; // + related query numbers
	vector<int> que; // queries (employee, package)

	// read input
	con.push_back({0,0}); // dummy connection (packages can be send before)
	relpac.push_back({0,0});
    for (int i=0; i<m; ++i) {
        int t; cin >> t;
        if (t == 1) {
        	int a, b; cin >> a >> b; // the boss of a is b
			con.push_back({a-1,b-1});
			int sz = pac.size();
			relpac.push_back({sz,sz});
		} else if (t == 2) {
            int a; cin >> a; // a = employee
            pac.push_back({a-1,{}});
            relpac.back().second++;
		} else if (t == 3) {
            int a,b; cin >> a >> b;
			que.push_back(a-1); // a = employee, b = package
			pac[b-1].second.push_back(que.size()-1);
		}
    }

    // construct the final tree and run DFS from the total bosses to get IN and OUT fields.
	in = out = vector<int>(n);
	visited = vector<bool>(n, false);
	vector<bool> isBoss(n, true);
	graph = vector< vector<int> >(n);
	for (int i=1; i<con.size(); ++i) { // skip the dummy connection
		graph[con[i].second].push_back(con[i].first);
		isBoss[con[i].first] = false;
	}
	for (int i=0; i<n; ++i)
		if (isBoss[i])
			dfs(i);

    // do union find and get the answers
    vector<bool> ans(que.size());
    uf = vector<int>(n);
    for (int i=0; i<n; ++i)
		uf[i]=i;
    for (int i=0; i<con.size(); ++i) {
        ufConnect(con[i].first, con[i].second);
        for (int j=relpac[i].first; j<relpac[i].second; ++j) {
			for (auto &k : pac[j].second) {
				int sent = pac[j].first;
				int sign = que[k];
				bool con1 = ufFind(sent) == ufFind(sign);
				bool con2 = (in[sign] <= in[sent]) && (out[sign] >= out[sent]);
                ans[k] = con1 && con2;
			}
        }
    }

	// output answer
	for (int i=0; i<ans.size(); ++i)
		if (ans[i])
			cout << "YES\n";
		else
			cout << "NO\n";
	return 0;
}
