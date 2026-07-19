//19 de Julio 2026 00:13
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
const ll MOD = 1e9+7;

string print(__int128 x){
	if(x == 0) return "0";
	string s = "";
	while(x > 0){
		s += (x%10)+'0';
		x /= 10;
	}
	reverse(all(s));
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	cin >> n;
	vl a, b;
	ff(i, 0, n){
		ll x, y;
		cin >> x >> y;
		a.pb(x);
		b.pb(y);
	}
	sort(all(a));
	sort(all(b));
	__int128 c1 = 0, c2 = 0;
	ff(i, 1, n){
		c1 += (__int128)i*(n-i)*(a[i]-a[i-1]);
		c2 += (__int128)i*(n-i)*(b[i]-b[i-1]);
	}
	cout << print(c1+c2);
	
}
//1 2 2 3 4
//x 1 2 4 8

//1 1 2 4 5
//x 0 2 8 12
