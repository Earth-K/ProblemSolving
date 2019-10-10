#include<iostream>
#include<vector>
using namespace std;
int N;
int opNum[4];
vector<int> nums, ops;

pair<int,int> calcAns(int res, int idx, int plus, int minus, int mul, int div) {
	int sz = nums.size();
	if (idx == sz) {
		return make_pair(res,res);
	}

	int a = res;
	int b = nums[idx];

	vector<pair<int, int>> vt;

	if (plus>0)	vt.push_back(calcAns(a+b, idx+1, plus-1, minus, mul, div));
	if (minus>0)vt.push_back(calcAns(a-b, idx+1, plus, minus-1, mul, div));
	if (mul>0)	vt.push_back(calcAns(a*b, idx+1, plus, minus, mul-1, div));
	if (div>0)	vt.push_back(calcAns(a/b, idx+1, plus, minus, mul, div-1));

	pair<int, int> ans = vt[0];
	for (pair<int, int> p : vt) {
		if (ans.first < p.first) ans.first = p.first;
		if (ans.second > p.second) ans.second = p.second;
	}
	return ans;
}

int main() {
	//freopen("input.txt","r",stdin);
	cin>>N;
	for (int i = 0, n; i<N; i++) {
		cin>>n;
		nums.push_back(n);
	}
	for (int i=0, cnt; i<4; i++) {
		cin>>cnt;
		opNum[i] = cnt;
		for (int j=0; j<cnt; j++)
			ops.push_back(i);
	}

	pair<int, int> ans;
	ans = calcAns(nums[0], 1, opNum[0], opNum[1], opNum[2], opNum[3]);

	cout<<ans.first <<'\n';
	cout<<ans.second<<'\n';

	return 0;
}