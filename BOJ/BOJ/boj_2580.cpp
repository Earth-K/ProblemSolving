#include<iostream>
using namespace std;

int map[9][9];
bool sq_chk[9][10], r_chk[9][10], c_chk[9][10];

bool solve(int cnt) {
	if (cnt == 81) {
		for (int i = 0; i<9; i++) {
			for (int j = 0; j<9; j++)
				cout<<map[i][j]<<" ";
			cout<<endl;
		}
		return true;
	}

	int r = cnt/9, c = cnt%9;
	int sqNum = 3*(r/3) + (c/3);

	if (map[r][c] != 0) {
		return solve(cnt+1);
	}
	else {
		for (int i = 1; i<=9; i++) {
			if (!r_chk[r][i] && !c_chk[c][i] && !sq_chk[sqNum][i]) {
				r_chk[r][i] = true;
				c_chk[c][i] = true;
				sq_chk[sqNum][i] = true;
				map[r][c] = i;
				if (solve(cnt+1))
					return true;
				map[r][c] = 0;
				sq_chk[sqNum][i] = false;
				c_chk[c][i] = false;
				r_chk[r][i] = false;
			}
		}
	}
	return false;
}
int main() {
	//freopen("input.txt","r",stdin);
	for (int i=0; i<9; i++) {
		for (int j=0; j<9; j++) {
			cin>>map[i][j];

			int sqNum = 3*(i/3) + (j/3);
			if (map[i][j] != 0) {
				r_chk[i][map[i][j]] = true;
				c_chk[j][map[i][j]] = true;
				sq_chk[sqNum][map[i][j]] = true;
			}
		}
	}
	solve(0);
	return 0;
}