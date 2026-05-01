//30 de Abril 2026 15:08
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
};

int main(){
	freopen("superbull.in", "r", stdin);
	freopen("superbull.out", "w", stdout);
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	vector<pair<ll, pll>> li;
	ff(i, 0, n){
		ff(j, i+1, n){
			//cout << arr[i] << ' ' << arr[j] << ' ' << (arr[i]^arr[j]) << ed;
			li.pb({(arr[i]^arr[j]), {i, j}});
		}
	}
	ll c = 0;
	sort(rall(li));
	DisjointS st(n);
	for(auto &[v, p] : li){
		if(st.unite(p.fi, p.se)){
			c += v;
		}
	}
	cout << c;
}
