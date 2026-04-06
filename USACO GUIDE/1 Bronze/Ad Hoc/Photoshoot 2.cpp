//4 de Abril 2026 21:15
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
const ll MOD = 1e9+7;

int main(){
	ll n;
	cin >> n;
	vl a(n), b(n);
	ll c = 0, j = 0;
	ff(i, 0, n) cin >> a[i], a[i]--;
	ff(i, 0, n) cin >> b[i], b[i]--;
	vb move(n, 0);
	ff(i, 0, n){
		while(j < n && move[a[j]]) j++;
		if(a[j] == b[i]) j++;
		else{
			c++;
			move[b[i]] = 1;
		}
	}
	cout << c;
}
