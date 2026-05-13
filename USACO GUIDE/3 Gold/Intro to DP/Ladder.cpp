//11 de Mayo 2026 22:31
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("ladder.in", "r", stdin);
	freopen("ladder.out", "w", stdout);
	ll n;
	cin >> n;
	vl arr(n), dp(n, 0);
	ff(i, 0, n) cin >> arr[i];
	dp[0] = arr[0];
	ff(i, 1, n){
		if(i == 1){
			dp[i] = max(dp[i-1]+arr[i], arr[i]);
			continue;
		}
		dp[i] = max(dp[i-1], dp[i-2])+arr[i];
	}
	cout << dp[n-1];
	
	
}
