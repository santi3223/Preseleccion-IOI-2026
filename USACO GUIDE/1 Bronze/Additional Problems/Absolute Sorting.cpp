//14 de Mayo 2026 23:14
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n);
		ff(i, 0, n) cin >> arr[i];
		ll minn = 0, maxx = 1e9;
		ff(i, 0, n-1){
			ll x = arr[i], y = arr[i+1];
			ll midl = (x+y)/2, midr = (x+y+1)/2;
			if(x < y) maxx = min(maxx, midl);
			if(x > y) minn = max(minn, midr);
		}
		if(minn <= maxx) cout << minn << ed;
		else cout << -1 << ed;
		
	}
	
}
