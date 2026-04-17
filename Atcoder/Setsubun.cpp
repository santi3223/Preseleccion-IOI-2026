//31 de Enero 2026 08:10
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vb vector<bool>
#define pb push_back
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define vl vector<ll>
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
constexpr ll MOD = 1e9+7;
 
int main(){
	ll n, k;
	cin >> n >> k;
	ll c = 0, cur = 0;
	while(cur < k){
		cur += n;
		n++;
		c++;
	}
	cout << c-1;
}
