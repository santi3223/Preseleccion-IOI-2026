//23 de Enero 2026 14:11
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
	ll n;
	cin >> n;
	vl order(n, -1);
	ll x = 0;
	ff(i, 0, n){
		ll a;
		cin >> a;
		if(a == -1){
			x = i;
			continue;
		}
		else{
			a--;
			order[a] = i;
		}
	}
	while(true){
		cout << x+1 << " ";
		x = order[x];
		if(x == -1) return 0;
	}
}
