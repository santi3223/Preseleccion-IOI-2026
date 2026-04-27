//22 de Enero 2026 21:28
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
	unsigned long long n, m;
	cin >> n >> m;
	bool ok = true;
	unsigned long long x = 0, cur = 1;
	ff(i, 0, m+1){
		if(x > 1e9){
			ok = false;
			break;
		}
		x += cur;
		cur*=n;
	}
	if(x > 1e9) ok = false;
	if(!ok) cout << "inf";
	else cout << x;
}
