//8 de Julio 2026 20:11
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
const ll MOD = 1e9+7;
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl a(n);
	vector<vl> dp(n+1, vl(n+1, -1));
	ll s = 0;
	ff(i, 0, n) cin >> a[i], s += a[i];
	ff(i, 0, n) dp[i][i] = a[i];
	ff(len, 1, n){
		ff(i, 0, n-len+1){
			dp[i][i+len] = max(a[i]-dp[i+1][i+len], a[i+len]-dp[i][i+len-1]);
		}
	}
	ll x = dp[0][n-1];
	cout << (s+x)/2;
}
