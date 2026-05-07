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
#define ed "\n"
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
		bool unite(ll a, ll b){
			a = find(a);
			b = find(b);
			if(a == b) return false;
			if(sz[a] < sz[b]) swap(a, b);
			sz[a] += sz[b];
			parent[b] = a;
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
	ff(i, 0, m){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		st.unite(a, b);
	}
	unordered_set<ll> tipos;
	ll maxx = 0;
	ff(i, 0, n){
		tipos.insert(st.find(i));
		maxx = max(maxx, st.siz(i));
	}
	cout << "Existen " << tipos.size() << " posibles tipos"<< ed << "El tipo con mas Pokemon tiene " << maxx;
}
