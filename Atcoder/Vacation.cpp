//14 de Marzo 2026 15:55
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

int main(){
	
	ll n;
	cin >> n;
	vector<vl> arr(n);
	ff(i, 0, n){
		ll a, b, c;
		cin >> a >> b >> c;
		arr[i] = {a, b, c};
	}
	vector<vl> dp(n, vl(3, LLONG_MAX));
	dp[0][0] = arr[0][0];
	dp[0][1] = arr[0][1];
	dp[0][2] = arr[0][2];
	ff(i, 1, n){
		dp[i][0] = max(dp[i-1][1], dp[i-1][2])+arr[i][0];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2])+arr[i][1];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1])+arr[i][2];
		
	}
	
	cout << max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
	
	
}
