#include<cstdio>
/*
	2019. 08. 21.
	πÈ¡ÿ 2302. ±ÿ¿Â ¡¬ºÆ

	DP
*/
int N, M, fib[41];
bool seat[41];

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);

	fib[0] = 1; fib[1] = 1;
	for (int i = 2; i <= 40; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		//printf("%d ", fib[i]);
	}
	//printf("\n");

	for (int i = 0, v; i < M; i++) {
		scanf("%d", &v);
		seat[v] = true;
	}

	int p = 1, ans = 1;
	while (true) {
		if (p > N)
			break;

		int cnt = 0;
		while (p <= N && seat[p] == false) {
			p++;
			cnt++;
		}
		//printf("%d", fib[cnt]);
		ans *= fib[cnt];
		p++;
	}
	printf("%d", ans);
	return 0;
}