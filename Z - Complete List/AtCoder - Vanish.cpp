//25 de Abril 2026 8:19
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

int main(){
	ll n, k;
	cin >> n >> k;
	map<ll, ll> mp;
	ff(i, 0, n){
		ll x;
		cin >> x;
		mp[x] += x;
	}
	vl arr;
	for(auto &x : mp){
		arr.pb(x.se);
	}
	sort(rall(arr));
	ll c = 0;
	ll sz = arr.size();
	ff(i, 0, sz) c += arr[i];
	ff(i, 0, min(sz, k)){
		c -= arr[i];
	}
	cout << c;
}
