//29 de Abril 2026 20:28
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
	ll tot = 1;
	vl a = {1,1,1,1,1,1,1,1,1,1};
	ll id = 0;
	ll n;
	cin >> n;
	while(tot < n){
		tot /= a[id];
		a[id]++;
		tot *= a[id];
		id++;
		id %= 10;
	}
	string c(a[0], 'c'),o(a[1], 'o'),d(a[2], 'd'),e(a[3], 'e'),f(a[4], 'f'),o1(a[5], 'o'),r(a[6], 'r'),c1(a[7], 'c'),e1(a[8], 'e'),s(a[9], 's');
	cout <<c<<o<<d<<e<<f<<o1<<r<<c1<<e1<<s;
}
