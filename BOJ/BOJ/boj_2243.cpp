#include<iostream>
using namespace std;
/*
	2019. 08. 13.
	백준 2243. 사탕상자

	세그먼트 트리
*/

int tree[4200000];
int N, bias = 1;

void update(int b, int c) {
	b = bias + (b - 1);
	tree[b] += c;
	
	while (b >>= 1) {
		tree[b] = tree[b << 1] + tree[b << 1 | 1];
	}
}

int query(int n, int s, int e, int k) {
	if (s == e)
		return s;

	int mid = (s + e) >> 1;
	if (tree[n << 1] >= k)
		return query(n << 1, s, mid, k);
	else
		return query(n << 1 | 1, mid + 1, e, k - tree[n << 1]);
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);

	while ((bias <<= 1) <= 1000000);

	for (int i = 0,a,b,c; i < N; i++) {
		scanf("%d%d", &a, &b);
		if (a == 2) {
			scanf("%d", &c);
			update(b,c);
		}
		else {
			int idx = query(1, 1, bias, b);
			printf("%d\n", idx);
			update(idx,-1);
		}
	}

	return 0;
}