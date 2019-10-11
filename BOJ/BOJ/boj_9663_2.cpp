#include <iostream>
using namespace std;
bool a[15][15];
int n;
bool check_col[14];
//row+col�� ���� ��� ������ �̿�
bool check_dig[30];
//row-col �� ���� ��� ������ �̿�
bool check_dig2[30];

bool check(int row, int col) {
	// |
	if (check_col[col]) {
		return false;
	}
	// /
	if (check_dig[row+col]) {
		return false;
	}
	// ���� �� �밢��
	if (check_dig2[row-col+n-1]) {
		return false;
	}
	return true;
}
int calc(int row) {
	if (row == n) {
		// ans += 1;
		return 1;
	}
	int cnt = 0;
	for (int col=0; col<n; col++) {
		if (check(row, col)) {
			check_dig[row+col] = true;
			check_dig2[row-col+n-1] = true;
			check_col[col] = true;
			a[row][col] = true;
			cnt += calc(row+1);
			check_dig[row+col] = false;
			check_dig2[row-col+n-1] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return cnt;
}
int main() {
	cin >> n;
	cout << calc(0) << '\n';
	return 0;
}