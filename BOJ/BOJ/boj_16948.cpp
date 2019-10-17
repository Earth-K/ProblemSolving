#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Obj {
	int r, c, cnt;
};
int dr[]={ -2,-2,0,0,2,2 };
int dc[]={ -1,1,-2,2,-1,1 };

int main() {
	freopen("input.txt","r",stdin);
	int n,r1,c1,r2,c2;

	cin >> n >> r1 >> c1 >> r2 >> c2;
	vector<vector<bool>> v(n, vector<bool>(n,0));
	queue<Obj> Q;

	Q.push({r1,c1,0});
	v[r1][c1] = true;
	int ans = 987654321;
	while (!Q.empty()) {
		int nowR = Q.front().r;
		int nowC = Q.front().c; 
		int nowCnt = Q.front().cnt;
		Q.pop();

		if (nowR == r2 && nowC == c2) {
			if (ans>nowCnt) 
				ans = nowCnt;
		}
		for (int i=0; i<6; i++) {
			int nextR = nowR+dr[i];
			int nextC = nowC+dc[i];
			if (0<=nextR && nextR<n && 0<=nextC && nextC<n) {
				if (v[nextR][nextC] == false) {
					v[nextR][nextC] = true;
					Q.push({ nextR,nextC,nowCnt+1 });
				}
			}
		}
	}
	if (ans==987654321)
		cout<<-1<<endl;
	else
		cout<<ans<<endl;
	return 0;
}