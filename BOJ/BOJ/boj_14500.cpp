#include<iostream>
using namespace std;

int R, C, map[500][500];
int dr[]={ -1,1,0,0 };
int dc[]={ 0,0,-1,1 };
bool visited[500][500];
int ans;

bool boundChk(int r, int c) {
	return 0<=r && r<R && 0<=c && c<C;
}
void dfs(int r, int c, int cnt, int sum) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	visited[r][c] = true;
	for (int i=0; i<4; i++) {
		int nextR = r+dr[i], nextC = c+dc[i];
		if (boundChk(nextR, nextC) && !visited[nextR][nextC])
			dfs(nextR, nextC, cnt+1, sum+map[r][c]);
	}
	visited[r][c] = false;
}

int main() {
	cin>>R>>C;
	for (int i=0; i<R; i++)
		for (int j=0; j<C; j++)
			cin>>map[i][j];

	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			dfs(i, j, 0, 0);
			int res;
			if (i+2 < R && j+1<C) {
				res = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j+1];
				if (ans<res) ans = res;
			}
			if (i+2 < R && 0<=j-1) {
				res = map[i][j] + map[i+1][j] + map[i+2][j] + map[i+1][j-1];
				if (ans<res) ans = res;
			}
			if (j+2 < C && i+1<R) {
				res = map[i][j] + map[i][j+1] + map[i][j+2] + map[i+1][j+1];
				if (ans<res) ans = res;
			}
			if (j+2 < C && 0<=i-1) {
				res = map[i][j] + map[i][j+1] + map[i][j+2] + map[i-1][j+1];
				if (ans<res) ans = res;
			}
		}
	}
	cout<<ans;
	return 0;
}