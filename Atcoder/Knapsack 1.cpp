//14 de Marzo 2026 20:56
//DP contest
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
	
	ll n, W;
	cin >> n >> W;
	vl dp(W+5, 0);
	ff(i, 0, n){
		ll w, v;
		cin >> w >> v;
		for(ll x = W; x >= w; x--){
			dp[x] = max(dp[x], dp[x-w]+v);
		}
	}
	cout << *max_element(all(dp));
	
}
