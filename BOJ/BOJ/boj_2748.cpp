#include<iostream>
using namespace std;
/*
	2019.07.23
	���� 2748. �Ǻ���ġ �� 2
*/
int N;
long long f[91];
int main() {
	scanf("%d", &N);
	f[0] = 0; f[1] = 1;
	for(int i = 2; i <= N ; i++)
		f[i] = f[i - 1] + f[i - 2];

	printf("%lld", f[N]);
	return 0;
}