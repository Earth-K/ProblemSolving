#include<cstdio>

int arr[1000001], tmp[1000001];
int N;
long long ans;

void merge_sort(int s, int e) {
	if (s>=e) return;
	int mid = (s+e)>>1;
	
	merge_sort(s, mid);
	merge_sort(mid+1, e);
	int i=s, j=mid+1, k=s;

	while (i<=mid && j<=e) {
		if (arr[i] < arr[j])
			tmp[k++] = arr[i++];
		else {
			ans += (mid+1)-i;
			tmp[k++] = arr[j++];
		}
	}
	while (i<=mid) tmp[k++] = arr[i++];
	while (j<=e) tmp[k++] = arr[j++];

	for (int i=s; i<=e; i++) arr[i] = tmp[i];
}
int main() {
	scanf("%d", &N);
	for (int i = 0,n; i<N; i++) {
		scanf("%d",&n);
		arr[i] = n;
	}
	merge_sort(0,N-1);
	printf("%lld\n",ans);
	return 0;
}