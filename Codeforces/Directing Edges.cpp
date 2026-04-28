//27 de Abril 2026 22:58
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

vl topo;
vector<vl> conexiones;
vb visited;

void dfs(ll cur){
	visited[cur] = true;
	for(auto x : conexiones[cur]){
		if(!visited[x]) dfs(x);
	}
	topo.pb(cur);
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		conexiones = vector<vl>(n);
		visited = vb(n, 0);
		topo.clear();
		vector<pll> edges;
		ff(i, 0, m){
			ll k, a, b;
			cin >> k >> a >> b;
			a--, b--;
			if(k == 1) conexiones[a].pb(b);
			edges.pb({a, b});
		}
		ff(i, 0, n) if(!visited[i]) dfs(i);
		reverse(all(topo));
		vl tim(n);
		ff(i, 0, n) tim[topo[i]] = i;
		bool cycle = false;
		ff(i, 0, n) for(auto &x : conexiones[i]) if(tim[i] > tim[x]) cycle = true;
		if(cycle){ cout << "NO" << ed; continue;}
		cout << "YES" << ed;
		for(auto [a, b] : edges){
			if(tim[a] > tim[b]) swap(a, b);
			cout << a+1 << ' ' << b+1 << ed;
		}
	}
}
