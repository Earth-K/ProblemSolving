#include<iostream>
using namespace std;
int n, map[2200][2200], cnt[3];
bool chkPaper(int r, int c, int size) {
	int num = map[r][c];
	for (int i=r; i<r+size; i++) {
		for (int j=c; j<c+size; j++) {
			if (map[i][j] != num)
				return false;
		}
	}
	return true;
}
void solve(int r, int c, int size) {
	if (chkPaper(r, c, size)) {
		cnt[map[r][c]+1] += 1;
		return;
	}

	int m = size/3;
	solve(r, c, m);
	solve(r, c+m, m);
	solve(r, c+m*2, m);
	solve(r+m, c, m);
	solve(r+m, c+m, m);
	solve(r+m, c+m*2, m);
	solve(r+m*2, c, m);
	solve(r+m*2, c+m, m);
	solve(r+m*2, c+m*2, m);
}

int main() {
	std::ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("input.txt","r",stdin);
	cin>>n;

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin>>map[i][j];

	solve(0, 0, n);
	for (int i=0; i<3; i++)
		cout<<cnt[i]<<'\n';

	return 0;
}