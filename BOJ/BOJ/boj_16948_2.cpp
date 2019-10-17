#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct Obj {
	int r, c;
};
int dr[]={ -2,-2,0,0,2,2 };
int dc[]={ -1,1,-2,2,-1,1 };
int dist[200][200];

int main() {
	//freopen("input.txt","r",stdin);
	int n, r1, c1, r2, c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;
	memset(dist, -1, sizeof(dist));
	queue<Obj> Q;

	Q.push({ r1,c1 });
	dist[r1][c1] = 0;
	while (!Q.empty()) {
		int nowR = Q.front().r;
		int nowC = Q.front().c;
		Q.pop();

		for (int i=0; i<6; i++) {
			int nextR = nowR+dr[i];
			int nextC = nowC+dc[i];
			if (0<=nextR && nextR<n && 0<=nextC && nextC<n) {
				if (dist[nextR][nextC] == -1) {
					dist[nextR][nextC] = dist[nowR][nowC]+1;
					Q.push({ nextR,nextC });
				}
			}
		}
	}
	cout<<dist[r2][c2]<<endl;
	return 0;
}