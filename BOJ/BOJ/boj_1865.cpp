#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;
/*
	2019. 08. 04.
	백준 1865. 웜홀

	벨만-포드 알고리즘
*/
struct Edge {
	int v, w;
};
int TC,N,M,W;
int D[501];
vector<Edge> a[501];

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &TC);

	for (int t = 0; t < TC; t++) {
		scanf("%d%d%d", &N, &M, &W);
		
		for (int i = 1; i <= N; i++) {
			a[i].clear();
			if (i != 1)
				D[i] = INF;
		}
		
		for (int j = 0, u, v, w; j < M; j++) {
			scanf("%d%d%d", &u, &v, &w);
			a[u].push_back({ v,w });
			a[v].push_back({ u,w });
		}
		for (int j = 0, u, v, w; j < W; j++) {
			scanf("%d%d%d", &u, &v, &w);
			a[u].push_back({ v,-w });
		}

		bool negative_cycle = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (Edge e : a[j]) {
					int from = j;
					int to = e.v;
					int cost = e.w;
					if (D[from] != INF && (D[to] > D[from] + cost)) {
						D[to] = D[from] + cost;
						if (i == N) {
							negative_cycle = true;
						}
					}
				}
			}
		}

		if (negative_cycle)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}