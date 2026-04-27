//24 de Enero 2026 08:01
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
	ll c = 0;
	ff(i, 0, str.size()){
		if(str[i] == 'i' || str[i] == 'j') c++;
	}
	cout << c;
}
