#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
	2019. 07. 31.
	���� 2252. �� �����

	Topological sort (���� ����)
	 : Indegree ���� �̿��� ����
*/
vector<int> A[32001];
int N, M, ind[32001];
queue<int> Q;
int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d", &N, &M);
	for (int i = 0,a,b; i < M; i++) {
		scanf("%d%d", &a, &b);
		A[a].push_back(b);
		ind[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0)
			Q.push(i);
	}
	while (!Q.empty()) {
		int n = Q.front();
		Q.pop();
		printf("%d ", n);
		for (int i = 0; i < A[n].size(); i++) {
			int next = A[n][i];
			ind[next]--;
			if (ind[next] == 0)
				Q.push(next);
		}
	}
	return 0;
}
