#include<iostream>
using namespace std;
/*
	2019. 07. 24.
	백준 1717. 집합의 표현
	disjoint-set
*/
int n, m, parent[1000001];
int _find(int n) {
	return parent[n] == n ? n : parent[n] = _find(parent[n]);
}
void _union(int a, int b) {
	int i = _find(a);
	int j = _find(b);
	if (i == j) return;

	parent[i] = j;
}
bool chk(int a, int b) {
	if (_find(a) == _find(b))
		return true;
	else
		return false;
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= n; i++)
		parent[i] = i;
	for (int i = 0, a, b, c; i < m; i++) {
		scanf("%d%d%d", &a,&b,&c);
		if (a == 0) {
			_union(b, c);
		}
		else {
			if (chk(b, c))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}

	return 0;
}