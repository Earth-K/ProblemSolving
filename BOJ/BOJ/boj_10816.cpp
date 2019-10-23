#include<iostream>
#include<algorithm>
using namespace std;
int arr[500000], n, m;
int upperBound(int arr[], int num) {
	int l = 0, r = n-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (arr[mid] == num) {
			l = mid+1;
		}
		else if (arr[mid] < num) {
			l = mid+1;
		}
		else if (arr[mid] > num) {
			r = mid-1;
		}
	}
	return l;
}
int lowerBound(int arr[], int num) {
	int l = 0, r = n-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (arr[mid] == num) {
			r = mid-1;
		}
		else if (arr[mid] < num) {
			l = mid+1;
		}
		else if (arr[mid] > num) {
			r = mid-1;
		}
	}
	return l;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for (int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);

	cin>>m;
	for (int i=0, q; i<m; i++) {
		cin>>q; 
		cout<<upperBound(arr, q)-lowerBound(arr, q)<<" ";
	}
	return 0;
}