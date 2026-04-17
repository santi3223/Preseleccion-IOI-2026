//25 de Enero 2026 17:40
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
	string str;
	cin >> str;
	string x = str;
	sort(all(x));
	char a;
	ll n = str.size();
	if(x[0] != x[1] && x[1] == x[n-1]) a = x[0];
	else a = x[n-1];
	ff(i, 0, n){
		if(str[i] == a){
			cout << i+1;
			return 0;
		}
	}
	
}
