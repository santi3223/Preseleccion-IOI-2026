//16 de Marzo 2026 10:38
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
	ff(i, 0, n){
		cin >> arr[i];
	}
	vb dp(k+5, false);
	ff(i, 0, k+1){
		for(auto &x : arr){
			if(i-x >= 0 && !dp[i-x]){
				dp[i] = true;
				break;
			}
		}
	}
	if(dp[k]) cout << "First";
	else cout << "Second";
}
