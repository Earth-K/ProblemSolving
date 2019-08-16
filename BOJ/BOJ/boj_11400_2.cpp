#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Edge {
	int u, v;
	bool ans;
};
bool operator<(const Edge& a, const Edge& b) {
	if (a.u == b.u)
		return a.v < b.v;
	else
		return a.u < b.u;
}
struct Info {
	int v, edge_idx;
};
vector<Info> adj[100001];
Edge edges[1000001];
int discovered[100001];
int V, E, cnt, cnt_ans;

int dfs(int nowV, int parent) {
	discovered[nowV] = ++cnt;
	int ret = discovered[nowV];

	for (Info n : adj[nowV]) {
		int nextV = n.v;
		int eidx = n.edge_idx;

		if (nextV == parent) continue;
		
		if (!discovered[nextV]) {
			int low = dfs(nextV, nowV);
			if (discovered[nowV] < low) {
				edges[eidx].ans = true;
				cnt_ans++;
			}
			else 
				ret = min(ret, low);
		}
		else
			ret = min(ret, discovered[nextV]);
	}

	return ret;
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &V, &E);
	for (int i = 0,u,v; i < E; i++){
		scanf("%d%d", &u, &v);
		if (u > v)	swap(u, v);
		edges[i] = { u,v,false };
	}

	sort(edges, edges + E);

	for (int i = 0, u, v; i < E; i++) {
		u = edges[i].u;
		v = edges[i].v;
		adj[u].push_back({ v,i });
		adj[v].push_back({ u,i });
	}

	for (int i = 1; i <= V; i++) {
		if(!discovered[i])
			dfs(i, -1);
	}
	
	printf("%d\n", cnt_ans);
	for (int i = 0; i < E; i++) {
		Edge e = edges[i];
		if(e.ans)
			printf("%d %d\n", e.u, e.v);
	}

	return 0;
}