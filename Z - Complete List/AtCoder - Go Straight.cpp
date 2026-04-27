//11 de Abril 2026 09:20
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>

int main(){
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	ll sti = -1, stj = -1;
	ff(i, 0, n){
		cin >> arr[i];
		ff(j, 0, m){
			if(sti == -1 && arr[i][j] == 'S'){
				sti = i; stj = j;
			}
			else if(sti != -1) break;
		}
	}
	queue<pair<ll, pll>> q;
	q.push({-1, {sti, stj}});
	vector<vector<array<bool, 5>>> vis(n, vector<array<bool, 5>>(m, {0, 0, 0, 0, 0}));
	vector<vector<array<tuple<ll,ll,ll,char>,5>>> par(n, vector<array<tuple<ll,ll,ll,char>,5>>(m));
	vis[sti][stj][0] = true;
	// N1, E2, S3, W4;
	bool ok = false;
	ll ci = -1, cj = -1, cdir = -1;
	while(!q.empty()){
		ll dir = q.front().fi, i = q.front().se.fi, j = q.front().se.se;
		q.pop();
		if(arr[i][j] == 'G'){ci = i; cj = j; cdir = dir; ok = true; break;}
		if(arr[i][j] == '#') continue;
		if(arr[i][j] == 'o'){
			if(dir == 1 && i-1 >= 0 && arr[i-1][j] != '#' && !vis[i-1][j][1]){
				vis[i-1][j][1] = 1; par[i-1][j][1] = {i, j, dir, 'U'};
				q.push({dir, {i-1, j}});
			}
			if(dir == 2 && j+1 < m && arr[i][j+1] != '#' && !vis[i][j+1][2]){
				vis[i][j+1][2] = 1; par[i][j+1][2] = {i, j, dir, 'R'};
				q.push({dir, {i, j+1}});
			}
			if(dir == 3 && i+1 < n && arr[i+1][j] != '#' && !vis[i+1][j][3]){
				vis[i+1][j][3] = 1; par[i+1][j][3] = {i, j, dir, 'D'};
				q.push({dir, {i+1, j}});
			}
			if(dir == 4 && j-1 >= 0 && arr[i][j-1] != '#' && !vis[i][j-1][4]){
				vis[i][j-1][4] = 1; par[i][j-1][4] = {i, j, dir, 'L'};
				q.push({dir, {i, j-1}});
			}
		}
		if(arr[i][j] == 'x'){
			if(dir != 1 && i-1 >= 0 && arr[i-1][j] != '#' && !vis[i-1][j][1]){
				vis[i-1][j][1] = 1; par[i-1][j][1] = {i, j, dir, 'U'};
				q.push({1, {i-1, j}});
			}
			if(dir != 2 && j+1 < m && arr[i][j+1] != '#' && !vis[i][j+1][2]){
				vis[i][j+1][2] = 1; par[i][j+1][2] = {i, j, dir, 'R'};
				q.push({2, {i, j+1}});
			}
			if(dir != 3 && i+1 < n && arr[i+1][j] != '#' && !vis[i+1][j][3]){
				vis[i+1][j][3] = 1; par[i+1][j][3] = {i, j, dir, 'D'};
				q.push({3, {i+1, j}});
			}
			if(dir != 4 && j-1 >= 0 && arr[i][j-1] != '#' && !vis[i][j-1][4]){
				vis[i][j-1][4] = 1; par[i][j-1][4] = {i, j, dir, 'L'};
				q.push({4, {i, j-1}});
			}
		}
		if(arr[i][j] == 'S' || arr[i][j] == '.'){
			if(i-1 >= 0 && arr[i-1][j] != '#' && !vis[i-1][j][1]){
				vis[i-1][j][1] = true; par[i-1][j][1] = {i,j,dir,'U'};
				q.push({1, {i-1, j}});
			}
			if(j+1 < m && arr[i][j+1] != '#' && !vis[i][j+1][2]){
				vis[i][j+1][2] = true; par[i][j+1][2] = {i,j,dir,'R'};
				q.push({2, {i, j+1}});
			}
			if(i+1 < n && arr[i+1][j] != '#' && !vis[i+1][j][3]){
				vis[i+1][j][3] = true; par[i+1][j][3] = {i,j,dir,'D'};
				q.push({3, {i+1, j}});
			}
			if(j-1 >= 0 && arr[i][j-1] != '#' && !vis[i][j-1][4]){
				vis[i][j-1][4] = true; par[i][j-1][4] = {i,j,dir,'L'};
				q.push({4, {i, j-1}});
			}
		}
	}
	if(!ok){cout << "No"; return 0;}
	cout << "Yes" << ed;
	string ord = "";
	while(ci != sti || cj != stj){
		auto [pi, pj, pd, mv] = par[ci][cj][cdir];
		ord += mv;
		ci = pi;
		cj = pj;
		cdir = pd;
	}
	reverse(all(ord));
	cout << ord;
	
}
