#include<iostream>
using namespace std;
/*
	2019. 07. 23. Start
	~ 2019.07. 23. AC

	백준 2042. 구간 합 구하기
*/
int N, M, K;
long long tree[5000001];
int main() {
	freopen("input.txt","r",stdin);
	scanf("%d%d%d", &N, &M, &K);
	
	int s = 1;
	while (s < N) 
		s = s << 1;
	
	for (int i = s; i < s+N; i++)
		scanf("%d", &tree[i]);
	
	int idx = s;
	s /= 2;
	while (s > 0) {
		for (int i = 0; i < s; i++)
			tree[s + i] = tree[(s + i) * 2] + tree[(s + i) * 2 + 1];
		s /= 2;
	}

	for (int i = 0,a,b,c; i < M + K; i++) {
		scanf("%d%d%d", &a, &b, &c);

		if (a == 1) {
			int p = idx + (b - 1);
			tree[p] = c;
			p /= 2;
			while (p > 0) {
				tree[p] = tree[p * 2] + tree[p * 2 + 1];
				p /= 2;
			}
		}
		else {
			long long sum = 0;
			int s = idx + (b - 1);
			int e = idx + (c - 1);
			if (s == e) {
				printf("%lld", tree[s]);
				continue;
			}

			while (s < e) {
				if ((s & 1) == 1)
					sum += tree[s++];
				if ((e & 1) == 0)
					sum += tree[e--];
				
				s /= 2;
				e /= 2;
				
				if (s == e)
					sum += tree[s];
			}
			printf("%lld\n", sum);
		}
	}

	return 0;
}