//25 de Enero 2026 21:17
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
	str = 'x'+str+'x';
	ll c = 0;
	ff(i, 1, str.size()-1){
		if(str[i] == 'i' && str[i+1] != 'o')c++;
		if(str[i] == 'o' && str[i-1] != 'i')c++;
	}
	cout << c;
	
		
}
