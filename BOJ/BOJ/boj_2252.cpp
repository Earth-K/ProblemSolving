#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
	2019. 07. 26.
	백준 2252. 줄 세우기

	Topological sort (위상 정렬)
	 : dfs로 구현
*/

int N, M;
vector<int> v[32001];
bool visited[32001];
stack<int> s;

void dfs(int v_num) {
	if (visited[v_num])
		return;

	visited[v_num] = true;

	for (int i = 0; i < v[v_num].size(); i++) {
		int n = v[v_num][i];
		dfs(n); // 재귀 호출
	}
	// 연결된 단말 노드부터 push
	s.push(v_num);
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d%d", &N, &M);

	for (int i = 0, a, b; i < M; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b); // a->b
	}

	for (int i = N; i >= 1; i--)
		dfs(i);

	while (!s.empty()) {
		printf("%d ", s.top());
		s.pop();
	}

	return 0;
}