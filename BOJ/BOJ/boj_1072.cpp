#include<iostream>
using namespace std;
/*
	2019. 08. 13.
	백준 1072. 게임

	이분 탐색
*/
int X, Y;
int BS(int Y, int X) {
	int res = (double)Y * 100 / X;
	if (res >= 99)
		return -1;

	int left = 0, right = 1000000000;
	while (left <= right) {
		int mid = (left + right) / 2;
		int tmp = (double)(Y + mid) * 100 / (X + mid);
		if (tmp > res)
			right = mid - 1;
		else
			left = mid + 1;

	}
	return left;
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &X, &Y);
	printf("%d", BS(Y, X));
	return 0;
}