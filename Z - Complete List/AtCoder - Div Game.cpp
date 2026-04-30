//29 de Abril 2026 21:06
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
	ll c = 0;
	for(ll p = 2; p*p <= n; p++){
		ll ex = 0;
		while(n % p == 0){
			ex++;
			n /= p;
		}
		for(ll i = 1; ex-i >= 0;i++){
			ex -= i;
			c++;
		}
	}
	if(n > 1) c++;
	cout << c;
}
