#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
	2019. 08. 04.
	백준 4375. 단절점
*/
vector<int> a[100001];
int discovered[100001];
bool isCut[100001];
int cnt;
int V, E;

int dfs(int nowV, bool isRoot) {
	int ret, child = 0;
	discovered[nowV] = ++cnt;
	ret = discovered[nowV];

	for(int nextV : a[nowV]){
		if (!discovered[nextV]) { // 아직 방문하지 않은 정점인 경우
			child++;
			int df = dfs(nextV, false);
			if (!isRoot && df >= discovered[nowV])
				isCut[nowV] = true;
			ret = min(ret, df);
		}
		else { // 이미 방문된 정점인 경우
			ret = min(ret, discovered[nextV]);
		}
	}
	
	if (isRoot)
		isCut[nowV] = child >= 2;

	return ret;
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &V, &E);
	for (int i = 0,u,v; i < E; i++) {
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	for (int i = 1; i <= V; i++) {
		if (!discovered[i])
			dfs(i,true);
	}
	int ans = 0;
	for (int i = 1; i <= V; i++) {
		if (isCut[i])
			ans++;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= V; i++){
		if (isCut[i])
			printf("%d ", i);
	}
	return 0;
}