#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
/*
	2019. 08. 23.
	백준 14003. 가장 긴 증가하는 부분 수열 5

	DP
*/
struct Obj {
	int idx, num;
};
int P[1000001], arr[1000001], N, idx;
vector<Obj> vt;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	idx = 0;
	vt.push_back({ idx,arr[0] });
	P[idx++] = arr[0];

	for (int i = 1; i < N; i++) {
		if (P[idx - 1] < arr[i]) {
			vt.push_back({ idx,arr[i] });
			P[idx++] = arr[i];
		}
		else {
			int tidx = lower_bound(P, P + idx, arr[i]) - P;
			P[tidx] = arr[i];
			vt.push_back({ tidx, arr[i] });
		}
	}

	stack<int> st;
	int targetIdx = idx-1;
	for (int i = vt.size() - 1; i >= 0; i--) {
		if (targetIdx == -1) break;
		if (vt[i].idx == targetIdx) {
			st.push(vt[i].num);
			targetIdx--;
		}
	}
	printf("%d\n", st.size());
	while (!st.empty()) {
		int num = st.top(); st.pop();
		printf("%d ", num);
	}
	return 0;
}