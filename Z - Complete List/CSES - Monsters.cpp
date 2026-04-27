//5 de Abril 2026 23:48
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

int main() {
	ll n, m;
	cin >> n >> m;
	vector<string> arr(n);
	ff(i, 0, n) cin >> arr[i];
	queue<pll> q;
	vector<pll> ex, monst;
	vector<vl> dis(n, vl(m, LLONG_MAX));
	ff(i, 0, n){
		ff(j, 0, m){
			if(arr[i][j] == 'A'){ q.push({i, j}); dis[i][j] = 0;}
			if(arr[i][j] == 'M') monst.pb({i, j});
			if((i == 0 || i == n-1 || j == 0 || j == m-1) && arr[i][j] != '#') ex.pb({i, j});
		}
	}
	vl check(monst.size(), 0);
	vector<vb> vis(n, vb(m, 0));
	while(!q.empty()){
		ll a = q.front().fi;
		ll b = q.front().se;
		vis[a][b] = 1;
		q.pop();
		if(a-1 >= 0 && !vis[a-1][b] && arr[a-1][b] != '#'){ q.push({a-1, b}); vis[a-1][b] = 1; dis[a-1][b] = dis[a][b]+1;}
		if(b-1 >= 0 && !vis[a][b-1] && arr[a][b-1] != '#'){ q.push({a, b-1}); vis[a][b-1] = 1; dis[a][b-1] = dis[a][b]+1;}
		if(a+1 < n && !vis[a+1][b] && arr[a+1][b] != '#'){ q.push({a+1, b}); vis[a+1][b] = 1; dis[a+1][b] = dis[a][b]+1;}
		if(b+1 < m && !vis[a][b+1] && arr[a][b+1] != '#'){ q.push({a, b+1}); vis[a][b+1] = 1; dis[a][b+1] = dis[a][b]+1;}
	}
	
	
	vector<vl> monster_dis(n, vl(m, LLONG_MAX));
	for(auto &[i,j]: monst){
		q.push({i,j});
		monster_dis[i][j] = 0;
	}

	while(!q.empty()){
		auto [a,b] = q.front(); q.pop();
		for(auto [da,db] : vector<pll>{{1,0},{-1,0},{0,1},{0,-1}}){
			ll na=a+da, nb=b+db;
			if(na>=0 && na<n && nb>=0 && nb<m && arr[na][nb]!='#' && monster_dis[na][nb]==LLONG_MAX){
				monster_dis[na][nb] = monster_dis[a][b]+1;
				q.push({na,nb});
			}
		}
	}
	
	
	
	ll a = -1, b = -1;
	ff(p, 0, ex.size()){
		auto [i, j] = ex[p];
		if(monster_dis[i][j] > dis[i][j]){
			a = i;
			b = j;
			break;
		}
	}
	if(a == -1){ cout << "NO"; return 0;}
	cout << "YES" << ed << dis[a][b] << ed;
	string x = "";
	while(dis[a][b] != 0){
		if(a-1 >= 0 && dis[a-1][b] < dis[a][b]){
			x += 'D';
			a -= 1;
			continue;
		}
		if(a+1 < n && dis[a+1][b] < dis[a][b]){
			x += 'U';
			a += 1;
			continue;
		}
		if(b-1 >= 0 && dis[a][b-1] < dis[a][b]){
			x += 'R';
			b -= 1;
			continue;
		}
		if(b+1 < m && dis[a][b+1] < dis[a][b]){
			x += 'L';
			b += 1;
			continue;
		}
	}
	reverse(all(x));
	cout << x;
	
}
