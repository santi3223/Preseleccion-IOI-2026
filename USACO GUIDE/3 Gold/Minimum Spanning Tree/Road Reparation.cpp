//30 de Abril 2026 15:27
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
			x = find(x), y = find(y);
			if(x == y) return false;
			if(sz[x] < sz[y]) swap(x, y);
			sz[x] += sz[y];
			parent[y] = x;
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
		arr.pb({c, {a-1, b-1}});
	}
	sort(all(arr));
	ll ans = 0;
	DisjointS st(n);
	for(auto &[x, p] : arr){
		if(st.unite(p.fi, p.se)){
			ans += x;
		}
	}
	ff(i, 1, n){
		if(!st.connected(0, i)){
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
	cout << ans;
}
