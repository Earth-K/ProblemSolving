#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
/*
	2019. 10. 08.
	백준 1339. 단어 수학

	순열
*/
vector<int> perm, alp;
int N, conv[256];
char str[10][9];

int getRes(const vector<int>& perm, const char str[10][9], vector<int>& alp) {
	int res = 0, ret = 0;
	for (int i=0; i<N; i++) {
		res = 0;
		for (int j=0; str[i][j]; j++)
			res = (res*10) + conv[str[i][j]];
		ret += res;
	}
	return ret;
}
int main() {
	//freopen("input.txt","r",stdin);
	scanf("%d", &N);
	int cnt = 0;
	for (int i=0; i<N; i++) {
		scanf("%s", str[i]);
		for (int j=0; str[i][j]; j++)
			alp.push_back(str[i][j]);
	}
	
	sort(alp.begin(), alp.end());
	alp.erase(unique(alp.begin(), alp.end()), alp.end());

	int sz = alp.size();
	for (int i=0; i<sz; i++)
		perm.push_back(9-i);

	int ans = 0;
	do {
		int res = 0;
		for (int i = 0; i<sz; i++)
			conv[alp[i]] = perm[i];

		res = getRes(perm, str, alp);
		if (ans < res)
			ans = res;
	} while (prev_permutation(perm.begin(), perm.end()));

	printf("%d\n", ans);
	return 0;
}