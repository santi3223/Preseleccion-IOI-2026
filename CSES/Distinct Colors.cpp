//30 de Abril 2026 12:17
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

vector<vl> conexiones;
vector<set<ll>> col;
vl ans;

void dfs(ll cur, ll par){
	for(auto &x : conexiones[cur]){
		if(x == par) continue;
		dfs(x, cur);
		if(col[x].size() > col[cur].size()){
			swap(col[x], col[cur]);
		}
		for(auto &c : col[x]) col[cur].insert(c);
	}
	ans[cur] = col[cur].size();
}

int main(){
	ll n;
	cin >> n;
	col.resize(n);
	ff(i, 0, n){
		ll x;
		cin >> x;
		col[i].insert(x);
	}
	conexiones = vector<vl>(n);
	ff(i, 0, n-1){
		ll a,b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	ans = vl(n);
	dfs(0, -1);
	ff(i, 0, n) cout << ans[i] << ' ';
}
