#include<iostream>
#include<queue>
#include<vector>
using namespace std;
/*
	2019. 08. 01.
	백준 2056. 작업

	Topological sort (위상 정렬)
	 : indegree 값을 이용한 구현
*/
queue<int> Q;
int N, ind[10001], time[10001],tmp[10001];
vector<int> A[10001];

int main() {
	scanf("%d", &N);
	for (int i = 1,a,b,c; i <= N; i++) {
		scanf("%d%d", &a, &b);
		tmp[i] = time[i] = a;
		if (b != 0) {
			for (int j = 0; j < b; j++) {
				scanf("%d", &c);
				A[c].push_back(i);
				ind[i]++;
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (ind[i] == 0)
			Q.push(i);
	}

	int ans = 0;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		for (int i = 0; i < A[now].size(); i++) {
			int next = A[now][i];

			if (time[next] < tmp[next] + time[now])
				time[next] = tmp[next] + time[now];

			ind[next]--;
			if (ind[next] == 0)
				Q.push(next);
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (ans < time[i])
			ans = time[i];
	}

	printf("%d", ans);
	return 0;
}