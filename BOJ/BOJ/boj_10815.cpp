#include<iostream>
#include<algorithm>
using namespace std;
int arr[500000];
int n, m;

int bs(int arr[], int num) {
	int left, right, mid;
	left = 0, right = n-1;

	while (left<=right) {
		mid = (left+right)>>1;

		if (arr[mid] == num) {
			return 1;
		}
		else if (arr[mid] > num) {
			right = mid-1;
		}
		else if (arr[mid] < num) {
			left = mid+1;
		}
	}
	return 0;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("input.txt","r",stdin);
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);

	cin>>m;
	for (int i=0, q; i<m; i++) {
		cin>>q;
		cout<<bs(arr, q)<<" ";
	}

	return 0;
}