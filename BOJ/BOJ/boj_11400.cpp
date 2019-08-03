#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*
	2019. 08. 04.
	백준 11400. 단절선
*/
struct Edge {
	int u, v;
};
bool operator<(const Edge& a, const Edge& b) {
	if (a.u == b.u)
		return a.v < b.v;
	else
		return a.u < b.u;
}
int discovered[100001];
vector<int> a[100001];
vector<Edge> edges;
int V, E, cnt;

int dfs(int nowV, int parentV) {
	int ret;
	discovered[nowV] = ++cnt;
	ret = discovered[nowV];
	
	for (int nextV : a[nowV]) {
		if (nextV == parentV)
			continue;
		if (!discovered[nextV]) { 
			int df = dfs(nextV, nowV);
			if (df > discovered[nowV])
				edges.push_back({min(nowV,nextV),max(nowV,nextV)});
			ret = min(ret, df);
		}
		else {
			ret = min(ret, discovered[nextV]);
		}
	}

	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);

	scanf("%d%d", &V, &E);
	for (int i = 0,u,v; i < E; i++) {
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		if(!discovered[i])
			dfs(i,0);
	}

	printf("%d\n", edges.size());
	sort(edges.begin(), edges.end());
	for (Edge e : edges) 
		printf("%d %d\n", e.u, e.v);

	return 0;
}