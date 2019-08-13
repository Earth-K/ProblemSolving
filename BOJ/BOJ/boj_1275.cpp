#include<iostream>

typedef long long ll;
using namespace std;

/*
	2019. 08. 13.
	백준 1275. 커피숍2

	세그먼트 트리
*/

int N, Q, bias = 1;
ll tree[263000];

ll getSum(int left, int right) {
	ll sum = 0;
	while (left < right) {
		if (left % 2 == 1) {
			sum += tree[left];
			left++;
		}
		if (right % 2 == 0) {
			sum += tree[right];
			right--;
		}

		left >>= 1;
		right >>= 1;
	}

	if (left == right)
		sum += tree[left];

	return sum;
}
void update(int a, ll b) {
	tree[a] = b;
	while (a >>= 1) {
		tree[a] = tree[a << 1] + tree[a << 1 | 1];
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &Q);
	
	while ((bias<<=1) < N);

	for (int i = 0,n; i < N; i++) {
		scanf("%d", &n);
		update(bias + i, n);
	}
	
	int x, y, a, b;
	while (Q--) {
		scanf("%d%d%d%d", &x, &y, &a, &b);
		if (x > y)
			swap(x, y);
		ll sum = getSum(bias+(x-1), bias+(y-1));
		printf("%lld\n", sum);
		update(bias+(a-1), b);
	}

	return 0;
}