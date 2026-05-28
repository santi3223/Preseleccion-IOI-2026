//27 de Mayo 2026 15:57
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
	vector<string> arr(n);
	vector<vl> dp(n, vl(n, 0));
	ff(i, 0, n) cin >> arr[i];
	if(arr[0][0] == '*'){
		cout << 0;
		return 0;
	}
	dp[0][0] = 1;
	ff(i, 0, n){
		ff(j, 0, n){
			if(arr[i][j] == '*') continue;
			ll up = 0, lef = 0;
			if(i-1 >= 0) up = dp[i-1][j];
			if(j-1 >= 0) lef = dp[i][j-1];
			dp[i][j] += up+lef;
			if(dp[i][j] >= MOD) dp[i][j] %= MOD;
		}
	}
	cout << dp[n-1][n-1];
}
