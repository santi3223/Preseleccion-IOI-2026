//4 de Abril 2026 22:12
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
const ll MOD = 1e9+7;

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n) cin >> arr[i];
		map<ll, vl> mp;
		ff(i, 0, n) mp[i-arr[i]].pb(arr[i]);
		
		ll c = 0;
		for(auto &cur : mp){
			sort(rall(cur.se));
			for(ll i = 0; i+1 < cur.se.size(); i += 2){
				ll w = cur.se[i]+cur.se[i+1];
				if(w > 0) c += w;
			}
		}
		cout << c << ed;
		
		
	}
}
