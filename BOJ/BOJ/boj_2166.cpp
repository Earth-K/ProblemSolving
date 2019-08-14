#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
/*
	2019. 08. 15.
	백준 2166. 다각형의 면적
	
	CCW
*/
typedef long long ll;
struct Point {
	ll x, y;
};

int N;
vector<Point> vt;
ll ccw(Point a, Point b, Point c) {
	ll res = a.x*b.y + b.x*c.y + c.x*a.y - a.x*c.y - c.x*b.y - b.x*a.y;
	return res;
}
int main() {
	//freopen("input.txt","r", stdin);
	scanf("%d", &N);
	vt.resize(N+1);
	for (int i = 0,x,y; i < N; i++) {
		scanf("%d%d", &x, &y);
		vt[i] = { x,y };
	} vt[N] = vt[0];

	Point p1 = { 0,0 };
	ll ans = 0;
	for (int i = 0; i <vt.size()-1 ; i++)
		ans += (double)ccw(p1, vt[i], vt[i + 1]);

	printf("%.1llf", fabs(ans/2.0));
	return 0;
}