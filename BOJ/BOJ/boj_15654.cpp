#include<cstdio>
#include<algorithm>
/*
	2019. 08. 28.
	[BOJ] น้มุ 15654. Nฐ๚ M (5)

	DFS
*/
int N, M, arr[8], ans[8];
bool chk[10001];

void perm(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (chk[arr[i]]) continue;

		chk[arr[i]] = true;
		ans[idx] = arr[i];
		perm(idx+1);
		chk[arr[i]] = false;
	}
}
int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr+N);
	perm(0);
	return 0;
}