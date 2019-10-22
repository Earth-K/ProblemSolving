#include<iostream>
#include<vector>
#include<cstring>
#include<tuple>
#include<set>
#define WALL -1
using namespace std;
int N, M, cnt;
int map[1000][1000];
int w[1000001];
int dr[]={ -1,1,0,0 };
int dc[]={ 0,0,-1,1 };

void dfs(int r, int c, int num) {
	if (map[r][c] == WALL) 
		return;

	map[r][c] = num;
	w[num]++;

	for (int i=0; i<4; i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if (map[nr][nc] == 0) {
			if (0<=nr && nr<N && 0<=nc && nc<M)
				dfs(nr, nc, num);
		}
	}
}

int getAns(int r, int c) {
	set<int> near;
	int ret=1;

	for (int i=0; i<4; i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if (0<=nr && nr<N && 0<=nc && nc<M) {
			if (map[nr][nc] != 0 && map[nr][nc] != WALL)
				near.insert(map[nr][nc]);
		}
	}
	for (int n: near)
		ret += w[n];
	return ret;
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin>>N>>M;

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			scanf("%1d", &map[i][j]);
			if (map[i][j] == 1)
				map[i][j] = WALL;
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (map[i][j] == 0)
				dfs(i, j, ++cnt);
		}
	}

	for (int i=0; i<N; i++) {
		for (int j=0; j<M; j++) {
			if (map[i][j] != WALL)
				cout<<0;
			else 
				cout<<getAns(i, j)%10;
		}
		cout<<'\n';
	}

	return 0;
}