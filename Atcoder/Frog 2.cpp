//6 de Marzo 2026 20:38
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

int main(){
	ll n, k;
	cin >> n >> k;
	vl dp(n, LLONG_MAX), arr(n);
	dp[0] = 0;
	ff(i, 0, n){
		cin >> arr[i];
		ff(j, 1, k+1){
			if(i-j >= 0){
				dp[i] = min(dp[i], dp[i-j]+abs(arr[i-j]-arr[i]));
			}
		}
	}
	cout << dp[n-1];
	
}
