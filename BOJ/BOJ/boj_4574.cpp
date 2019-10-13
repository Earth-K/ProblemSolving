#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int map[10][10], N;
bool chk_r[10][10], chk_c[10][10], chk_sq[10][10], domino[10][10];
int dr[]={ 1,0 };
int dc[]={ 0,1 };

int sq(int r, int c) {
	return 3*(r/3) + (c/3);
}
bool boundChk(int r, int c) {
	return 0<=r && r<9 && 0<=c && c<9;
}
bool check(int r, int c, int num) {
	return !chk_r[r][num] && !chk_c[c][num] && !chk_sq[sq(r,c)][num];
}
bool go(int cnt) {
	if (cnt == 81) {
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++)
				cout<<map[i][j];
			cout<<'\n';
		}
		return true;
	}
	
	int r = cnt/9;
	int c = cnt%9;
	if (map[r][c] != 0) {
		return go(cnt+1);
	}
	else {
		for (int i=0; i<2; i++) 
		{
			int nr = r+dr[i];
			int nc = c+dc[i];
			if (!boundChk(nr, nc)) continue;
			if (map[nr][nc] != 0) continue;

			for (int j=1; j<=9; j++) {
				for (int k=1; k<=9; k++) {
					if (domino[j][k]) continue;
					if (j==k) continue;

					if (check(r, c, j) && check(nr, nc, k)) {
						chk_r[r][j] = chk_c[c][j] = chk_sq[sq(r,c)][j] = true;
						chk_r[nr][k] = chk_c[nc][k] = chk_sq[sq(nr,nc)][k] = true;
						domino[j][k] = domino[k][j] = true;
						map[r][c] = j;
						map[nr][nc] = k;

						if (go(cnt+1))
							return true;

						map[nr][nc] = 0;
						map[r][c] = 0;
						domino[j][k] = domino[k][j] = false;
						chk_r[nr][k] = chk_c[nc][k] = chk_sq[sq(nr,nc)][k] = false;
						chk_r[r][j] = chk_c[c][j] = chk_sq[sq(r,c)][j] = false;
					}
				}
			}
		}
	}

	return false;
}
int main() {
	int tc = 1;
	while (true) {
		memset(map, 0, sizeof(map));
		memset(chk_r, 0, sizeof(chk_r));
		memset(chk_c, 0, sizeof(chk_c));
		memset(chk_sq, 0, sizeof(chk_sq));
		memset(domino, 0, sizeof(domino));
		cin >> N;
		if (N==0) break;
		
		int n1, n2;
		int r1, c1, r2, c2;
		string s1, s2;
		for (int i=0; i<N; i++) {
			cin>>n1>>s1>>n2>>s2;
			r1 = s1[0]-'A', c1 = s1[1]-'1';
			r2 = s2[0]-'A', c2 = s2[1]-'1';
			map[r1][c1] = n1;
			map[r2][c2] = n2;
			domino[n1][n2] = domino[n2][n1] = true;
			chk_r[r1][n1] = chk_c[c1][n1] = chk_sq[sq(r1,c1)][n1] = true;
			chk_r[r2][n2] = chk_c[c2][n2] = chk_sq[sq(r2,c2)][n2] = true;
		}
		for (int i=1; i<=9; i++) {
			cin>>s1;
			r1 = s1[0]-'A', c1 = s1[1]-'1';
			map[r1][c1] = i;
			chk_r[r1][i] = chk_c[c1][i] = chk_sq[sq(r1,c1)][i] = true;
		}
		cout<<"Puzzle "<< tc++ <<'\n';
		go(0);
	}
	return 0;
}