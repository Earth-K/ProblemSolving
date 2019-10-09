#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
/*
	2019. 10. 09.
	[BOJ] 백준 14888. 연산자 끼워넣기

	순열
*/
int N;
vector<int> nums, ops;

int calc(int res, int opIdx) {
	int a = res;
	int b = nums[opIdx+1];
	int op = ops[opIdx];

	if (op == 0) return a+b;
	else if (op == 1) return a-b;
	else if (op == 2) return a*b;
	else return a/b;
}
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);
	for (int i = 0, n; i<N; i++) {
		scanf("%d", &n);
		nums.push_back(n);
	}
	for (int i = 0, cnt; i<4; i++) {
		scanf("%d", &cnt);
		while (cnt--)
			ops.push_back(i);
	}

	int min, max, res;
	min = 9876543210;
	max = -min;
	do{
		res = nums[0];
		int sz = ops.size();
		for (int i = 0; i<sz; i++)
			res = calc(res, i);
		if (max < res) max = res;
		if (min > res) min = res;
	} while (next_permutation(ops.begin(), ops.end()));

	printf("%d\n%d", max, min);
	return 0;
}