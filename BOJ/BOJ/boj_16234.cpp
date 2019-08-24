#include<iostream>
#include<vector>
using namespace std;
/*
	2019. 08. 24.
	백준 16234. 인구 이동

	DFS, 시뮬레이션
*/
struct Obj {
	int r, c;
};
int N, L, R, map[50][50], map2[50][50];
bool visited[50][50];
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };
vector<Obj> vt;

int getSum(int r, int c) {
	vt.push_back({ r,c });
	visited[r][c] = true;

	int nextR, nextC, sub, sum;
	nextR = nextC = sub = sum = 0;

	sum = map[r][c];
	for (int i = 0; i < 4; i++) {
		nextR = r + dr[i];
		nextC = c + dc[i];
		sub = abs(map[r][c] - map[nextR][nextC]);
		if (0 <= nextR && nextR < N && 0 <= nextC && nextC < N &&
			L <= sub && sub <= R &&
			visited[nextR][nextC] == false) {
			sum += getSum(nextR, nextC);
		}
	}
	return sum;
}
int main() {
	int ans = 0;
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &L, &R);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	while (true) {
		bool flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visited[i][j]) {
					vt.clear();
					int sum = getSum(i, j);
					int val = sum / vt.size();
					for (Obj o : vt)
						map2[o.r][o.c] = val;
					if (vt.size() != 1)
						flag = true;
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map[i][j] = map2[i][j];
				visited[i][j] = false;
			}
		}
		if (flag)
			ans++;
		else
			break;
	}
	printf("%d", ans);
	return 0;
}