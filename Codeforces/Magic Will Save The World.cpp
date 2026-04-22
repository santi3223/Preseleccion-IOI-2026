//21 de Abril 2026 22:45
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

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll w, f, n;
		cin >> w >> f >> n;
		vl arr(n);
		ll sum = 0;
		ff(i, 0, n){
			cin >> arr[i];
			sum += arr[i];
		}
		vb dp(sum+5, 0);
		dp[0] = 1;
		ff(i, 0, n){
			for(ll p = sum; p >= arr[i]; p--){
				dp[p] = dp[p] || dp[p-arr[i]];
			}
		}
		ll minn = 2e9;
		ff(i, 0, sum+5){
			if(!dp[i]) continue;
			minn = min(minn, max((i+w-1)/w, (sum-i+f-1)/f));
		}
		cout << minn << ed;
	}
	
}
