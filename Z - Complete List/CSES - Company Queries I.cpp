//4 de Mayo 2026 19:51
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
 
vector<vl> conexiones, ancestor;
 
void dfs(ll cur, ll par){
	ancestor[cur][0] = par;
	ff(i, 1, 20){
		if(ancestor[cur][i-1] == -1) continue;
		ancestor[cur][i] = ancestor[ancestor[cur][i-1]][i-1];
	}
	for(auto x : conexiones[cur]){
		if(x != par) dfs(x, cur);
	}
}
 
ll kancestor(ll x, ll k){
	ff(i, 0, 20){
		if(k & (1LL << i)){
			x = ancestor[x][i];
			if(x == -1) break;
		}
	}
	return x;
}
 
int main(){
	ll n, q;
	cin >> n >> q;
	conexiones = vector<vl>(n);
	ancestor = vector<vl>(n, vl(20, -1));
	ff(i, 1, n){
		ll a;
		cin >> a;
		a--;
		conexiones[a].pb(i);
		conexiones[i].pb(a);
	}
	dfs(0, -1);
	while(q--){
		ll a, k;
		cin >> a >> k;
		ll ans = kancestor(a-1, k);
		if(ans != -1) ans++;
		cout << ans << ed;
	}
}
