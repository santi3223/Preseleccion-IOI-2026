//17 de Marzo 2026 21:43
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
	ll n, k;
	cin >> n >> k;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	vl dp(k+5, 0), pref(k+5, 0);
	dp[0] = 1;
	
	ff(i, 0, n){
		pref[0] = dp[0];
		ff(j, 1, k+1){
			pref[j] = (pref[j-1]+dp[j])%MOD;
		}
		vl nw(k+5, 0);
		ff(j, 0, k+1){
			ll l = max(0LL, j-arr[i]), r = j;
			nw[j] = pref[r];
			if(l > 0) nw[j] = (nw[j]-pref[l-1]+MOD)%MOD;
		}
		dp = nw;
	}
	cout << dp[k];
}
