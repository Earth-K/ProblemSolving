#include<iostream>
using namespace std;
/*
	2019.07.23
	백준 2748. 피보나치 수 2
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