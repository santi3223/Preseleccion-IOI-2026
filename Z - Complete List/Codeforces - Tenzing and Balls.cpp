//10 de Abril 2026 23:03
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		vl arr(n+5), dp(n+5), buc(n+5, LLONG_MAX);
		dp[0] = 0;
		ff(i, 1, n+1){
			cin >> arr[i];
			dp[i] = min(dp[i-1]+1, buc[arr[i]]);
			buc[arr[i]] = min(buc[arr[i]], dp[i-1]);
		}
		cout << n-dp[n] << ed;
	}
}
