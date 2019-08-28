#include<cstdio>
using namespace std;
struct Point{
	int x, y, dir, k;
}P[1000];
bool isDied[1000];
short map[4001][4001];
int T, N, ans;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,-1,1 };

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
	for(int t = 1 ; t<=T ; t++)
	{
		scanf("%d", &N);
		for (int i = 0,x, y,dir,k; i < N; i++) {
			scanf("%d%d%d%d", &x, &y, &dir, &k);
			P[i] = { (x + 1000) * 2,(y + 1000) * 2,dir,k };
			isDied[i] = false;
		}

		ans = 0;
		int nextX, nextY;
		while(true)
		{
			bool flag = false;
			
			for (int i = 0; i < N; i++)
				map[P[i].y][P[i].x] = 0;

			for (int i = 0; i < N; i++) {
				Point &p = P[i];
				if (isDied[i] == false) {
					flag = true;
					nextY = p.y + dy[p.dir];
					nextX = p.x + dx[p.dir];
					if (0 <= nextY && nextY <= 4000 && 0 <= nextX && nextX <= 4000) {
						map[nextY][nextX]++;
						p.y = nextY;
						p.x = nextX;
					}
					else
						isDied[i] = true;
				}
			}
			if (!flag)
				break;

			for (int i = 0; i < N; i++) {
				if (isDied[i])  continue;
				const Point p = P[i];
				
				if (map[p.y][p.x] >= 2) {
					ans += p.k;
					isDied[i] = true;
				}
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}