//15 de Marzo 2026 19:57
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
#define ld long double

int main(){
	ll n;
	cin >> n;
	vector<ld> arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	vector<vector<ld>> dp(n+5, vector<ld>(n+5, 0.0));
	dp[0][0] = 1.0;
	ff(i, 0, n){
		ff(j, 0, i+1){
			dp[i+1][j+1] += dp[i][j]*arr[i]; //heads
			dp[i+1][j] += dp[i][j]*(1.0-arr[i]); //tails
		}
	}
	ld ans = 0.0;
	ff(i, n/2+1, n+1){
		ans += dp[n][i];
	}
	cout << fixed << setprecision(10) << ans;
}
