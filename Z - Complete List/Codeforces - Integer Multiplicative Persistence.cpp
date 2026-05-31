//29 de Mayo 2026 15:03
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

const long double PI = acos(-1.0);

ll calc(ll n){
	ll c = 1;
	ll cur = n;
	while(cur > 0){
		ll dig = cur%10;
		c *= dig;
		cur /= 10;
	}
	return c;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll c = 0;
		while(n >= 10){
			//cout << n << ' ';
			c++;
			n = calc(n);
		}
		//cout << ed;
		cout << c << ed;
	}
	
}
