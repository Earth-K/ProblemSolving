#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
typedef long long ll;
using namespace std;
/*
	2019. 08. 16.
	πÈ¡ÿ 3878. ¡° ∫–∏Æ

	ƒ¡∫§Ω∫ «Ê
*/
struct Point {
	ll x, y;
}p1,p2,black[101],white[101];

Point convex1[101], convex2[101];
int idx1, idx2;

ll ccw(Point a, Point b, Point c) {
	ll res = a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x *b.y - b.x*a.y;
	if (res < 0) return -1;
	else if (res == 0) return 0;
	else return 1;
}
ll getDist(const Point& a, const Point& b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
bool operator<(const Point& a, const Point& b) {
	int res = ccw(p1, a, b);
	if (res == 0) {
		ll dist1 = getDist(p1, a);
		ll dist2 = getDist(p1, b);
		return dist1 < dist2;
	}
	else
		return res > 0;
}
bool isCrossed(const Point& a, const Point& b, const Point& c, const Point& d) {
	int cc1 = ccw(a, b, c); int cc2 = ccw(a, b, d);
	int cc3 = ccw(c, d, a);	int cc4 = ccw(c, d, b);

	if (cc1 == 0 && cc2 == 0 && cc3 == 0 && cc4 == 0) {
		int minX1, maxX1, minY1, maxY1, minX2, maxX2, minY2, maxY2;
		minX1 = min(a.x, b.x); maxX1 = max(a.x, b.x);
		minY1 = min(a.y, b.y); maxY1 = max(a.y, b.y);
		minX2 = min(c.x, d.x); maxX2 = max(c.x, d.x);
		minY2 = min(c.y, d.y); maxY2 = max(c.y, d.y);
		if (a.x == c.x) {
			if (minY1 > maxY2 || minY2 > maxY1)
				return false;
		}
		else {
			if (minX1 > maxX2 || minX2 > maxX1)
				return false;
		}
	}
	return cc1*cc2 <= 0 && cc3*cc4 <= 0;
}
int T,N,M;
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &T);
	while (T--) {
		p1 = { INF,INF };
		p2 = { INF,INF };
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%lld%lld", &black[i].x, &black[i].y);
			if (p1.y > black[i].y) p1 = black[i];
			else if (p1.y == black[i].y && p1.x > black[i].x) p1 = black[i];
		}
		for (int i = 0; i < M; i++) {
			scanf("%lld%lld", &white[i].x, &white[i].y);
			if (p2.y > white[i].y) p2 = white[i];
			else if (p2.y == white[i].y && p2.x > white[i].x) p2 = white[i];
		}
		
		idx1 = -1;
		sort(black, black + N);
		for (int i = 0; i < N; i++) {
			while (idx1 > 0 && ccw(convex1[idx1 - 1], convex1[idx1], black[i]) <= 0)
				idx1--;
			convex1[++idx1] = black[i];
		}
		convex1[++idx1] = black[0];

		p1 = p2;
		idx2 = -1;
		sort(white, white + M);
		for (int i = 0; i < M; i++) {
			while (idx2 > 0 && ccw(convex2[idx2 - 1], convex2[idx2], white[i]) <= 0)
				idx2--;
			convex2[++idx2] = white[i];
		}
		convex2[++idx2] = white[0];

		if (N == 1 && M == 1) {
			printf("YES\n");
			continue;
		}

		int i, j;
		for( i = 0 ; i<idx1 ; i++){
			for (j = 0; j < idx2; j++) {
				if (ccw(convex1[i], convex1[i + 1], convex2[j]) <= 0)
					break;
			}
			if (j != idx2) break;
		}
		if (i == idx1) {
			printf("NO\n");
			continue;
		}
		for (i = 0; i < idx2; i++) {
			for (j = 0; j < idx1; j++) {
				if (ccw(convex2[i], convex2[i + 1], convex1[j]) <= 0) 
					break;
			}
			if (j != idx1) break;
		}
		if (i == idx2) {
			printf("NO\n");
			continue;
		}

		bool flag = false;
		for (i = 0; i < idx1; i++) {
			for (j = 0; j < idx2; j++) {
				if (isCrossed(convex1[i], convex1[i + 1], convex2[j], convex2[j + 1])) {
					flag = true;
					break;
				}
			}
			if (flag)break;
		}
		if (flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}