#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int from[10001], dist[10001];
char how[10001];
bool chk[10001];

string getHow(int num) {
	string ret = "";
	if (from[num] == -1)
		return ret;
	ret += getHow(from[num]) + how[num];
	return ret;
}

void bfs(int start, int target) {
	memset(chk, 0, sizeof(chk));
	queue<int> Q;
	Q.push(start);

	dist[start] = 0;
	from[start] = -1;
	how[start] = ' ';
	chk[start] = true;
	while (!Q.empty()) {
		int now = Q.front();
		Q.pop();

		if (now == target) {
			string how = getHow(now);
			cout<<how<<endl;
			return;
		}

		// D
		int next = now*2 % 10000;
		if (chk[next] == false) {
			Q.push(next);
			chk[next] = true;
			from[next] = now;
			dist[next] = dist[now]+1;
			how[next] = 'D';
		}
		// S
		next = now-1;
		if (next<0) next = 9999;
		if (chk[next] == false) {
			Q.push(next);
			chk[next] = true;
			from[next] = now;
			dist[next] = dist[now]+1;
			how[next] = 'S';
		}
		// L
		next = (now%1000)*10 + (now/1000);
		if (chk[next] == false) {
			Q.push(next);
			chk[next] = true;
			from[next] = now;
			dist[next] = dist[now]+1;
			how[next] = 'L';
		}
		// R
		next = (now%10)*1000 + (now/10);
		if (chk[next] == false) {
			Q.push(next);
			chk[next] = true;
			from[next] = now;
			dist[next] = dist[now]+1;
			how[next] = 'R';
		}
	}
}

int main() {
	//freopen("input.txt","r",stdin);
	int T, start, end;
	cin>>T;
	while (T--) {
		cin>>start>>end;
		bfs(start, end);
	}
	return 0;
}