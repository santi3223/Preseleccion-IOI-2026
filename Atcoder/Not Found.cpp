//26 de Enero 2026 09:32
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
	string str, a = "qwertyuiopasdfghjklzxcvbnm";
	cin >> str;
	map<char, ll> mp;
	ff(i, 0, str.size()){
		mp[str[i]]++;
	}
	ff(i, 0, a.size()){
		if(mp[a[i]] == 0){
			cout << a[i];
			return 0;
		}
	}
}
