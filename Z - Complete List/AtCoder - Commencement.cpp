//23 de Enero 2026 12:20
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
	map<char, ll> mp;
	ff(i, 0, str.size()){
		mp[str[i]]++;
	}
	map<ll, ll> ocur;
	for(auto &x: mp){
		ocur[x.se]++;
	}
	for(auto &x : ocur){
		if(x.se == 2) continue;
		cout << "No";
		return 0;
	}
	cout << "Yes";
	
	
}
