//25 de Enero 2026 19:03
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
	map<ll, ll> last;
	ll minn = LLONG_MAX;
	ff(i, 0, n){
		ll x;
		cin >> x;
		if(last[x] != 0){
			minn = min(minn, (i+1)-last[x]);
		}
		last[x] = i+1;
	}
	if(minn == LLONG_MAX) minn = -2;
	cout << minn+1;
	
		
}
