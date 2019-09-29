#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
/*
	2019. 09. 29.
	백준 17471. 게리맨더링

	[삼성전자 상시 SW역량테스트-A형]
	DFS, 조합
*/
int N;
int arr[11], A[11][11];
bool visited[11];

int dfs(int v, vector<int>& perm, int type) {
	int cnt = 1;
	visited[v] = true;

	for (int i = 1; i<=N; i++) {
		if (perm[i-1] == type && A[v][i] == 1 && visited[i] == false)
			cnt += dfs(i, perm, type);
	}
	return cnt;
}

int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);
	for (int i = 1; i<=N; i++)
		scanf("%d", &arr[i]);

	for (int i = 1, n; i<=N; i++) {
		scanf("%d", &n);
		for (int j = 0, v; j<n; j++) {
			scanf("%d", &v);
			A[i][v] = 1;
		}
	}
	int ans = 987654321;
	for (int k = 1; k<= N-1; k++) {
		vector<int> perm(k, 0);
		for (int i=k+1; i<=N; i++)
			perm.push_back(1);

		do {
			int area0_idx = -1, area1_idx = -1;
			for (int i = 0; i<N; i++) {
				if (perm[i] == 0) area0_idx = i;
				else area1_idx = i;

				if (area0_idx != -1 && area1_idx != -1)
					break;
			}
			int a0_cnt, a1_cnt, res0, res1;
			a0_cnt = a1_cnt = res0 = res1 = 0;

			memset(visited, 0, sizeof(visited));
			a0_cnt = dfs(area0_idx+1, perm, 0);
			memset(visited, 0, sizeof(visited));
			a1_cnt = dfs(area1_idx+1, perm, 1);

			if (a0_cnt == k && a1_cnt == N-k) {
				for (int i=0; i<N; i++) {
					if (perm[i] == 0) res0 += arr[i+1];
					else res1+= arr[i+1];
				}

				int sub = abs(res0-res1);
				if (ans > sub)
					ans = sub;
			}
		} while (next_permutation(perm.begin(), perm.end()));
	}
	if (ans == 987654321)
		printf("%d", -1);
	else
		printf("%d", ans);
	return 0;
}