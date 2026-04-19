#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
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
	ll n, m;
	cin >> n >> m;
	DisjointS st(n);
	ll q = n, maxx = 1;
	while(m--){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		if(st.unite(a, b)){
			q--;
			maxx = max(maxx, st.siz(a));
		}
		cout << q << ' ' << maxx << ed;
	}
}

