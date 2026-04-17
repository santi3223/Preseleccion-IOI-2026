//25 de Enero 2026 17:46
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
	vl arr(n);
	ff(i, 0, n){
		ll p;
		cin >> p;
		p--;
		arr[p] = i;
	}
	ll q;
	cin >> q;
	while(q--){
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		if(arr[a] < arr[b]) cout << a+1;
		else cout << b+1;
		cout << ed;
	}
	
}
