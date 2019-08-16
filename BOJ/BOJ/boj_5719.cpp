#include<cstdio>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;
/*
	2019. 08. 16.
	백준 5719. 거의 최단 경로

	다익스트라
*/
int N, M, S, D, ans;

struct Edge {
	int u, v, p, short_path;
}E[10000];
struct Info {
	int v, cost, edge_idx;
};
bool operator<(const Info& a, const Info& b) {
	return a.cost > b.cost;
}

int dist[501];
bool visited[501];
vector<Info> adj[501];
vector<int> shortpath_list[501];
priority_queue<Info> pq;
queue<int> q;

int main() {
	//freopen("input.txt","r",stdin);
	while (1) {
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0) break;
		scanf("%d%d", &S, &D);
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < N; i++) {
			dist[i] = INF;
			adj[i].clear();
			shortpath_list[i].clear();
		}
		for (int i = 0; i < M; i++) {
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].p);
			E[i].short_path = 0;
			adj[E[i].u].push_back({ E[i].v, E[i].p, i });
		}

		// 다익스트라
		int nowV, nowCost, nextV, cost, edge_idx;

		dist[S] = 0;
		pq.push({ S,0,-1 });
		while (!pq.empty()) 
		{
			nowV = pq.top().v;
			nowCost = pq.top().cost;
			pq.pop();

			if (nowCost != dist[nowV]) continue;

			for (int i = 0; i < adj[nowV].size(); i++) {
				nextV = adj[nowV][i].v;
				cost = nowCost + adj[nowV][i].cost;
				edge_idx = adj[nowV][i].edge_idx;
				if (dist[nextV] > cost) {
					dist[nextV] = cost;
					pq.push({ nextV,cost,edge_idx });

					//최단 경로 비용을 갱신하면서 현재 정점에서 nextV에 연결된 edge_idx를 저장
					shortpath_list[nextV].clear();
					shortpath_list[nextV].push_back(edge_idx);
				}
				else if (dist[nextV] == cost) {
					shortpath_list[nextV].push_back(edge_idx);
				}
			}
		}

		ans = -1;
		if (dist[D] != INF) 
		{
			for (int i = 0; i < N; i++) 
				visited[i] = false;

			// S부터 D까지 최단 경로에 해당하는 Edge를 모두 1로 check
			q.push(D);
			visited[D] = true;
			while (!q.empty()) 
			{
				nowV = q.front(); q.pop();
				for (int i = 0; i < shortpath_list[nowV].size(); i++) {
					edge_idx = shortpath_list[nowV][i];
					E[edge_idx].short_path = 1;
					if (!visited[E[edge_idx].u]) {
						visited[E[edge_idx].u] = true;
						q.push(E[edge_idx].u);
					}
				}
			}

			// 거의 최단 경로를 구하기 위한 다익스트라
			for (int i = 0; i < N; i++)
				dist[i] = INF;
			dist[S] = 0;
			pq.push({ S,0,-1 });
			while (!pq.empty()) {
				nowV = pq.top().v; 
				nowCost = pq.top().cost;
				pq.pop();
				
				if (nowCost != dist[nowV]) continue;

				if (nowV == D) {
					ans = nowCost;
					break;
				}
				for (int i = 0; i < adj[nowV].size(); i++) {
					nextV = adj[nowV][i].v;
					cost = nowCost + adj[nowV][i].cost;
					edge_idx = adj[nowV][i].edge_idx;

					// 최단 경로에 해당하는 Edge인 경우 무시
					if (E[edge_idx].short_path == 1) 
						continue;

					if (dist[nextV] > cost){
						dist[nextV] = cost;
						pq.push({ nextV,cost,edge_idx });
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}