//24 de Enero 2026 16:21
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define vb vector<bool>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define ed "\n"
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define fi first
#define se second
#define pll pair<ll, ll>

int main(){
	ll x;
	cin >> x;
	if(x > 0){
		ll p = x % 10;
		if(p == 0) p = 10;
		x += 10-p;
	}
	else{
		ll p = (x*(-1))%10;
		x += p;
	}
	cout << (ll)x/10;

}
