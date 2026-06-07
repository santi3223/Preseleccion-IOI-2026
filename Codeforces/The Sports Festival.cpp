//6 de Junio 2026 22:33
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
	ll n;
	cin >> n;
	vl arr(n);
	ff(i, 0, n) cin >> arr[i];
	sort(all(arr));
	vector<vl> dp(n, vl(n, 0));
	ff(sz, 2, n+1){
		ff(i, 0, n-sz+1){
			ll j = i+sz-1;
			dp[i][j] = arr[j]-arr[i]+min(dp[i+1][j], dp[i][j-1]);
		}
	}
	cout << dp[0][n-1];
}
