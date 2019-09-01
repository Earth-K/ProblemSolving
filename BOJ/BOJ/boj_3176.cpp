#include<iostream>
#include<vector>
#include<algorithm>
/*
	2019. 09. 01.
	[BOJ] 백준 3176. 도로 네트워크 

	LCA (sparse table)
*/
#define INF 987654321
using namespace std;

struct Edge {
	int v, w;
};
struct Obj {
	int minLen, maxLen;
};

int N, K;
int level[100001], parent[100001][20], minVal[100001][20], maxVal[100001][20];
bool visited[100001];
vector<Edge> a[100001];

void dfs(int v, int cnt) {

	visited[v] = true;
	level[v] = cnt;

	for (Edge nextE : a[v]) {
		if (visited[nextE.v])continue;
		parent[nextE.v][0] = v;
		minVal[nextE.v][0] = nextE.w;
		maxVal[nextE.v][0] = nextE.w;
		dfs(nextE.v, cnt + 1);
	}
}

Obj LCA(int a, int b) {
	if (level[a] < level[b])
		swap(a, b);
	
	int diff = level[a] - level[b];
	int minDist, maxDist;

	minDist = INF;
	maxDist = -INF;

	int k = 0;
	while (diff >= (1 << k)) {
		if (diff & (1 << k)) {
			minDist = min(minDist, minVal[a][k]);
			maxDist = max(maxDist, maxVal[a][k]);
			a = parent[a][k];
		}
		k++;
	}
	if (a == b) 
		return{ minDist, maxDist };

	for (int k = 19; k >= 0; k--) {
		if (parent[a][k] != parent[b][k]) {
			minDist = min(minDist, min(minVal[a][k],minVal[b][k]));
			maxDist = max(maxDist, max(maxVal[a][k],maxVal[b][k]));
			a = parent[a][k];
			b = parent[b][k];
		}
	}
	minDist = min(minDist, min(minVal[a][0],minVal[b][0]));
	maxDist = max(maxDist, max(maxVal[a][0],maxVal[b][0]));
	
	return { minDist, maxDist };
}
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d",&N);
	for (int i = 0,u,v,w; i < N-1; i++) {
		scanf("%d%d%d", &u, &v, &w);
		a[u].push_back({ v,w });
		a[v].push_back({ u,w });
	}
	
	for (int i = 1; i <= N; i++) {
		minVal[i][0] = INF;
		maxVal[i][0] = -INF;
	}

	dfs(1,1);

	for (int k = 1; k <= 19; k++) {
		for (int i = 1; i <= N; i++) {
			parent[i][k] = parent[parent[i][k - 1]][k - 1];
			minVal[i][k] = min(minVal[parent[i][k - 1]][k - 1], minVal[i][k-1]);
			maxVal[i][k] = max(maxVal[parent[i][k - 1]][k - 1], maxVal[i][k-1]);
		}
	}

	scanf("%d", &K);
	for (int i = 0,a,b; i < K; i++) {
		scanf("%d%d", &a, &b);

		Obj res = LCA(a,b);
		printf("%d %d\n", res.minLen, res.maxLen);
	}
	return 0;
}