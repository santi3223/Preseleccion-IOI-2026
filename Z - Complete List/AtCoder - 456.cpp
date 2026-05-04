//2 de Mayo 2026 08:14
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
	ll n = 3;
	vector<vl>arr(n, vl(6));
	ff(i, 0, n){
		ff(j, 0, 6) cin >> arr[i][j];
	}
	vector<map<ll, ll>> mp(n);
	ff(i, 0, n){
		for(auto x : arr[i]) mp[i][x]++;
	}
	ll c = 0;
	c += 1LL*mp[0][4]*mp[1][5]*mp[2][6];
	c += 1LL*mp[0][4]*mp[1][6]*mp[2][5];
	c += 1LL*mp[0][5]*mp[1][4]*mp[2][6];
	c += 1LL*mp[0][5]*mp[1][6]*mp[2][4];
	c += 1LL*mp[0][6]*mp[1][4]*mp[2][5];
	c += 1LL*mp[0][6]*mp[1][5]*mp[2][4];
	long double q = (long double)c/216.0;
	cout << fixed << setprecision(10) << q;
}
