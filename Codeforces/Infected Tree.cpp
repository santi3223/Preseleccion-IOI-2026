//11 de Abril 2026 23:06
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
#define ed "\n"

vector<vl> conexiones;
vl sz, dp;

void dfs1(ll cur, ll par){
	for(auto &x : conexiones[cur]){
		if(x != par){
			dfs1(x, cur);
			sz[cur] += sz[x];
		}
	}
	sz[cur]++;
}

void dfs(ll cur, ll par){
	ll s = 0;
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur);
		s += dp[x];
	}
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		dp[cur] = max(dp[cur], s-dp[x]+sz[x]-1);
	}
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		conexiones = vector<vl>(n);
		sz = vl(n, 0);
		dp = vl(n, 0);
		
		ff(i, 0, n-1){
			ll a, b;
			cin >> a >> b;
			a--;
			b--;
			conexiones[a].pb(b);
			conexiones[b].pb(a);
		}
		dfs1(0, -1);
		dfs(0, -1);
		cout << dp[0] << ed;
	}
}
