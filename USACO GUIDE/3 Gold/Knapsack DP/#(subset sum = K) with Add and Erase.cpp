//5 de Mayo 2026 20:50
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
ll MOD = 998244353;

int main(){
	ll q, k;
	cin >> q >> k;
	vl dp(k+5, 0);
	dp[0] = 1;
	while(q--){
		char o;
		ll x;
		cin >> o >> x;
		if(o == '+'){
			for(ll w = k; w >= x; w--){
				dp[w] += dp[w-x];
				dp[w] %= MOD;
			}
		}
		else{
			ff(w, x, k+1){
				dp[w] += MOD-dp[w-x];
				dp[w] %= MOD;
			}
		}

		cout << dp[k] << ed;
	}
}
