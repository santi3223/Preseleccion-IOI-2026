//11 de Marzo 2026 18:36
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

vl arr;
ll n;

pll solve(ll x){
	pll dp[n][2];
	dp[0][0] = {0, 0};
	dp[0][1] = {arr[0]-x, 1};
	ff(i, 1, n){
		dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
		dp[i][1] = max(pll(dp[i-1][0].fi+arr[i]-x, dp[i-1][0].se+1),
				       pll(dp[i-1][1].fi+arr[i], dp[i-1][1].se));
	}
	return max(dp[n-1][0], dp[n-1][1]);
}

int main(){
	ll k;
	cin >> n >> k;
	arr = vl(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	ll l = 0, r = 1e18;
	while(l < r){
		ll mid = (l+r+1)/2;
		if(solve(mid).se >= k){
			l = mid;
		}
		else{
			r = mid-1;
		}
	}
	cout << solve(l).fi+l*k;
}
