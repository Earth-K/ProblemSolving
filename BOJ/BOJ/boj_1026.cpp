#include<cstdio>
#include<algorithm>
/*
	2019. 08. 31.
	[BOJ] 백준 1026. 보물

	정렬
*/
int N,A[50],B[50];
bool comp(const int &a, const int &b) {
	return a>b;
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
		scanf("%d", &A[i]);
	for (int i = 0; i<N; i++)
		scanf("%d", &B[i]);

	std::sort(A, A+N);
	std::sort(B, B+N, comp);
	int ans = 0;
	for (int i = 0; i<N; i++)
		ans += A[i]*B[i];
	printf("%d", ans);
	return 0;
}