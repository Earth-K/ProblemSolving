#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int N, M;
/*
	2019. 08. 01.
	백준 11657. 타임머신

	벨만-포드 알고리즘
*/
struct Edge {
	int from, to, cost;
};
Edge nodes[6000];
int dist[501];
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);

	for (int i = 0, a, b, c; i < M; i++) {
		scanf("%d%d%d", &a, &b, &c);
		nodes[i] = { a,b,c };
	}

	dist[1] = 0;
	for (int i = 2; i <= N; i++) 
		dist[i] = INT_MAX;

	bool negative_cycle = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int x = nodes[j].from;
			int y = nodes[j].to;
			int z = nodes[j].cost;
			if (dist[x] != INT_MAX && dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;
				if (i == N) {
					negative_cycle = true;
				}
			}
		} 
	}
	if (negative_cycle)
		printf("-1\n");
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INT_MAX)
				printf("-1\n");
			else
				printf("%d\n", dist[i]);
		}
	}
	return 0;
}