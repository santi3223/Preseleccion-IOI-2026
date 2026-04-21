//15 de Marzo 2026 18:49
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
	ll n, m;
	cin >> n >> m;
	vector<vl> dp(n+5, vl(m+5, 0));
	vector<string> arr(n);
	dp[0][0] = 1;
	ff(i, 0, n){
		cin >> arr[i];
		ff(j, 0, m){
			if(i == 0 && j == 0) continue;
			ll a = 0, b = 0;
			if(i-1 >= 0 && arr[i-1][j] == '.'){
				a = dp[i-1][j];
			}
			if(j-1 >= 0 && arr[i][j-1] == '.'){
				b = dp[i][j-1];
			}
			dp[i][j] = a+b;
			if(dp[i][j] >= MOD){
				dp[i][j] %= MOD;
			}
		}
	}
	/*ff(i, 0, n){
		ff(j, 0, m){
			cout << dp[i][j] << " ";
		}
		cout << ed;
	}*/
	cout << dp[n-1][m-1];
}
