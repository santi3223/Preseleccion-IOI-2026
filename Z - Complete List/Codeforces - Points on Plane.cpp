//10 de Mayo 2026 23:22
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
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

bool cmp(pair<pll, ll> &a, pair<pll, ll> &b){
	return a.fi.fi < b.fi.fi || (a.fi.fi== b.fi.fi && (a.fi.fi % 2 == 0 ? (a.fi.se < b.fi.se) : (a.fi.se > b.fi.se)));
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vector<pair<pll, ll>> arr(n);
	ll R = 1000;
	ff(i, 0, n){
		cin >> arr[i].fi.fi >> arr[i].fi.se;
		arr[i].se = i;
		arr[i].fi.fi /= R;
	}
	sort(all(arr), cmp);
	for(auto x : arr){
		cout << x.se+1 << ' ';
	}
	
}
