#include<cstdio>
#include<algorithm>
using namespace std;
/*
	2019. 08. 23
	[BOJ] 백준 11053. 가장 긴 증가하는 부분 수열

	DP
*/
int idxs[1000],P[1000];
int arr[1000], N, idx;
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	idx = 0;
	P[idx] = arr[0];
	idxs[idx++] = 0;

	for (int i = 1; i < N; i++) {
		if (P[idx-1] < arr[i]) {
			P[idx] = arr[i];
			idxs[idx++] = i;
		}
		else {
			int tidx = lower_bound(P, P+idx, arr[i]) - P;
			P[tidx] = arr[i];
			idxs[tidx] = i;
		}
	}
	printf("%d", idx);
	return 0;
}