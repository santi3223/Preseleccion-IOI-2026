//27 de Enero 2026 20:04
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
ll MOD = 1e9;

int main(){
	char a, b, c;
	ll x;
	cin >> a >> b >> c >> x;
	if(a == 'A' && b == 'B'&& c == 'C' && 0 < x && x < 350 && x != 316) cout << "Yes";
	else cout << "No";
	
}
