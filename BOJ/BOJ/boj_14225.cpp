#include<iostream>
#include<vector>
using namespace std;
/*
	2019. 10. 09.
	백준 14225. 부분수열의 합

	재귀함수
*/
int N;
vector<int> arr;
bool chk[2000005];

void fillChk(int idx, int sum) {
	if (idx == N) {
		chk[sum] = true;
		return;
	}
	fillChk(idx+1, sum+arr[idx]);
	fillChk(idx+1, sum);
}

int main() {
	//freopen("input.txt","r",stdin);
	cin>>N;
	for (int i = 0,n; i < N; i++) {
		cin>>n;
		arr.push_back(n);
	}

	fillChk(0,0);

	int ans = 0;
	for (int i = 1; i<=2000000; i++) {
		if (chk[i]==false) {
			ans = i;
			break;
		}
	}

	cout<<ans;
	return 0;
}