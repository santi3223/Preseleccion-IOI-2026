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

vector<vector<pll>> conexiones;

int main(){
	ll n, m;
	cin >> n >> m;
	vector<pair<ll, pll>> arr;
	conexiones = vector<vector<pll>>(n);
	map<pll, ll> mp;
	ff(i, 0, m){
		ll a, b, c;
		cin >> a >> b >> c;
		if(a > b) swap(a, b);
		mp[{a, b}] = c;
		arr.pb({c, {a, b}});
		conexiones[a].pb({b, c});
		conexiones[b].pb({a, c});
	}
	sort(all(arr));
	bool sub1 = true;
	ll cc1 = 0, cc2 = 0;
	ff(i, 0, n){
		if(conexiones[i].size() > 2) sub1 = false;
		if(conexiones[i].size() == 1) cc1++;
		if(conexiones[i].size() == 2) cc2++;	
	}
	if(sub1){
		ll q;
		cin >> q;
		while(q--){
			ll a, b;
			cin >> a >> b;
			if(cc1 == 2){
				cout << -1 << ed;
			}
			else{
				cout << arr[m-1].fi << ed;
			}
		}
	}
	if(conexiones[0].size() == m && cc1 == m){
		ll q;
		cin >> q;
		while(q--){
			ll a, b;
			cin >> a >> b;
			if(a > b) swap(a, b);
			ll p = 0;
			if(arr[p].se.se == a || arr[p].se.se == b) p++;
			if(arr[p].se.se == a || arr[p].se.se == b) p++;
			cout << max({mp[{0, a}], mp[{0, b}], arr[p].fi}) << ed;
		}
	}
	
}
