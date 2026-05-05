//5 de Mayo 2026 19:30
#include <bits/stdc++.h>
using namespace std;
#define ll int
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

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	ll MAX = 1e5;
	vector<vb> dp(n+5, vb(MAX+5));
	dp[0][0] = true;
	ff(i, 1, n+1){
		ff(cur, 0, MAX+1){
			dp[i][cur] = dp[i-1][cur];
			ll prev = cur-arr[i-1];
			if(prev >= 0 && dp[i-1][prev]) dp[i][cur] = 1;
		}
	}
	vl pos;
	ff(i, 1, MAX+1) if(dp[n][i]) pos.pb(i);
	cout << pos.size() << ed;
	for(ll x : pos) cout << x << ' ';
}
