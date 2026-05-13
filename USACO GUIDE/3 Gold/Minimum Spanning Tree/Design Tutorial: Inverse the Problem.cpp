//12 de Mayo 2026 23:15
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
			return x == parent[x] ? x : (parent[x] = find(parent[x]));
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
};

vector<vl> dist, nwdist;
vector<vector<pll>> conexiones;

void dfs(ll cur, ll par, ll root, ll d){
	nwdist[root][cur] = d;
	for(auto x : conexiones[cur]){
		if(x.fi == par) continue;
		dfs(x.fi, cur, root, d+x.se);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	dist = vector<vl>(n, vl(n));
	ff(i, 0, n){
		ff(j, 0, n) cin >> dist[i][j];
	}
	ff(i, 0, n) 
		if(dist[i][i] != 0){
			cout << "NO";
			return 0;
		}
	
	vector<pair<ll, pll>> ms;
	ff(i, 0, n){
		ff(j, 0, n){
			ms.pb({dist[i][j], {i, j}});
			if((i != j && dist[i][j] == 0) || dist[i][j] != dist[j][i]){
				cout << "NO";
				return 0;
			}
		}
	}
	sort(all(ms));
	conexiones = vector<vector<pll>>(n);
	DisjointS st(n);
	for(auto [d, x] : ms){
		if(st.unite(x.fi, x.se)){
			conexiones[x.fi].pb({x.se, d});
			conexiones[x.se].pb({x.fi, d});
		}
	}
	nwdist = vector<vl>(n, vl(n));
	ff(i, 0, n){
		dfs(i, -1, i, 0);
	}
	if(nwdist == dist) cout << "YES";
	else cout << "NO";
	
}
