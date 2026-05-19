//18 de Mayo 2026 22:41
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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll t;
	cin >> t;
	ll x, y;
	cin >> x >> y;
	ll mns, mxs, mnd, mxd;
	mns = mxs = x+y;
	mnd = mxd = x-y;
	cout << max(mxs-mns, mxd-mnd) << ed;
	ff(i, 1, t){
		cin >> x >> y;
		ll sum = x+y, dif = x-y;
		mns = min(mns, sum);
		mnd = min(mnd, dif);
		mxs = max(mxs, sum);
		mxd = max(mxd, dif);
		cout << max(mxs-mns, mxd-mnd) << ed;
		
	}
}
