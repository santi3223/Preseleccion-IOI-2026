//27 de Mayo 2026 15:42
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

const ll MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl dp(1e6+5, 0);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 8;
	dp[5] = 16;
	dp[6] = 32;
	ff(i, 7, n+1){
		ff(j, 1, 7){
			dp[i] += dp[i-j];
			if(dp[i] >= MOD) dp[i] %= MOD;
		}
	}
	cout << dp[n];
	
}
