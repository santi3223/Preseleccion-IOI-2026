//27 de Enero 2026 22:25
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
ll MOD = 1e9;

map<ll, long double> mp;
ll a, x, y;

long double f(ll n){
	if(mp.count(n)) return mp[n];
	mp[n] = min(x+f(n/a), (6*y+f(n/2)+f(n/3)+f(n/4)+f(n/5)+f(n/6))/5);
	return mp[n];
}

int main(){
	mp[0] = 0;
	ll n;
	cin >> n >> a >> x >> y;
	cout << fixed << setprecision(6) << f(n);
	
}
