#include<iostream>
using namespace std;

bool chk[20*100000+10];
int N, arr[20];

int main() {
	//freopen("input.txt","r",stdin);
	cin>>N;
	for (int i=0; i<N; i++)
		cin>>arr[i];

	for (int i=0; i < (1<<N); i++) {
		int sum = 0;

		for (int j=0; j<N; j++) {
			if (i&(1<<j))
				sum += arr[j];
		}
		chk[sum] = true;
	}

	for (int i=1; ; i++) {
		if (chk[i] == false) {
			cout<<i;
			break;
		}
	}

	return 0;
}