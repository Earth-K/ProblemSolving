#include<cstdio>
/*
	2019. 08. 22.
	���� 10844. ���� ��� ��

	DP
*/
int N;
//dp[i][j] : ���̰� i�� j�� ������ ��ܼ�
long long dp[101][10];

int main() {
	//freopen("input.txt","r",stdin);
	dp[1][0] = 0;
	for (int j = 1; j <= 9; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= 100; i++) {
		for (int j = 0; j <= 9; j++) {
			if (0 <= j - 1)
				dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % 1000000000;
			if (j + 1 <= 9)
				dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % 1000000000;
		}
	}

	scanf("%d", &N);
	unsigned long long ans = 0;
	for (int j = 0; j <= 9; j++)
		ans = (ans + dp[N][j])%1000000000;
	printf("%lld", ans);
	return 0;
}