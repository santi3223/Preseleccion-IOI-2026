//25 de Enero 2026 21:46
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
	map<ll,ll> mp;
	set<ll> arr;
	ff(i, 0, 7){
		ll x;
		cin>> x;
		mp[x]++;
		arr.insert(x);
	}
	bool dos = false, tres = false;
	for(auto &x : arr){
		if(mp[x] >= 3 && !tres) tres = true;
		else if(mp[x] >= 2 && !dos) dos = true;
	}
	if(dos && tres) cout << "Yes";
	else cout << "No";
	
		
}
