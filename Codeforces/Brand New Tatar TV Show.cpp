//12 de Junio 2026 23:17
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
const long double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		map<ll, ll> mp;
		ff(i, 0, n){
			ll x;
			cin >> x;
			mp[x]++;
			if(mp[x] >= 2) mp[x] -= 2;
		}
		bool ok = false;
		vl arr;
		for(auto x : mp){
			if(x.se == 0) ok = true;
			arr.pb(x.fi);
		}
		if(ok){
			cout << "YES" << ed;
			continue;
		}
		for(ll i = arr.size()-2; i >= 0; i--){
			if(arr[i+1]-arr[i] <= k){
				if(mp[arr[i+1]] == 1){
					ok = 1;
					break;
				 }
			}
		}
		if(ok) cout << "YES" << ed;
		else cout << "NO" << ed;
	}
}
