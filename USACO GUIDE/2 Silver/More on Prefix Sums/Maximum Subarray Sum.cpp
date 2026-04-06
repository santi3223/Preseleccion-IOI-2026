//2 de Abril 2026 14:24
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
	ll n;
	cin >> n;
	ll cur = 0, maxx = LLONG_MIN;
	ff(i, 0, n){
		ll x;
		cin >> x;
		cur += x;
		maxx = max(maxx, cur);
		if(cur < 0) cur = 0;
	}
	cout << maxx;
	
}
