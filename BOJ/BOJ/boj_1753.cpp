#include<iostream>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

struct Obj {
	int v, w;
};
struct cmp {
	bool operator()(const Obj& o1, const Obj& o2) {
		return o1.w> o2.w;
	}
};

priority_queue<Obj,vector<Obj>,cmp> pq;
vector<Obj> a[20001];
int dist[20001];
int V, E, K;

void dij(int S) {
	pq.push({S,0});

	while (!pq.empty()) {
		int nowV = pq.top().v;
		int nowW = pq.top().w;
		pq.pop();
		
		if (dist[nowV] != INF)
			continue;

		dist[nowV] = nowW;

		for (Obj e : a[nowV]) {
			if (dist[e.v] == INF)
				pq.push({ e.v,e.w+nowW });
		}
	}
}

int main() {
	freopen("input.txt","r",stdin);
	cin>>V>>E>>K;
	for (int i=0, u, v, w; i<E; i++) {
		cin>>u>>v>>w;
		a[u].push_back({ v,w });
	}
	for (int i=1; i<=20000; i++)
		dist[i] = INF;

	dij(K);

	for (int i=1; i<=V; i++) {
		if (dist[i] == INF)
			cout<<"INF"<<'\n';
		else
			cout<<dist[i]<<'\n';
	}
	return 0;
}