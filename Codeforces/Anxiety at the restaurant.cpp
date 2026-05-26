//25 de Mayo 2026 15:02
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define fi first
#define se second
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, m;
	cin >> n >> m;
	ll tot = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		tot += x;
	}
	ll tip = (tot+10-1)/10;
	tot += tip;
	ll cur = 0;
	ff(i, 0, m){
		ll x;
		cin >> x;
		cur += x;
	}
	//cout << cur << ' ' << tot << ed;
	if(cur >= tot) cout << "YES";
	else cout << "NO";
}
