#include<iostream>
#include<vector>
using namespace std;
int N, min_ans, max_ans;
int opNum[4];
vector<int> nums, ops;

void calcAns(int res, int idx, int plus, int minus, int mul, int div) {
	int sz = ops.size();
	if (idx == sz) {
		if (max_ans<res) max_ans = res;
		if (min_ans>res) min_ans = res;
		return;
	}
	
	int a = res;
	int b = nums[idx+1];

	if(plus>0)	calcAns(a+b, idx+1, plus-1, minus, mul, div);
	if(minus>0) calcAns(a-b, idx+1, plus, minus-1, mul, div);
	if(mul>0)	calcAns(a*b, idx+1, plus, minus, mul-1, div);
	if(div>0)	calcAns(a/b, idx+1, plus, minus, mul, div-1);
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
	
	min_ans = 9876543210;
	max_ans = -min_ans;

	calcAns(nums[0],0,opNum[0],opNum[1],opNum[2],opNum[3]);

	cout<<max_ans<<'\n';
	cout<<min_ans<<'\n';

	return 0;
}