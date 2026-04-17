//25 de Enero 2026 21:30
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
	cin >> n;
	string str(n, '-');
	if(n % 2 == 0){
		str[n/2] = '=';
		str[n/2-1] = '=';
	}
	else{
		str[n/2] = '=';
	}
	cout << str;
	
		
}
