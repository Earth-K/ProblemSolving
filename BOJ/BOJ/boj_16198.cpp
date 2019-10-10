#include<iostream>
#include<vector>
using namespace std;
int N,ans;
int solve(vector<int> &vt) {
	int sz = vt.size();
	if (sz==2)
		return 0;

	int ans = 0;
	for (int i=1; i<sz-1; i++) {
		int e = vt[i-1] * vt[i+1];
		vector<int> tmp(vt);
		tmp.erase(tmp.begin() + i);
		e = e + solve(tmp);
		if (ans < e)
			ans = e;
	}

	return ans;
}
int main() {
	freopen("input.txt","r",stdin);
	vector<int> vt;
	cin>>N;
	for (int i=0, n; i<N; i++) {
		cin>>n;
		vt.push_back(n);
	}
	cout<<solve(vt);
	return 0;
}