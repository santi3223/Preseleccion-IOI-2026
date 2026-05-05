//5 de Mayo 2026 17:04
#include <bits/stdc++.h>
using namespace std;
#define ll int
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
	ll n, W;
	cin >> n >> W;
	vl price(n), pages(n);
	ff(i, 0, n) cin >> price[i];
	ff(i, 0, n) cin >> pages[i];
	vl dp(W+5, 0);
	ff(i, 0, n){
		ll p = price[i];
		for(ll w = W; w >= p; w--){
			dp[w] = max(dp[w], dp[w-p]+pages[i]);
		}
	}
	cout << dp[W];
}
