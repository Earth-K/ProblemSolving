#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
/*
	2019. 08. 19.
	백준 2098. 외판원 순회

	비트마스크, DP
*/

const int IMPOSSIBLE = 9876543210;
int W[16][16], N, dp[16][1 << 16], start;

int TSP(int current, int visited) {
	if (visited == (1 << N) - 1) {
		// 0으로 향하는 길이 없는 경우 IMPOSSIBLE 리턴
		return W[current][start] ? W[current][start] : IMPOSSIBLE;
	}
	int &ret = dp[current][visited];

	if (ret != -1) return ret;

	ret = IMPOSSIBLE;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) continue; // 이미 방문된 경우
		if (W[current][i] == 0) continue; // 길이 없는 경우

		// current -> i 비용 + i에서 모든 정점 방문하고 0으로 돌아오는 비용
		ret = min(ret, W[current][i] + TSP(i, visited | (1 << i)));
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &W[i][j]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", TSP(0, 1));

	return 0;
}