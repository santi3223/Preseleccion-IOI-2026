//14 de Marzo 2026 08:11
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
	ll h, w, q;
	cin >> h >> w >> q;
	while(q--){
		ll o, x;
		cin >> o >> x;
		if(o == 1){
			cout << x*w;
			h -= x;
			
		}
		else{
			cout << x*h;
			w -= x;
		}
		cout << ed;
	}
	
}
