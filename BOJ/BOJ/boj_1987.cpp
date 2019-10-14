#include<iostream>
using namespace std;

int R, C, ans;
int dr[]={ -1,1,0,0 };
int dc[]={ 0,0,-1,1 };
bool alp[26];
char map[20][21];

bool boundChk(int r, int c) {
	return 0<=r && r<R && 0<=c && c<C;
}

void go(int r, int c, int cnt) {
	int idx = map[r][c]-'A';

	if (!boundChk(r, c)) return;
	if (alp[idx]) return;

	if (ans<cnt) ans = cnt;

	for (int i=0; i<4; i++) {
		alp[idx] = true;
		go(r+dr[i], c+dc[i], cnt+1);
		alp[idx] = false;
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	cin>>R>>C;

	for (int i=0; i<R; i++)
		cin>>map[i];
	go(0,0,1);

	cout<<ans;
	return 0;
}