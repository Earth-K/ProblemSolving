#include<cstdio>
using namespace std;
/*
	2019. 08. 28.
	[BOJ] น้มุ 15649. Nฐ๚ M (3)

	DFS
*/
int N, M;
int arr[8], ans[8];

void perm(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		ans[idx] = arr[i];
		perm(idx + 1);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	perm(0);
	return 0;
}