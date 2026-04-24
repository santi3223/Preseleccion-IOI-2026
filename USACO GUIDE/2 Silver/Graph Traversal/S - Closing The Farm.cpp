//23 de Abril 2026 21:59
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
			ll xr = find(x), yr = find(y);
			if(xr == yr) return false;
			if(sz[xr] < sz[yr]) swap(xr, yr);
			sz[xr] += sz[yr];
			parent[yr] = xr;
			return true;
		}
		ll siz(ll x){
			return sz[find(x)];
		}
};

int main(){
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	ll n, m;
	cin >> n >> m;
	vector<vl> conexiones(n);
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		conexiones[a].pb(b);
		conexiones[b].pb(a);
	}
	vl query(n);
	ff(i, 0, n) cin >> query[i];
	reverse(all(query));
	DisjointS st(n);
	vb open(n, 0);
	vl ans;
	ll beg = query[0]-1;
	ans.pb(1);
	ff(i, 0, n){
		query[i]--;
		open[query[i]] = true;
		if(i == 0) continue;
		for(auto &x : conexiones[query[i]]){
			if(!open[x]) continue;
			st.unite(query[i], x);
		}
		if(st.siz(beg) == i+1) ans.pb(1);
		else ans.pb(0);
	}
	reverse(all(ans));
	ff(i, 0, n){
		if(ans[i] == 1) cout << "YES";
		else cout << "NO";
		cout << ed;
	}
	
}
