//21 de Abril 2026 12:49
//DP contest
//resubmission
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>

int main(){
	ll n;
	cin >> n;
	vl arr(n), dp(n+5, LLONG_MAX);
	ff(i, 0, n){
		cin >> arr[i];
	}
	dp[0] = 0;
	ff(i, 1, n){
		dp[i] = min(dp[i], dp[i-1]+abs(arr[i]-arr[i-1]));
		if(i >= 2) dp[i] = min(dp[i], dp[i-2]+abs(arr[i]-arr[i-2]));
	}
	cout << dp[n-1];
}
