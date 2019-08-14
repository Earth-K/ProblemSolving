#include<iostream>
#include<string>
using namespace std;
/*
	2019. 08. 15.
	백준 3830. 교수님은 기다리지 않는다

	디스조인트 셋
*/
int N, M, parent[100001];
long long diff[100001];

int Find(int n) {
	if (parent[n] != n) {
		int r = Find(parent[n]);
		diff[n] += diff[parent[n]];
		parent[n] = r;
	}
	return parent[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	
	while (1) {
		cin >> N >> M;
		if (N == 0 && M == 0)
			break;

		for (int i = 1; i <= N; i++) {
			parent[i] = i;
			diff[i] = 0;
		}

		for (int i = 0,a,b,w; i < M; i++) {
			int parA, parB;
			string type;
			cin >> type;
			if (type[0] == '!') {
				cin >> a >> b >> w;
				parA = Find(a);
				parB = Find(b);
				if (parA != parB) {
					diff[parB] = w + diff[a] - diff[b];
					parent[parB] = parA;
				}
			}
			else {
				cin >> a >> b;

				if (Find(a) != Find(b))
					cout<< "UNKNOWN" << "\n";
				else 
					cout<< diff[b] - diff[a] << "\n";
			}
		}
	}
	return 0;
}