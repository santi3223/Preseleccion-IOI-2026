//24 de Enero 2026 08:10
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
	bool stop = true;
	ll vol = 0;
	ll q;
	cin >> q;
	while(q--){
		ll x;
		cin >> x;
		if(x == 1) vol++;
		else if(x == 2){
			if(vol >= 1) vol--;
		}
		else if(x == 3){
			stop = !stop;
		}
		//cout << x << "  " << !stop << " " << vol << ed;
		if(!stop && vol >= 3){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
		cout << ed;
	}
}
