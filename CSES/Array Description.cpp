//7 de Julio 2026 11:06
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
	ll n, m;
	cin >> n >> m;
	vector<vl> dp(n+5, vl(m+5, 0));
	ll prev;
	cin >> prev;
	if(prev == 0){
		ff(i, 1, m+1) dp[0][i] = 1;
	}
	else dp[0][prev] = 1;
	ll x;
	ff(i, 1, n){
		cin >> x;
		if(x == 0){
			ff(j, 1, m+1) dp[i][j] = dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1], dp[i][j] %= MOD;
		}
		else dp[i][x] = dp[i-1][x-1]+dp[i-1][x]+dp[i-1][x+1], dp[i][x] %= MOD;
	}
	ll c = 0;
	ff(i, 1, m+1) c += dp[n-1][i], c %= MOD;
	cout << c;
}
