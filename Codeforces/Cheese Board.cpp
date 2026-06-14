//13 de Junio 2026 23:53
#include <bits/stdc++.h>
using namespace std;
#define ll int
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

int main(){
	ll n;
	cin >> n;
	ll a = 0, b = 0;
	ff(i, 0, n){
		string x, y;
		cin >> x >> y;
		if(y == "soft") a++;
		else b++;
	}
	if(a > b) swap(a, b);
	ff(i, 1, n+1){
		if(i % 2 == 0){
			if(i*i/2 >= a && i*i/2 >= b){
				cout << i;
				return 0;
			}
		}
		else{
			if(i*i/2 >= a && i*i/2+1 >= b){
				cout << i;
				return 0;
			}
		}
	}
	
}
