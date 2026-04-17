//23 de Enero 2026 14:20
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

map<ll, ll> mem;

ll fun(ll x){
	if(x < 2) return 0;
	if(mem[x] != 0){
		return mem[x];
	}
	if(x % 2 == 0){
		ll a = fun(x/2);
		mem[x] = 2*a+x;
		return mem[x];
	}
	else{
		ll a = fun(x/2), b = fun(x/2+1);
		mem[x] = a+b+x;
		return mem[x];
		
	}
	
}

int main(){
	ll x;
	cin >> x;
	cout << fun(x);
}
