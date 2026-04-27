//25 de Enero 2026 21:14
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
	ll a, b;
	char x;
	cin >> a >> x >> b;
	if(a >= 38) cout << 1;
	else if(a <= 37){
		if(a == 37 && b >= 5){
			cout << 2;
		}
		else cout <<3;
	}
	
		
}
