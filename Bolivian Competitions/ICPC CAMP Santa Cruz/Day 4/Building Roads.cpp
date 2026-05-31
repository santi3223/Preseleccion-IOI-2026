//28 de Mayo 2026 17:00
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

vb vis;
vector<vl> conexiones;

void dfs(ll cur){
	vis[cur] = 1;
	for(ll x : conexiones[cur]){
		if(!vis[x]) dfs(x);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	conexiones = vector<vl>(n);
	vis = vb(n, 0);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		conexiones[--a].pb(--b);
		conexiones[b].pb(a);
	}
	dfs(0);
	vector<pll> ans;
	ff(i, 0, n){
		if(!vis[i]){
			ans.pb({1, i+1});
			dfs(i);
		}
	}
	cout << ans.size() << ed;
	for(auto [a, b] : ans) cout << a << ' ' << b << ed;
	
}
