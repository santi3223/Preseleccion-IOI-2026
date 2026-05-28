//27 de Mayo 2026 15:48
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
	string a, b;
	cin >> a >> b;
	ll n = a.size(), m = b.size();
	vector<vl> dp(n+1, vl(m+1, 0));
	ff(i, 0, n+1) dp[i][0] = i;
	ff(j, 0, m+1) dp[0][j] = j;
	ff(i, 1, n+1){
		ff(j, 1, m+1){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = min({dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1});
			}
		}
	}
	cout << dp[n][m];
}

