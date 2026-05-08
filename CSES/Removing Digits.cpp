//8 de Mayo 2026 18:40
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
	string s;
	cin >> s;
	ll start = stoll(s);
	vl dp(start+5, 1e18);
	dp[start] = 0;
	for(ll i = start; i > 0; i--){
		if(dp[i] == 1e18) continue;
		ll cur = i;
		while(cur > 0){
			ll dig = cur%10;
			cur /= 10;
			dp[i-dig] = min(dp[i-dig], dp[i]+1);
		}
	}
	/*for(ll i = start; i >= 0; i--){
		cout << dp[i] << ' ';
	}*/
	cout << dp[0];
}
