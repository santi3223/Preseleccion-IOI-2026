//27 de Mayo 2026 15:14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	vl dp(n, 1e18), arr(n);
	dp[0] = 0;
	ff(i, 0, n){
		cin >> arr[i];
		ff(j, 1, k+1){
			if(i-j < 0) break;
			dp[i] = min(dp[i], dp[i-j]+abs(arr[i]-arr[i-j]));
		}
	}
	/*ff(i, 0, n){
		cout << dp[i] << ' ';
	}
	cout << ed;*/
	cout << dp[n-1];
}
