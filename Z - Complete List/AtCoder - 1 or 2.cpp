//9 de Abril 2026 18:21
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

struct UnionFind {
     vl par;
    
    UnionFind(ll n) : par (n, -1) {}
     void init (ll n){par.assign(n, -1);}
    
    ll root(ll x){
         if(par[x] < 0) return x;
         else return  par[x] = root (par[x]);
    }
    
    bool issame (ll x, ll y){
         return  root(x) == root(y);
    }
    
    bool merge (ll x, ll y){
        x = root(x); y = root(y);
         if(x == y) return false ;
         if(par[x] > par[y]) swap(x, y);
        par[x] += par[y];
         par[y] = x;
         return true;
    }
    
    ll size(ll x){
         return -par[root(x)];
    }
};

int main(){
	ll n, m;
	cin >> n >> m;
	UnionFind uf(n);
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		uf.merge(a, b);
	}
	set<ll> st;
	ff(i, 0, n) st.insert(uf.root(i));
	cout << st.size();
	
	
}
