//23 de Mayo 2026 22:44
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

vector<vl> dp;
ll n;
string s;

ll calc(ll l, ll r){
	ll &res = dp[l][r];
	if(res != -1) return res;
	if(l > r) return res = 0;
	if(l == r) return res = 1;
	res = 1 + calc(l+1, r);
	ff(i, l+1, r+1){
		if(s[l] == s[i]){
			res = min(res, calc(l+1, i-1)+calc(i, r));
		}
	}
	return res;
}

int main(){
	cin >> n >> s;
	dp = vector<vl>(n, vl(n, -1));
	cout << calc(0, n-1);
}
