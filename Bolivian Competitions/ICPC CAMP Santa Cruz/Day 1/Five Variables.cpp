//25 de Mayo 2026 16:33
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
const ll MOD = 1e9+7;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n = 5;
	ll ok = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(x == 0) ok = i+1;
	}
	cout << ok;
}
