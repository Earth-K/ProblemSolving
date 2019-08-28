#include<iostream>
using namespace std;
/*
	2019. 08. 28.
	[BOJ] น้มุ 15649. Nฐ๚ M (1)
	
	DFS
*/
int N, M;
int arr[8], ans[8];
bool chk[9];

void perm(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		if (chk[arr[i]]) continue;

		chk[arr[i]] = true;
		ans[idx] = arr[i];
		perm(idx+1);
		chk[arr[i]] = false;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	perm(0);
	return 0;
}