//8 de Julio 2026 21:58
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<pair<pll, ll>> arr(n);
	vl lis;
	ff(i, 0, n){
		ll a, b, c;
		cin >> a >> b >> c;
		arr[i] = {{a, b}, c};
		lis.pb(a);
		lis.pb(b);
	}
	sort(all(arr));
	sort(all(lis));
	lis.erase(unique(all(lis)), lis.end());
	ll sz = 0;
	for(auto &[x, c] : arr){
		x.fi = lower_bound(all(lis), x.fi)-lis.begin();
		x.se = lower_bound(all(lis), x.se)-lis.begin();
		sz = max({sz, x.fi, x.se});
		//cout << x.fi << ' ' << x.se << ' ' << c << ed;
	}
	vl dp(sz+5, 0);
	ll prev = 1;
	for(auto [x, c] : arr){
		while(prev < x.fi){
			dp[prev] = max(dp[prev], dp[prev-1]);
			prev++;
		}
		ll p = 0;
		if(x.fi-1 >= 0) p = dp[x.fi-1];
		dp[x.se] = max(dp[x.se], p+c);
	}
	ll maxx = 0;
	for(auto x : dp) maxx = max(maxx, x);
	cout << maxx;
	
}
