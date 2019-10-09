#include<iostream>
#include<vector>
using namespace std;
/*
	2019. 10. 09.
	백준 6603. 로또

	조합 (재귀 함수)
*/
vector<int> nums, ans;
int N;

void printAns(const vector<int>& nums, int idx, int cnt) {
	if (cnt == 6) {
		for (int n : ans)
			cout<<n<<" ";
		cout<<'\n';
		return;
	}
	if (idx == nums.size())
		return;
	ans.push_back(nums[idx]);
	printAns(nums, idx+1, cnt+1);
	ans.pop_back();
	printAns(nums, idx+1, cnt);
}

int main() {
	freopen("input.txt","r",stdin);
	while (true) {
		cin >> N;
		if (N == 0) break;
		nums.clear();
		for (int i = 0, n; i<N; i++) {
			cin>>n;
			nums.push_back(n);
		}
		printAns(nums,0,0);
		cout<<'\n';
	}
	
	return 0;
}