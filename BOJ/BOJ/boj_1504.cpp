#include<iostream>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
/*
	2019. 08. 02.
	백준 1504. 특정한 최단 경로
	다익스트라 알고리즘
*/
struct Obj {
	int v, w;
};
bool operator< (const Obj& a, const Obj& b) {
	return a.w > b.w;
}

bool visited[801];
vector<Obj> A[200001];
int dist[801];

priority_queue<Obj> pq;
int N, E;

void dij(int s) {
	for (int i = 1; i <= N; i++) {
		visited[i] = false;
		dist[i] = INT_MAX;
	}

	pq.push({ s,0 });
	dist[s] = 0;

	while (!pq.empty()) {
		int nowV = pq.top().v;
		int nowW = pq.top().w;
		pq.pop();

		visited[nowV] = true;
		
		for (int i = 0; i < A[nowV].size(); i++) {
			int nextV = A[nowV][i].v;
			int nextW = nowW + A[nowV][i].w;

			if (dist[nextV] > nextW && !visited[nextV]) {
				dist[nextV] = nextW;
				pq.push({nextV,nextW});
			}
		}
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &E);
	for (int i = 0,u,v,w; i < E; i++) {
		scanf("%d%d%d", &u, &v, &w);
		A[u].push_back({ v,w });
		A[v].push_back({ u,w });
	}

	int a, b;
	scanf("%d%d",&a,&b);
	int StoV1, StoV2, V1toN, V2toN, V1toV2;
	
	dij(N);
	V1toN = dist[a];
	V2toN = dist[b];

	dij(1);
	StoV1 = dist[a];
	StoV2 = dist[b];

	dij(a);
	V1toV2 = dist[b];

	int path1=-1, path2=-1;
	if (StoV1 != INT_MAX && V1toV2 != INT_MAX && V2toN != INT_MAX) {
		path1 = StoV1 + V1toV2 + V2toN;
	}
	if (StoV1 != INT_MAX && V1toV2 != INT_MAX && V2toN != INT_MAX) {
		path2 = StoV2 + V1toV2 + V1toN;
	}
	if (path1 == -1 && path2 == -1)
		printf("-1");
	else 
		printf("%d", path1 < path2 ? path1 : path2);
	return 0;
}