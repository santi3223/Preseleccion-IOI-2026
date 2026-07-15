//14 de Julio 2026 23:59
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl a(n);
	ff(i, 0, n) cin >> a[i];
	vector<vl> dp(n, vl(2, 1e18));
	string prev = "", cur;
	ff(i, 0, n){
		cin >> cur;
		if(i == 0){
			dp[i][0] = 0;
			dp[i][1] = a[i];
		}
		else{
			string rp = prev;
			reverse(all(rp));
			if(prev <= cur && dp[i-1][0] != 1e18){
				dp[i][0] = dp[i-1][0];
			}
			if(rp <= cur && dp[i-1][1] != 1e18){
				dp[i][0] = min(dp[i][0], dp[i-1][1]);
			}
			string rc = cur;
			reverse(all(rc));
			if(prev <= rc && dp[i-1][0] != 1e18){
				dp[i][1] = dp[i-1][0]+a[i];
			}
			if(rp <= rc && dp[i-1][1] != 1e18){
				dp[i][1] = min(dp[i][1], dp[i-1][1]+a[i]);
			}
		}
		prev = cur;
	}
	ll minn = min(dp[n-1][0], dp[n-1][1]);
	if(minn >= 1e18) minn = -1;
	cout << minn;
	
}
