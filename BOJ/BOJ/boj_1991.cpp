#include<iostream>
using namespace std;
/*
	2019. 09. 02.
	[BOJ] 백준 1991. 트리 순회
	
	트리
*/
int adj[26][2], N;

void preOrder(int n) {
	if (n+'A' == '.') return;
	cout<< (char)(n+'A');
	preOrder(adj[n][0]);
	preOrder(adj[n][1]);
}
void inOrder(int n) {
	if (n+'A' == '.') return;
	inOrder(adj[n][0]);
	cout<< (char)(n+'A');
	inOrder(adj[n][1]);
}
void postOrder(int n) {
	if (n+'A' == '.') return;
	postOrder(adj[n][0]);
	postOrder(adj[n][1]);
	cout<< (char)(n+'A');
}
int main() {
	cin >> N;
	for (int i = 0,n,l,r; i<N; i++) {
		char ch1, ch2, ch3;
		cin >> ch1 >> ch2 >> ch3;
		n = ch1-'A';
		l = ch2-'A';
		r = ch3-'A';
		adj[n][0] = l;
		adj[n][1] = r;
	}
	preOrder(0);
	cout<<"\n";
	inOrder(0);
	cout<<"\n";
	postOrder(0);

	return 0;
}