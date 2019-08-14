#include<iostream>
using namespace std;
/*
	2019. 08. 13.
	백준 14648. 쿼리 맛보기

	세그먼트 트리
*/
typedef long long ll;
int N, Q, bias = 1;
ll tree[2050];

void update(int idx, int n) {
	tree[idx] = n;
	while (idx>>=1) {
		tree[idx] = tree[idx << 1] + tree[idx << 1 | 1];
	}
}

ll getSum(int left, int right) {
	ll sum = 0;
	while (left<right) {
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

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &Q);
	
	while ((bias <<= 1) < N);
	
	for (int i = 0,n; i < N; i++) {
		scanf("%d", &n);
		update(bias+i, n);
	}
	for (int i = 0,type,a,b,c,d; i < Q; i++) {
		scanf("%d%d%d", &type, &a, &b);
		if (type == 1) {
			ll sum = getSum(bias + (a - 1), bias + (b - 1));
			printf("%lld\n", sum);
			ll num1 = tree[bias + (a - 1)];
			ll num2 = tree[bias + (b - 1)];
			update(bias + (a - 1), num2);
			update(bias + (b - 1), num1);
		}
		else {
			scanf("%d%d", &c, &d);
			ll sum1 = getSum(bias + (a - 1), bias + (b - 1));
			ll sum2 = getSum(bias + (c - 1), bias + (d - 1));
			printf("%lld\n", sum1 - sum2);
		}
	}

	return 0;
}