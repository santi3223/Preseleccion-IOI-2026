//16 de Marzo 2026 15:44
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
const ll MOD = 1e9+7;

int main(){
	ll n;
	cin >> n;
	vl arr(n);
	vector<vl> dp(n+5, vl(n+5, 0));
	ff(i, 0, n){
		cin >> arr[i];
		dp[i][i] = arr[i];
	}
	ff(len, 2, n+1){
		for(ll l = 0; l+len-1 < n; l++){
			ll r = l+len-1;
			dp[l][r] = max(arr[l]-dp[l+1][r], arr[r]-dp[l][r-1]);
		}
	}
	/*ff(i, 0, n){
		ff(j, 0, n) cout << dp[i][j] << " ";
		cout << ed;
	}*/
	cout << dp[0][n-1];
}
