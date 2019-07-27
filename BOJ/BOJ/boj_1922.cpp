#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
	2019. 07. 27.
	백준 1922. 네트워크 연결
	크루스칼 알고리즘 풀이
*/
struct Edge {
	int s, d, w;
};
struct comp {
	bool operator() (const Edge& a, const Edge& b) {
		return a.w > b.w;
	}
};
priority_queue<Edge,vector<Edge>, comp> pq;

int N,M;
vector<int> a[1001];

int parent[1001];
int _find(int n) {
	return parent[n] == n ? n : parent[n] = _find(parent[n]);
}
bool _union(int a, int b) {
	int i = _find(a);
	int j = _find(b);
	if (i == j)
		return false;

	parent[i] = j;
	return true;
}


int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &N,&M);
	for (int i = 0, s, d, w; i < M; i++) {
		scanf("%d%d%d", &s, &d, &w);
		pq.push({ s,d,w });
	}

	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int answer = 0;
	while (!pq.empty()) {
		Edge e = pq.top(); pq.pop();
		int a, b;
		a = e.s;
		b = e.d;
		if (!_union(a, b)) continue;

		answer += e.w;
	}
	printf("%d", answer);
	return 0;
}