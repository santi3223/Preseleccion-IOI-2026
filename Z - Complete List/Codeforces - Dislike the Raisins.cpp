//31 de Mayo 2026 16:23
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


int main(){
	ll t;
	cin >> t;
	while(t--){
		ll c, r, s;
		cin >> c >> r >> s;
		ll nr = r%s;
		ll nc = c;
		if(nr != 0) nc -= s-nr;
		cout << (nc+s-1)/s << ' ';
		c -= r*(s-1);
		cout << max(0LL, (c+s-1)/s) << ed;
	}
	
}
