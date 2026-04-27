//22 de Abril 2026 16:48
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
			return x == parent[x] ? x : (parent[x] = find(parent[x]));
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
	ll n, m, q;
	cin >> n >> m >> q;
	vector<pair<ll, pll>> arr(m), Q(q);
	ff(i, 0, m){
		ll a, b, w;
		cin >> a >> b >> w;
		arr[i] = {w, {a, b}};
	}
	sort(rall(arr));
	ff(i, 0, q){
		ll a, w;
		cin >> a >> w;
		Q[i] = {w, {a, i}};
	}
	sort(rall(Q));
	ll j = 0;
	vl ans(q);
	DisjointS st(n);
	ff(i, 0, q){
		ll w = Q[i].fi;
		while(j < m && arr[j].fi >= w){
			st.unite(arr[j].se.fi, arr[j].se.se);
			j++;
		}
		ans[Q[i].se.se] = st.siz(Q[i].se.fi);
	}
	ff(i, 0, q){
		cout << ans[i] << ed;
	}
}
