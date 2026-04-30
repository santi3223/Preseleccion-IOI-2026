//20 de Marzo 2026 18:54
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
	vector<vl> arr(n, vl(n));
	vl dp((1<<n)+5);
	ff(i, 0, n) ff(j, 0, n) cin >> arr[i][j];
	ff(mask, 0, (1<<n)){
		ll c = 0;
		ff(i, 0, n){
			ff(j, 0, n){
				if((mask >> i) % 2 != 0 && (mask>>j) % 2 != 0) c += arr[i][j];
			}
		}
		c /=2;
		dp[mask] = c;
		for(ll sub = mask; sub; sub = (sub-1)&mask){
			dp[mask] = max(dp[mask], dp[sub]+dp[sub^mask]);
		}
	}
	cout << dp[(1<<n)-1];
}
