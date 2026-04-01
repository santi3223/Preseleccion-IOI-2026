//7 de Febrero 2026 22:28
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>

int main(){
	ll n;
	cin >> n;
	vl a(n), b(n);
	ff(i, 0, n){
		cin >> a[i];
		a[i] *= (i+1)*(n-i);
	}
	ff(i, 0, n){
		cin >> b[i];
	}
	sort(all(a));
	sort(all(b));
	ll c = 0;
	ff(i, 0, n){
		c += a[i]*b[n-1-i];
	}
	cout << c;
}
