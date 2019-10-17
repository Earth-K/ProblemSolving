#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_N 5
using namespace std;
struct Obj {
	int num;
	bool chk;
};
int dr[]={ -1,0,1,0 };
int dc[]={ 0,1,0,-1 };

vector<int> gen(int k) {
	vector<int> ret(MAX_N);
	for (int i=0; i<MAX_N; i++) {
		ret[i] = (k&3);
		k >>= 2;
	}
	return ret;
}
int move(vector<vector<int>> map, const vector<int>& dirs) {
	int n = map.size();
	vector<vector<Obj>> d(n, vector<Obj>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			d[i][j].num = map[i][j];
			d[i][j].chk = false;
		}
	}
	for (int dir : dirs) {
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
				d[i][j].chk = false;

		while (true) {
			bool moved = false;
			if (dir == 0) { // up
				for (int c=0; c<n; c++) {
					for (int r=0; r<=n-2; r++) {
						if (d[r][c].num == 0 && d[r+1][c].num != 0) {
							swap(d[r][c], d[r+1][c]);
							moved = true;
						}
						else if (d[r][c].num == d[r+1][c].num) {
							if (!d[r][c].chk && !d[r+1][c].chk) {
								d[r][c].num *= 2;
								d[r][c].chk = true;
								d[r+1][c].num = 0;
								moved = true;
							}
						}
					}
				}
			}
			else if (dir == 1) { // right
				for (int r=0; r<n; r++) {
					for (int c=n-1; c>0; c--) {
						if (d[r][c].num == 0 && d[r][c-1].num != 0) {
							swap(d[r][c], d[r][c-1]);
							moved = true;
						}
						else if (d[r][c].num == d[r][c-1].num) {
							if (!d[r][c].chk && !d[r][c-1].chk) {
								d[r][c].num *= 2;
								d[r][c].chk = true;
								d[r][c-1].num = 0;
								moved = true;
							}
						}
					}
				}
			}
			else if (dir == 2) { // down
				for (int c=0; c<n; c++) {
					for (int r=n-1; r>0; r--) {
						if (d[r][c].num == 0 && d[r-1][c].num != 0) {
							swap(d[r][c], d[r-1][c]);
							moved = true;
						}
						else if (d[r][c].num == d[r-1][c].num) {
							if (!d[r][c].chk && !d[r-1][c].chk) {
								d[r][c].num *= 2;
								d[r][c].chk = true;
								d[r-1][c].num = 0;
								moved = true;
							}
						}
					}
				}
			}
			else { // left
				for (int r=0; r<n; r++) {
					for (int c=0; c<=n-2; c++) {
						if (d[r][c].num == 0 && d[r][c+1].num != 0) {
							swap(d[r][c], d[r][c+1]);
							moved = true;
						}
						else if (d[r][c].num == d[r][c+1].num) {
							if (!d[r][c].chk && !d[r][c+1].chk) {
								d[r][c].num *= 2;
								d[r][c].chk = true;
								d[r][c+1].num = 0;
								moved = true;
							}
						}
					}
				}
			}
			if (moved == false) 
				break;
		}
	}

	int ret=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (ret < d[i][j].num) 
				ret = d[i][j].num;
		}
	}
	return ret;
}
int main() {
	//freopen("input.txt","r",stdin);
	int n;
	cin >> n;
	vector<vector<int>> map(n, vector<int>(n));
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin>>map[i][j];
		}
	}

	int ans = 0;
	for (int k=0; k<(1<<(MAX_N * 2)); k++) {
		vector<int> dirs = gen(k);
		int res = move(map, dirs);
		if (ans < res) ans = res;
	}
	cout<<ans<<endl;
	return 0;
}