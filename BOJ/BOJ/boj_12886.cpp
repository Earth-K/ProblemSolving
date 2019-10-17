#include<iostream>
using namespace std;

int sum;
bool chk[1501][1501];

void dfs(int x, int y) {
	if (chk[x][y]) return;
	chk[x][y] = true;

	int a[3]={x,y,sum-x-y};

	for (int i=0; i<3; i++) {
		for (int j=0; j<3; j++) {
			if (a[i] < a[j]) {
				int b[3] ={x,y,sum-x-y};
				b[i] += a[i];
				b[j] -= a[i];
				dfs(b[0], b[1]);
			}
		}
	}
}
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	sum = a+b+c;
	if (sum%3 != 0) {
		cout<<0;
		return 0;
	}
	dfs(a, b);
	if (chk[sum/3][sum/3])
		cout<<1;
	else
		cout<<0;
	return 0;
}