#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
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
};

int main(){
	ll n, m;
	cin >> n >> m;
	DisjointS st(n);
	while(m--){
		ll a, b;
		cin >> a >> b;
		st.unite(a-1, b-1);
	}
	unordered_set<ll> a;
	ff(i, 0, n) a.insert(st.find(i));
	cout << a.size()-1;
}
