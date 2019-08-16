#include<iostream>
#include<algorithm>
#include<vector>
#define MAX_N 100005
#define INF 987654321
typedef long long ll;
using namespace std;
/*
	2019. 08. 16.
	¹éÁØ 1708. º¼·Ï ²®Áú

	ÄÁº¤½º Çæ
*/
int N;
struct Point {
	ll x, y, idx;
}P[MAX_N];
Point p1;
vector<int> vt;

ll ccw(const Point& a, const Point& b, const Point& c) {
	ll res = a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x * a.y;
	if (res > 0) return 1;
	else if (res == 0) return 0;
	else return -1;
}
ll getDist(const Point& a, const Point& b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool comp(const Point& a, const Point& b) {
	int res = ccw(p1, a, b);
	if (res == 0) {
		ll dist1 = getDist(p1, a);
		ll dist2 = getDist(p1, b);
		return dist1 < dist2;
	}
	else return res > 0;
}
int main() {
	//freopen("input.txt","r", stdin);
	scanf("%d", &N);
	p1 = { INF,INF };
	for (int i = 1; i <= N; i++) {
		scanf("%lld%lld", &P[i].x, &P[i].y);
		P[i].idx = i;
		if (p1.x > P[i].x) p1 = P[i];
		else if (p1.x == P[i].x && p1.y > P[i].y) p1 = P[i];
	}

	sort(P+1, P+N+1, comp);
	vt.resize(N+1);
	int vidx = 0;
	for (int i = 1; i <= N; i++) {
		while (vidx >= 2 && ccw(P[vt[vidx-2]], P[vt[vidx-1]], P[i]) <= 0) {
			vidx--;
		}
		vt[vidx++] = i;
	}

	printf("%d", vidx);
	/*
	for (int i = 0; i < vidx; i++)
		printf("%d ", P[vt[i]].idx);

	printf("p1 : %d,%d\n\n", p1.x, p1.y);
	for (int i = 0; i < N; i++) 
		printf("P[%d] : %d, %d\n", i, P[i].x, P[i].y);
	*/
	return 0;
}