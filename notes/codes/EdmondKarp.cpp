int cap[1000][1000], flow[1000][1000], n;

int edmondKarp(int s, int t) {
	int b, e, q[n], p[n], d, FLOW=0; // flow[i][j] initialized to 0
	for(;;) {
		for(int i=0; i<n; ++i)
			p[i]=-1;
		for(q[b=e=0]=s; b<=e; ++b)
			for (int v=0; v<n; ++v)
				if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0) {
					p[q[++e]=v] = q[b];
				}
		if (p[t]<0)
			break;
		d = cap[p[t]][t] - flow[p[t]][t];
		for(int i=t; i!=s; i=p[i])
			d=min(d, cap[p[i]][i] - flow[p[i]][i]);
		for(int i=t; i!=s; i=p[i]) {
			flow[p[i]][i] += d;
			flow[i][p[i]] -= d;
		}
		FLOW += d;
	}
	return FLOW;
}
