//23 de Enero 2026 12:36
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
	string a, b;
	cin >> a >> b;
	map<char, ll> mp;
	ff(i, 0, a.size()){
		mp[toupper(a[i])]++;
	}
	bool ok = true;
	ll id = 0;
	ff(i, 0, a.size()){
		if(toupper(a[i]) == b[id]){
			id++;
		}
	}
	if(id == 3) ok = true;
	else ok = false;
	if(id== 2 && b[2] == 'X') ok = true;
	
	if(ok) cout << "Yes";
	else cout << "No";
	
	
}
