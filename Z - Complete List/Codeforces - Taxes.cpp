//2 de Junio 2026 23:21
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

bool prime(ll n){
	for(ll i = 2; i*i <= n; i++){
		if(n % i == 0) return 0;
	}
	return 1;
}

int main(){
	ll n;
	cin >> n;
	if(prime(n)) cout << 1;
	else if(n % 2 == 0 || prime(n-2)) cout << 2;
	else cout << 3;
}
