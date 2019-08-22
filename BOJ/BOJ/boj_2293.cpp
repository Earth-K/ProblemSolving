#include<cstdio>
/*
	2019. 08. 22.
	백준 2293. 동전1

	DP
*/

int c[101], N ,K;
int dp[10001];

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &c[i]);
	
	dp[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= K; j++) {
			if (c[i] > j)
				dp[j] = dp[j];
			else
				dp[j] = dp[j] + dp[j - c[i]];
		}
	}
	printf("%d", dp[K]);
	return 0;
}