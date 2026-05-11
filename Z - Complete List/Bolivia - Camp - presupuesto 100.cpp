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
			ll xr = find(x);
			ll yr = find(y);
			if(xr == yr) return false;
			if(sz[xr] < sz[yr]) swap(xr, yr);
			sz[xr] += sz[yr];
			parent[yr] = xr;
			return true;
		}
		bool connected(ll x, ll y){
			return find(x) == find(y);
		}
};

int main(){
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, pll>> arr;
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr.pb({c, {a, b}});
	}
	sort(all(arr));
	ll coun = 0;
	DisjointS dis(n);
	ff(i, 0, n){
		ll x = arr[i].se.fi, y = arr[i].se.se;
		//cout << x+1 << ' ' << y+1;
		if(dis.unite(x, y)){
			//cout << " SI";
			coun += arr[i].fi;
		}
		//cout << ed;
	}
	ff(i, 0, n){
		if(!dis.connected(0, i)){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << coun;
}
