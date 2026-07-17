//13 de Julio 2026 12:01
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
vl sz, heavy;
vb vis;
vector<vl> conexiones, rev;
ll n;
 
void check(ll cur){
	vis[cur] = 1;
	for(auto x : rev[cur]){
		if(!vis[x]) check(x);
	}
}
 
void dfs(ll cur){
	if(cur == n-1){
		sz[cur] = 1;
		return;
	}
	if(sz[cur] != -1){
		return;
	}
	if(!vis[cur]) return;
	sz[cur] = 0;
	for(auto x : conexiones[cur]){
		dfs(x);
		if(sz[x] > sz[cur]){
			heavy[cur] = x;
			sz[cur] = sz[x];
		}
	}
	sz[cur]++;	
}
 
int main(){
	ll m;
	cin >> n >> m;
	conexiones = vector<vl>(n);
	rev = conexiones;
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		rev[b].pb(a);
	}
	vis = vb(n, 0);
	sz = vl(n, -1);
	heavy = vl(n, -1);
	check(n-1);
	if(!vis[0]){
		cout << "IMPOSSIBLE";
		return 0;
	}
	dfs(0);
	vl ans;
	ll cur = 0;
	while(cur != -1){
		ans.pb(cur+1);
		cur = heavy[cur];
	}
	cout << ans.size() << ed;
	for(auto x : ans) cout << x << ' ';
}
