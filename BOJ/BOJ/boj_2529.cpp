#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
/*
	2019. 10. 08.
	백준 2529. 부등호

	순열, 문자-숫자 매핑
*/
int k, op[10], arr[11];
vector<int> big, small;

void check(const vector<int>& perm, int& cnt) {
	cnt = 0;
	for (int i = 0; i<k; i++) {
		if (op[i] == 1)
			cnt += perm[i] < perm[i+1];
		else
			cnt += perm[i] > perm[i+1];
	}
}
int main() {
	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		char ch[2];
		scanf("%s", ch);
		if (ch[0] == '<')  op[i] = 1;
		else  op[i] = 2;
	}
	
	for (int i = 0; i<k+1; i++) {
		big.push_back(9-i);
		small.push_back(i);
	}
	
	int cnt;
	do {
		check(big, cnt);
		if (cnt == k) 
			break;
	} while (prev_permutation(big.begin(), big.end()));

	do {
		check(small, cnt);
		if (cnt == k)
			break;
	} while (next_permutation(small.begin(), small.end()));
	
	for (int i=0; i<k+1; i++)
		printf("%d", big[i]);
	printf("\n");

	for (int i=0; i<k+1; i++)
		printf("%d", small[i]);
	printf("\n");

	return 0;
}