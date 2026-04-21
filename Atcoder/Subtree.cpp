//20 de Marzo 2026 20:06
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

ll MOD;

vector<vl> conexiones;
vl parent, up, down;

void dfsd(ll cur){
	down[cur] = 1;
	for(auto &x : conexiones[cur]){
		if(x == parent[cur]) continue;
		parent[x] = cur;
		dfsd(x);
		down[cur] = (down[cur]*down[x]) % MOD;
	}
	down[cur] = (down[cur]+1) % MOD;
}

void dfsu(ll cur){
	ll deg = conexiones[cur].size();
	vl pref(deg, 1), suf(deg, 1);
	ff(i, 0, deg){
		ll x = conexiones[cur][i];
		ll val = (x == parent[cur]) ? 1 : down[x];
		pref[i] = val;
		if(i > 0) pref[i] = (pref[i]*pref[i-1])%MOD;
	}
	
	for(ll i = deg-1; i >= 0; i--){
		ll x = conexiones[cur][i];
		ll val = (x == parent[cur]) ? 1 : down[x];
		suf[i] = val;
		if(i < deg-1) suf[i] = (suf[i]*suf[i+1])%MOD;
	}
	
	ff(i, 0, deg){
		ll x = conexiones[cur][i];
		if(x == parent[cur]) continue;
		ll prod = up[cur];
		if(i > 0) prod = (prod*pref[i-1]) % MOD;
		if(i < deg-1) prod = (prod*suf[i+1]) % MOD;
		up[x] = (prod+1) % MOD;
		dfsu(x);
	}
}

int main(){
	ll n;
	cin >> n >> MOD;
	parent = vl(n+5);
	up = vl(n+5);
	down = vl(n+5);
	conexiones = vector<vl>(n+5);
	ff(i, 0, n-1){
		ll a, b;
		cin >> a >> b;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	parent[1] = 0;
	up[1] = 1;
	
	dfsd(1);
	dfsu(1);
	ff(i, 1, n+1){
		cout << ((down[i]-1+MOD)%MOD*up[i])%MOD << ed;
	}
}
