#include<iostream>
#include<vector>
#include<string>
using namespace std;

int learn[26];

int count(vector<int> &words, int mask) {
	int cnt = 0;
	for (int word : words) {
		if ((word & (1<<26)-1-mask) == 0)
			cnt++;
	}
	return cnt;
}

int go(int idx, int k, int mask, vector<int> &words) {
	if (k<0) return 0;
	if (idx==26)
		return count(words, mask);

	int ans = 0, res;

	learn[idx] = true;
	res = go(idx+1, k-1, mask|(1<<idx), words);
	learn[idx] = false;
	if (ans < res) ans = res;

	if (idx != 'a'-'a' && idx != 'n'-'a' && idx != 't'-'a' &&
		idx != 'i'-'a' && idx != 'c'-'a') {
		res = go(idx+1, k, mask, words);
		if (ans < res) ans = res;
	}
	return ans;
}
int main() {
	int N, K;
	//freopen("input.txt","r",stdin);
	cin>>N>>K;
	vector<int> words(N);
	for (int i=0; i<N; i++) {
		string word;
		cin >> word;
		for (char ch : word)
			words[i] |= (1<<ch-'a');
	}
	cout<<go(0, K, 0, words)<<endl;
	return 0;
}