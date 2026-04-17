//25 de Enero 2026 22:47
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
	ll n;
	string str;
	cin >> n >> str;
	string res = "abcdefghijklmnopqrstuvwxyz";
	ll q;
	cin>> q;
	while(q--){
		char x, y;
		cin >> x >> y;
		ff(i, 0, 26){
			if(res[i] == x) res[i] = y;
		}
	}
	ff(i, 0, n){
		cout << res[str[i]-'a'];
	}
		
}

