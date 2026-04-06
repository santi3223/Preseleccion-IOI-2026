//6 de Marzo 2026 23:53
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
#define vb vector<bool>

void calc(ll l, ll r, ll k){
	if(l == r){
		cout << "! " << l << endl;
		return;
	}
	ll m = (l+r)/2;
	cout << "? " << l << " " << m << endl;
	ll sum;
	cin >> sum;
	if((m - l + 1) - sum >= k){
		calc(l, m, k);
	}
	else{
		calc(m + 1, r, k - (m - l + 1) + sum);
	}
}

int main(){
	ll n, t, k;
	cin >> n >> t >> k;
	calc(1, n, k);
}
