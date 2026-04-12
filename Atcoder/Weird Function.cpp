//26 de Febrero 2026 21:33
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
#define ed "\n"

ll f(ll x){
	return x*x+2*x+3;
}

int main(){
	ll t;
	cin >> t;
	cout << f(f(f(t)+t)+f(f(t)));
}
