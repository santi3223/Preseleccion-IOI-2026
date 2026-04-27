//23 de Enero 2026 14:03
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
	if(n == 1){
		cout << 0;
		return 0;
	}
	if(n == 2){
		cout << 2;
		return 0;
	}
	if(n == 3){
		cout << 4;
		return 0;
	}
	if(n == 4){
		cout << 6;
		return 0;
	}
	if(n == 5){
		cout << 8;
		return 0;
	}
	//start
	ll id = 0, maxx = 0, most = 0;
	ff(i, 1, 5){
		ll cur = i, c = 1;
		while(cur*5 < n){
			cur *= 5;
			c++;
		}
		if(cur > maxx){
			id = i;
			maxx = cur;
			most = c;
		}
		//cout << cur << " " << i << ed;
	}
	string str(most, '0');
	str[most-1] = (id*2)+'0';
	n -= maxx;
	
	while(n > 0){
		if(n <= 5){
			str[0] = ((n-1)*2)+'0';
			n = 0;
			break;
		}
		
		id = 0, maxx = 0, most = 0;
		ff(i, 1, 5){
			ll cur = i, c = 1;
			while(cur*5 < n){
				cur *= 5;
				c++;
			}
			if(cur > maxx){
				id = i;
				maxx = cur;
				most = c;
			}
			//cout << cur << " " << i << ed;
		}
		
		str[most-1] = (id*2)+'0';
		n -= maxx;
		
	}
	
	reverse(all(str));
	cout << str;
}

