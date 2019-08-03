#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
/*
	2019. 08. 04.
	백준 2458. 키 순서
*/
int N, M;
int a[501][501];
int cnt[501];
int main() {
	freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &M);
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			a[i][j] = (i == j) ? 0 : INF;
	
	for (int i = 0,u,v; i < M; i++) {
		scanf("%d%d", &u, &v);
		a[u][v] = 1;
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (a[i][j] < INF || a[j][i] < INF)
				cnt[i]++;
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (cnt[i] == N)
			ans++;
	}

	printf("%d", ans);
	return 0;
}