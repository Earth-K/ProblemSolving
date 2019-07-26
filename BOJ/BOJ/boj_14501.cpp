#include<iostream>
using namespace std;

int t[17], p[17], dp[17], N;

/*
	2019. 07. 26.
	น้มุ 14501. ล๐ป็

	DP
*/

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d",&N);
	for (int i = 1; i <= N; i++)
		scanf("%d%d", &t[i], &p[i]);

	for (int i = 2; i <= N+1; i++) {
		for (int j = 1; j < i; j++) {
			int m, pp, idx;
			m = pp = 0;
			idx = j;

			pp = p[idx];
			idx += t[idx];

			while (true) {
				
				if (idx == i) {
					m += pp;
					break;
				}
				else if (idx > i)
					break;

				m += pp;
				pp = p[idx];
				idx += t[idx];
			}

			if (dp[i] < dp[j-1] + m)
				dp[i] = dp[j-1] + m;	
		}
	}

	printf("%d", dp[N + 1]);

	return 0;
}