#include<iostream>
using namespace std;
typedef long long ll;

int N, type, arr[21];
ll fac[21], K;
bool chk[21];

int main() {
	//freopen("input.txt","r",stdin);
	fac[0] = 1;
	for (int i = 1; i <= 20; i++)
		fac[i] = i * fac[i - 1];

	int cnt;
	cin >> N >> type;
	if (type == 1) {
		cin >> K;

		for (int i = 1; i <= N; i++) {
			cnt = 1;
			for (int n = 1; n <= N; n++) {
				if (chk[n]) continue;

				if (cnt*fac[N - i] >= K) {
					chk[n] = true;
					cout << n << " ";
					K -= (cnt - 1) * fac[N - i];
					break;
				}
				cnt++;
			}
		}

	}
	else {
		for (int i = 1; i <= N; i++)
			cin >> arr[i];

		K = 1;
		for (int i = 1; i <= N; i++) {
			cnt = 1;
			for (int n = 1; n <= N; n++) {
				if (chk[n]) continue;

				if (arr[i] == n) {
					chk[n] = true;
					K += (cnt - 1)*fac[N - i];
					break;
				}
				cnt++;
			}
		}
		cout << K;
	}
	return 0;
}