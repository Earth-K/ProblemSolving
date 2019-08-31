#include<cstdio>
#include<algorithm>
/*
	2019. 08. 31.
	[BOJ] น้มุ 15654. Nฐ๚ M (6)

	DFS
*/
int arr[8], ans[8];
int N, M;

void perm(int idx, int pre) {
	if (idx == M) {
		for (int i = 0; i<M; i++)
			printf("%d ", ans[i]);
		printf("\n");
		return;
	}
	
	for (int i = 0; i<N; i++) {
		if (pre < arr[i]) {
			ans[idx] = arr[i];
			perm(idx+1, arr[i]);
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i<N; i++)
		scanf("%d", &arr[i]);
	std::sort(arr, arr+N);
	perm(0, -1);
	return 0;
}