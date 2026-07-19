//15 de Julio 2026 22:05
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>
#define all(aaa) aaa.begin(), aaa.end()
#define rall(aaa) aaa.rbegin(), aaa.rend()
#define pll pair<ll, ll>
#define fi first
#define se second
#define ed "\n"
#define vb vector<bool>
#define vs vector<string>
#define ff(aa, bb, cc) for(ll aa = bb; aa < cc; aa++)
#define pb push_back

struct Big{
	vl a;
	Big(ll n){
		while(n > 0){
			a.pb(n%10);
			n /= 10;
		}
	}
	void add(Big &b){
		ll carry = 0;
		ll i = 0, j = 0;
		if(a.size() < b.a.size()) a.resize(b.a.size(), 0);
		while(i < a.size() || j < b.a.size()){
			ll x = (i < a.size() ? a[i] : 0);
			ll y = (j < b.a.size() ? b.a[j] : 0);
			ll cur = x+y+carry;
			a[i] = cur%10;
			carry = cur/10;
			i++;
			j++;
		}
		while(carry){
			a.pb(carry%10);
			carry /= 10;
		}
	}
	void mult(ll x){
		ll carry = 0;
		ll i = 0;
		while(i < a.size()){
			ll cur = a[i]*x+carry;
			a[i] = cur%10;
			carry = cur/10;
			i++;
		}
		while(carry){
			a.pb(carry%10);
			carry /= 10;
		}
	}
	string st(){
		string ans = "";
		for(ll i = a.size()-1; i >= 0; i--) ans += a[i]+'0';
		return ans;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	Big sum(1), cnt(1);
	ll n = s.size();
	ff(i, 0, n){
		//cout << i << ed;
		char c = s[i];
		if(c == 'L'){
			sum.mult(2);
		}
		else if(c == 'R'){
			sum.mult(2);
			sum.add(cnt);
		}
		else if(c == 'P') continue;
		else{
			sum.mult(5);
			sum.add(cnt);
			cnt.mult(3);
		}
	}
	cout << sum.st();
	
}
