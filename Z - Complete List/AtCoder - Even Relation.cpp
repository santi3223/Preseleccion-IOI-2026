//9 de Abril 2026 16:41
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

vector<vector<pll>> conexiones;
vl ans;

void dfs(ll cur, ll par, ll sum){
	if(sum % 2 == 0) ans[cur] = 1;
	//cout << cur << ' ' << par << ' ' << sum << ed;
	for(auto x : conexiones[cur]){
		if(x.fi == par) continue;
		dfs(x.fi, cur, sum+x.se);
	}
}


int main(){
	ll n;
	cin >> n;
	conexiones.resize(n);
	ff(i, 0, n-1){
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		conexiones[a].pb({b, c});
		conexiones[b].pb({a, c});
	}
	ans = vl(n, 0);
	dfs(0, -1, 0);
	ff(i, 0, n) cout << ans[i] << ed;
	
	
}
