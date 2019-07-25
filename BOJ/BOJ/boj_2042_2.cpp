#define ll long long
#include<iostream>
using namespace std;

int N, M, K;
ll A[1000001], tree[1000001];

void update(int i, ll diff) {
	while (i <= N) {
		tree[i] += diff;
		i += (i&-i);
	}
}

ll sum(int i) {
	ll ret = 0;

	while (i>0) {
		ret += tree[i];
		i -= (i&-i);
	}

	return ret;
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d%d", &N, &M, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%lld", &A[i]);
		update(i, A[i]);
	}

	for (int i = 0; i < M + K; i++) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);

		if (a == 1) {
			ll diff = c - A[b];

			A[b] = c;
			update(b, diff);
		}
		else {
			printf("%lld\n", sum(c) - sum(b - 1));
		}
	}
	return 0;
}