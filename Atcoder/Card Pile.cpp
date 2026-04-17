//25 de Enero 2026 20:53
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
	deque<ll> arr;
	ff(i, 0, 100){
		arr.push_back(0);
	}
	ll q;
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		if(x == 1){
			ll a;
			cin >> a;
			arr.pb(a);
		}
		else{
			ll a = arr.back();
			cout << a << ed;
			arr.pop_back();
		}
	}
	
		
}

