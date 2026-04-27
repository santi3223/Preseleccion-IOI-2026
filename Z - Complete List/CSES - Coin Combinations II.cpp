//22 de Abril 2026 10:43
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define pll pair<ll, ll>
#define fi first
#define se second
#define vb vector<bool>
#define pb push_back
#define vs vector<string>
constexpr ll MOD = 1e9+7;

int main(){
	ll n, x;
	cin >> n >> x;
	vl arr(n);
	ff(i, 0, n){
		cin >> arr[i];
	}
	vl dp(x+5, 0);
	dp[0] = 1;
	ff(j, 0, n){
		ff(i, 1, x+1){
			if(i-arr[j] < 0) continue;
			dp[i] += dp[i-arr[j]];
			if(dp[i] >= MOD) dp[i] %= MOD;
		}
	}
	/*ff(i, 0, dp.size()){
		cout << dp[i] << ' ';
	}
	cout << ed;*/
	cout << dp[x];
	
}
