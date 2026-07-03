//2 de Julio 2026 19:29
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
const ll MOD = 1e9+7;
 
int main(){
	ll n;
	cin >> n;
	ll sz = n*(n+1)/2;
	if(sz % 2 != 0){
		cout << 0;
		return 0;
	}
	sz /= 2;
	vl dp(sz+5, 0);
	dp[0] = 1;
	for(ll i = n; i >= 1; i--){
		for(ll j = sz; j >= 0; j--){
			if(j-i >= 0){
				dp[j] += dp[j-i];
				if(dp[j] >= MOD) dp[j] %= MOD;
			}
		}
	}
	/*ff(i, 0, sz+1){
		cout << dp[i] << ' ';
	}
	cout << ed;*/
	cout << dp[sz]*500000004 % MOD;
	
}
