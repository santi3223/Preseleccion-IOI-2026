#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back


int main(){
	ll n;
	cin >> n;
	vector<pll> arr;
	ff(i, 0, n){
		ll a,b;
		cin>>a>>b;
		arr.pb({a, b});
	}
	ll q;
	cin >> q;
	while(q--){
		ll l, r, W;
		cin >> l >> r >> W;
		l--;
		r--;
		vector<pll> prod;
		ff(i, l, r+1){
			prod.pb(arr[i]);
		}
		sort(all(prod));
		vl dp(W+5, 0);
		ff(i, 0, prod.size()){
			for(ll j = W; j >= prod[i].fi; j--){
				dp[j] = max(dp[j],dp[j-prod[i].fi]+prod[i].se);
			}
		}
		ll maxx = 0;
		ff(i, 0, W+2) cout << dp[i] << ' ';
		cout << ed;
		ff(i, 0, W+1){
			maxx = max(maxx, dp[i]);
		}
		cout << maxx << ed;
	}
}
