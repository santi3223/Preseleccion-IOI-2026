//20 de Marzo 2026 14:30
//DP contest
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
#define ed endl
#define vs vector<string>
const ll MOD = 1e9+7;

vector<vl> conexiones;
vl dp0, dp1;

void dfs(ll cur, ll par){
	dp0[cur] = 1;
	dp1[cur] = 1;
	for(auto &x : conexiones[cur]){
		if(x != par){
			dfs(x, cur);
			dp0[cur] = (dp0[cur]*(dp0[x]+dp1[x])) % MOD;
		}
	}
	for(auto &x : conexiones[cur]){
		if(x != par){
			dp1[cur] = (dp1[cur]*dp0[x])%MOD;
		}
	}
}

int main(){
	ll n;	
	cin >> n;
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
		
	}
	dp0 = vl(n+5);
	dp1 = vl(n+5);
	dfs(0, -1);
	cout << (dp0[0]+dp1[0])%MOD;
	
}
