//8 de Mayo 2026 18:25
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), 	aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>
constexpr ll MOD = 1e9+7;

int main(){
	ll n, x;
	cin >> n >> x;
	vl arr(n), dp(1e6+5, 1e18);
	ff(i, 0, n) cin >> arr[i], dp[arr[i]] = 1;
	dp[0] = 1;
	ff(i, 1, x+1){
		for(auto c : arr){
			if(i-c < 0) continue;
			if(dp[i-c] == 1e18) continue;
			dp[i] = min(dp[i], dp[i-c]+1);
		}
	}
	/*ff(i, 0, x+1){
		cout << dp[i] << ' ';
	}
	cout << ed;*/
	if(dp[x] == 1e18) dp[x] = -1;
	cout << dp[x];
}
