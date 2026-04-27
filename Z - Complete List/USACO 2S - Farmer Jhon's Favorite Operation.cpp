//11 de marzo 2026 18:18
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		vl arr(n);
		ff(i, 0, n){
			cin >> arr[i];
			arr[i] %= m;
		}
		sort(all(arr));
		vl b = arr;
		for(auto &x : arr){
			b.pb(x+m);
		}
		ll sz = b.size();
		vl c(sz+1, 0);
		ff(i, 0, sz){
			c[i+1] = c[i]+b[i];
		}
		ll minn = LLONG_MAX;
		ff(i, 0, n){
			ll val = c[i+n]-c[i+n-n/2]-c[i+n/2]+c[i];
			minn = min(minn, val);
		}
		cout << minn << ed;
	}
}
