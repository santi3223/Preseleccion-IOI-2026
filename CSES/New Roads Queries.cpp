//24 de Mayo 2026 23:31
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

struct DisjointS{
	private:
		vl parent, sz;
	public:
		DisjointS(ll n): parent(n), sz(n, 1){
			ff(i, 0, n) parent[i] = i;
		}
		ll find(ll x){
			return parent[x] == x ? x : (parent[x] = find(parent[x]));
		}
		bool unite(ll x, ll y){
			x = find(x);
			y = find(y);
			if(x == y) return false;
			if(sz[x] < sz[y]) swap(x, y);
			sz[x] += sz[y];
			parent[y] = x;
			return true;
		}
		bool same(ll x, ll y){
			return find(x) == find(y);
		}
};

const ll LOG = 20;
vector<vl> ancestor, val;
vector<vector<pll>> conexiones;
vl dep;
ll maxx = 0;

void dfs(ll cur, ll par){
	ancestor[cur][0] = par;
	ff(i, 1, LOG){
		if(ancestor[cur][i-1] != -1){
			ancestor[cur][i] = ancestor[ancestor[cur][i-1]][i-1];
			val[cur][i] = max(val[cur][i-1], val[ancestor[cur][i-1]][i-1]);
		}
		else break;
	}
	for(auto [x, w] : conexiones[cur]){
		if(x != par){
			val[x][0] = w;
			dep[x] = dep[cur]+1;
			dfs(x, cur);
		}
	}
}

ll kanc(ll a, ll k){
	ff(i, 0, LOG){
		if(k & (1LL << i)){
			maxx = max(maxx, val[a][i]);
			a = ancestor[a][i];
		}
		if(a == -1) break;
	}
	return a;
}

void lca(ll a, ll b){
	if(dep[a] < dep[b]) swap(a, b);
	ll dif = dep[a]-dep[b];
	a = kanc(a, dif);
	if(a == b) return;
	for(ll i = LOG-1; i >= 0; i--){
		if(ancestor[a][i] != ancestor[b][i]){
			maxx = max(maxx, val[a][i]);
			maxx = max(maxx, val[b][i]);
			a = ancestor[a][i];
			b = ancestor[b][i];
		}
	}
	maxx = max(maxx, val[a][0]);
	maxx = max(maxx, val[b][0]);
	//return ancestor[a][0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	vector<pair<ll, pll>> prev;
	conexiones = vector<vector<pll>>(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		prev.pb({i, {--a, --b}});
	}
	sort(all(prev));
	DisjointS dsu(n);
	for(auto [a, b] : prev){
		if(dsu.unite(b.fi, b.se)){
			conexiones[b.fi].pb({b.se, a});
			conexiones[b.se].pb({b.fi, a});
		}
	}
	ancestor = vector<vl>(n, vl(LOG, -1));
	val = vector<vl>(n, vl(LOG, 0));
	dep = vl(n, -1);
	ff(i, 0, n){
		if(dep[i] == -1){
			dep[i] = 0;
			dfs(i, -1);
		}
	}
	while(q--){
		ll a, b;
		cin >> a >> b;
		--a;
		--b;
		if(!dsu.same(a, b)){
			cout << -1 << ed;
			continue;
		}
		maxx = -1;
		lca(a, b);
		cout << maxx+1 << ed;
	}
}
