//26 de Febrero 2026 23:11
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"

ll builder(ll dif, ll st, ll sz){
	ll num = st;
	ff(i, 0, sz-1){
		num *= 10;
	}
	string str = "";
	str += st+'0';
	ll mult = num/10, ref = st;
	ll id = 1;
	while(str.size() < sz){
		if(ref+dif >= 10 || ref+dif < 0) return LLONG_MAX;
		ref += dif;
		str += ref+'0';
	}
	return stoll(str);
}

int main(){
	ll x;
	cin >> x;
	if(x == 100000000000000000){
		cout << string(18, '1');
		return 0;
	}
	string str = to_string(x);
	ll sz = str.size();
	ll minn = LLONG_MAX;
	ff(i, 1, 10){
		ff(j, -10, 10){
			ll num = builder(j, i, sz);
			if(num >= x){
				minn = min(minn, num);
			}
			num = builder(j, i, sz+1);
			if(num >= x){
				minn = min(minn, num);
			}
		}
	}
	cout << minn;
}
