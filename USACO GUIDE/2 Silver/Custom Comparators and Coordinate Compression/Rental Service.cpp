//30 de Junio 2026 17:55
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	
	ll n, m, r;
	cin >> n >> m >> r;
	vl arr(n);
	ll c1 = 0, c2 = 0;
	ff(i, 0, n) cin >> arr[i], c1 += arr[i];
	sort(all(arr));
	
	vector<pll> store(m);
	ff(i, 0, m) cin >> store[i].se >> store[i].fi;
	sort(rall(store));
	vector<pll> aux;
	ff(i, 0, m){
		c2 += store[i].se;
		if(c2 > c1){
			ll nw = store[i].se-(c2-c1);
			if(nw > 0) aux.pb({store[i].fi, nw});
			break;
		}
		aux.pb({store[i].fi, store[i].se});
	}
	store = aux;
	m = store.size();
	
	//c2 = min(c1, c2);
	vl buy(r);
	ff(i, 0, r) cin >> buy[i];
	sort(rall(buy));
	
	vl value(n, 0);
	ll id = 0;
	for(ll i = n-1; i >= 0; i--){
		if(i != n-1) value[i] += value[i+1];
		ll c = 0, q = arr[i];
		while(id < m && q > 0){
			if(store[id].se > q){
				c += q*store[id].fi;
				store[id].se -= q;
				break;
			}
			else{
				q -= store[id].se;
				c += store[id].se*store[id].fi;
			}
			id++;
		}
		value[i] += c;
	}
	
	
	ll cur = 0, maxx = 0;
	id = 0;
	ff(i, 0, n+1){
		ll v = 0;
		if(i < n) v = value[i];
		maxx = max(maxx, cur+v);
		if(id >= r) break;
		cur += buy[id];
		id++;
	}
	cout << maxx;
	
}
