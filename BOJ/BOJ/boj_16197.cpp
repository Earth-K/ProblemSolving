#include<iostream>
using namespace std;

struct Ball {
	int r, c;
}balls[2];

int R, C;
char map[20][21];
int dr[]={1,-1,0,0};
int dc[]={0,0,-1,1};
int ans = 987654321;

bool boundChk(Ball b) {
	return 0<=b.r && b.r<R && 0<=b.c && b.c<C;
}
void dfs(int cnt, Ball b1, Ball b2) {
	if (cnt == 11) return;
	if (!boundChk(b1) && !boundChk(b2)) 
		return;
	if ((boundChk(b1) && !boundChk(b2)) || (!boundChk(b1) && boundChk(b2))) {
		if (ans>cnt) ans = cnt;
		return;
	}

	for (int i = 0; i<4; i++) {
		if (map[b2.r+dr[i]][b2.c+dc[i]] == '#' && map[b1.r+dr[i]][b1.c+dc[i]] == '#')
			dfs(cnt+1, b1, b2);
		else if(map[b1.r+dr[i]][b1.c+dc[i]] == '#')
			dfs(cnt+1, b1, { b2.r+dr[i],b2.c+dc[i] });
		else if (map[b2.r+dr[i]][b2.c+dc[i]] == '#')
			dfs(cnt+1, { b1.r+dr[i],b1.c+dc[i] }, b2);
		else
			dfs(cnt+1, { b1.r+dr[i],b1.c+dc[i] }, { b2.r+dr[i],b2.c+dc[i] });
	}
}

int main() {
	cin>>R>>C;
	for (int i=0; i<R; i++)
		cin>>map[i];

	int cnt = 0;
	for (int i = 0; i<R; i++) {
		for (int j = 0; j<C; j++) {
			if (map[i][j] == 'o')
				balls[cnt++] ={ i,j };
		}
	}

	dfs(0,balls[0],balls[1]);
	if (ans > 10)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}