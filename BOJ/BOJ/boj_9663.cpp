#include<iostream>
using namespace std;

int N, map[14][14], ans;

bool check(int r, int c) {
	int i=r-1, j=c;
	while (0<=i) {
		if (map[i--][j] == 1)
			return false;
	}
	i=r-1, j=c-1;
	while (0<=i && 0<=j) {
		if (map[i--][j--] == 1)
			return false;
	}
	i=r-1, j=c+1;
	while (0<=i && j<N) {
		if (map[i--][j++] == 1)
			return false;
	}
	return true;
}
void calc(int r) {
	if (r==N) {
		ans++;
		return;
	}
	for (int c=0; c<N; c++) {
		map[r][c] = 1;
		if (check(r, c))
			calc(r+1);
		map[r][c] = 0;
	}
}
int main() {
	cin>>N;
	calc(0);
	cout<<ans;
	return 0;
}