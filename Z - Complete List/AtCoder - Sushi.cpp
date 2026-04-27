//6 de Marzo 2026 18:54
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
#define ed "\n"
#define vb vector<bool>

ll n;
vector<vector<vector<long double>>> dp;

long double fun(ll a, ll b, ll c){
	if(dp[a][b][c] >= 0) return dp[a][b][c];
	if(a == b && b == c && c == 0) return 0.0;
	long double ans = 0.0;
	if(a > 0) ans += fun(a-1, b, c)*a;
	if(b > 0) ans += fun(a+1, b-1, c)*b;
	if(c > 0) ans += fun(a, b+1, c-1)*c;
	ans += n;
	ans *= 1.0/(a+b+c);
	return dp[a][b][c] = ans;
}

int main(){
	cin >> n;
	ll a = 0, b = 0, c = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(x == 1) a++;
		else if(x == 2) b++;
		else c++;
	}
	dp = vector<vector<vector<long double>>>(n+5, vector<vector<long double>>(n+5, vector<long double>(n+5, -1.0)));
	cout << fixed << setprecision(10) << fun(a, b, c);
}
