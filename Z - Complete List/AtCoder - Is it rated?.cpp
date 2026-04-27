//26 de Enero 2026 10:42
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
	ll r, x;
	cin >> r >> x;
	if(x == 1  && 1600 <= r && r <= 2999) cout<<"Yes";
	else if(x == 2 && 1200 <= r && r <= 2399) cout << "Yes";
	else cout << "No";
	
}
