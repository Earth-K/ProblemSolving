#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*
	2019. 07. 26.
	���� 2252. �� �����

	Topological sort (���� ����)
	 : dfs�� ����
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
		dfs(n); // ��� ȣ��
	}
	// ����� �ܸ� ������ push
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