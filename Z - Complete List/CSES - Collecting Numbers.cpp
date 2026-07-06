//4 de Julio 2026 15:00
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define pll pair<ll, ll>
#define ed "\n"
#define vb vector<bool>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define fi first
#define se second
 
int main(){
	ll n;
	cin >> n;
	vl pos(n);
	ff(i, 0, n){
		ll a;
		cin >> a;
		pos[a-1] = i;
	}
	ll c = 1;
	ff(i, 0, n-1){
		if(pos[i] > pos[i+1]) c++;
	}
	cout << c;
}
