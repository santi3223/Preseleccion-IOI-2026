//22 de Marzo 2026 22:36
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

struct dsu{
	ll n;
	vl arr;
	dsu(ll n){
		this->n = n;
		arr = vl(n+1);
		ff(i, 0, n+1) arr[i] = i;
	}
	
	ll find(ll x){
		return(arr[x]==x?x:arr[x]=find(arr[x]));
	}
	
	void united(ll a, ll b){
		a = find(a);
		b = find(b);
		if(a == b) return;
		arr[a] = b;
		return;
	}
	
	bool confirm(ll a, ll b){
		a = find(a);
		b = find(b);
		if(a == b) return true;
		return false;
	}
};



int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m1, m2;
		cin >> n >> m1 >> m2;
		vector<pll> g;
		ff(i, 0, m1){
			ll a, b;
			cin >> a >> b;
			g.pb({a, b});
		}
		dsu d1(n+1), d2(n+1);
		ff(i, 0, m2){
			ll a, b;
			cin >> a >> b;
			d2.united(a, b);
		}
		ll c = 0;
		ff(i, 0, m1){
			if(d2.confirm(g[i].fi, g[i].se)) d1.united(g[i].fi, g[i].se);
			else c++;
		}
		ff(i, 1, n+1){
			ll par = d2.find(i);
			if(d1.confirm(par, i)) continue;
			else{
				c++;
				d1.united(par, i);
			}
		}
		cout << c << ed;
	}
}
