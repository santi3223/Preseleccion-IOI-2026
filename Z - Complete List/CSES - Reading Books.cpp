//4 de Julio 2026 22:06
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define pll pair<ll, ll>
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	ll s = 0, maxx = 0;
	ff(i, 0, n){
		ll x;
		cin >> x;
		s += x;
		maxx = max(maxx, x);
	}
	cout << max(s, maxx*2);
}
