#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
/*
	2019. 09. 02.
	[BOJ] 백준 1167. 트리의 지름

	트리
*/
struct Node{
	int v, w;
};
int V;

vector<Node> adj[100001];
bool visited[100001];
int maxW, maxV;

queue<Node> Q;
void bfs(int V) {
	memset(visited, 0, sizeof(visited));
	visited[V] = true;
	Q.push({ V, 0 });
	maxV = maxW = 0;

	int nowV, nowW, nextV, nextW;
	while (!Q.empty()) {
		nowV = Q.front().v;	nowW = Q.front().w;	Q.pop();

		if (maxW < nowW) {
			maxV = nowV;
			maxW = nowW;
		}

		for (Node nextN : adj[nowV]) {
			nextV = nextN.v;
			nextW = nowW + nextN.w;
			if (!visited[nextV]) 
			{
				visited[nextV] = true;
				Q.push({ nextV, nextW });
			}
		}
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &V);

	for (int i = 0, n; i<V; i++) {
		scanf("%d", &n);
		while (true) 
		{
			int nextV, nextW;
			scanf("%d", &nextV);
			if (nextV == -1) break;
			scanf("%d", &nextW);
			adj[n].push_back({ nextV, nextW });
			adj[nextV].push_back({ n, nextW });
		}
	}
	bfs(1);
	bfs(maxV);
	printf("%d", maxW);
	return 0;
}