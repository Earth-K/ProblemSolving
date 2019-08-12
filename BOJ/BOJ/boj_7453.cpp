#include<iostream>
#include<algorithm>
#define ll long long
#define N_MAX 4000
using namespace std;
/*
	2019. 08. 13. 
	7453. 합이 0인 네 정수 
	
	binary search
*/
int N, A[N_MAX], B[N_MAX], C[N_MAX], D[N_MAX];
ll AB[N_MAX*N_MAX], CD[N_MAX*N_MAX];

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);

	int idx = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[idx] = A[i] + B[j];
			CD[idx++] = C[i] + D[j];
		}
	}
	
	ll ans = 0;
	sort(CD, CD+idx);
	for (int i = 0; i < N*N; i++) {
		ll fn = -AB[i];
		ans += upper_bound(CD, CD + idx, fn) - lower_bound(CD, CD + idx, fn);
	}

	printf("%lld", ans);
	return 0;
}