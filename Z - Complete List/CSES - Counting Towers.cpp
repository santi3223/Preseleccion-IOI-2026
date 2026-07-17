//7 de Julio 2026 13:03
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
	ll t;
	cin >> t;
	ll N = 1e6;
	vector<vl> dp(N+5, vl(2, 0));
	dp[1][0] = 1;
	dp[1][1] = 1;
	ff(i, 2, N+1){
		dp[i][0] = ((dp[i-1][0]*4 % MOD) + dp[i-1][1])%MOD;
		dp[i][1] = ((dp[i-1][1]*2%MOD)+dp[i-1][0])%MOD;
	}
	while(t--){
		ll n;
		cin >> n;
		cout << (dp[n][0]+dp[n][1])%MOD << ed;
	}
}
