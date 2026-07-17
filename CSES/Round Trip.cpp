//9 de Julio 2026 12:27
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
const ll MOD = 1e9+7;
 
vector<vl> conexiones;
vl par, ans;
vb vis;
bool found = 0;
ll ind = -1;
 
void dfs(ll cur, ll p){
	if(found) return;
	if(vis[cur]){
		ans.pb(cur);
		found = 1;
		ind = p;
		return;
	}
	vis[cur] = 1;
	par[cur] = p;
	for(auto x : conexiones[cur]){
		if(found) return;
		if(x != p) dfs(x, cur);
	}
}
 
int main(){
	ll n, m;
	cin >> n >> m;
	conexiones = vector<vl>(n);
	par = vl(n, 0);
	vis = vb(n, 0);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	ff(i, 0, n){
		if(found) break;
		if(!vis[i]){
			dfs(i, -1);
		}
	}
	if(!found){
		cout << "IMPOSSIBLE";
		return 0;
	}
	while(true){
		ans.pb(ind);
		if(ind == ans[0]) break;
		ind = par[ind];
	}
	cout << ans.size() << ed;
	for(auto x : ans) cout << x+1 << ' ';
	
}
