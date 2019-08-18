#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
/*
	2019. 08. 19.
	���� 2098. ���ǿ� ��ȸ

	��Ʈ����ũ, DP
*/

const int IMPOSSIBLE = 9876543210;
int W[16][16], N, dp[16][1 << 16], start;

int TSP(int current, int visited) {
	if (visited == (1 << N) - 1) {
		// 0���� ���ϴ� ���� ���� ��� IMPOSSIBLE ����
		return W[current][start] ? W[current][start] : IMPOSSIBLE;
	}
	int &ret = dp[current][visited];

	if (ret != -1) return ret;

	ret = IMPOSSIBLE;
	for (int i = 0; i < N; i++) {
		if (visited & (1 << i)) continue; // �̹� �湮�� ���
		if (W[current][i] == 0) continue; // ���� ���� ���

		// current -> i ��� + i���� ��� ���� �湮�ϰ� 0���� ���ƿ��� ���
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