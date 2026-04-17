//11 de Abril 2026 08:05
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
#define ed "\n"
#define vs vector<string>

int main(){
	ll t,x;
	cin >> t >> x;
	ll saved;
	cin >> saved;
	cout << 0 << ' ' << saved << ed;
	ff(i, 1, t+1){
		ll p;
		cin >> p;
		if(abs(saved-p) >= x){
			saved = p;
			cout << i << ' ' << p << ed;
		}
	}
}
