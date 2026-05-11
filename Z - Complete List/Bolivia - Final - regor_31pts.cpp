#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
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
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ll n;
string univ;
vl pos;
set<string> st;
vector<string> resultados;

vector<string> inter; //vl

string suma(string a, string b){
	string ok = "";
	//cout << "SUMA " << a << ' ' << b << ed;
	reverse(all(a));
	reverse(all(b));
	ll sz1 = a.size();
	ll sz2 = b.size();
	ll sz = max(sz1, sz2);
	ll carry = 0;
	ll i = 0;
	//cout << "SIZES " << i << ' ' << sz << ed;
	while(i < sz || carry > 0){
		//cout << "CYCLE " << i << ' ' << ok << ed;
		ll dig1 = 0, dig2 = 0;
		if(i < sz1){
			dig1 = a[i]-'0';
		}
		if(i < sz2){
			dig2 = b[i]-'0';
		}
		//cout << "DIG " << dig1 << ' ' << dig2 << ed;
		ll cur = dig1+dig2+carry;
		//cout << cur << ed;
		carry = 0;
		
		ll ans = cur % 10;
		carry += cur/10;
		ok += (ans+'0');
		i++;
	}
	reverse(all(ok));
	//cout << "RESULTA " << ok;
	return ok;
}

void calc(){
	string cur = "1";
	ff(i, 0, n){
		//cout << ed << univ[i] << ed;
		//cout << cur << ed;
		if(univ[i] == 'L'){
			cur = suma(cur, cur);
		}
			
		if(univ[i] == 'R'){
			cur = suma(cur, cur);
			string o = "1";
			cur = suma(cur, o);
		}
		if(univ[i] == 'P') continue;
	}
	//cout << cur << ed;
	resultados.pb(cur);
}

void brute(ll p){
	if(p == pos.size()){
		//cout << univ << ed;
		calc();
		return;
	}
	univ[pos[p]] = 'R';
	brute(p+1);
	univ[pos[p]] = 'L';
	brute(p+1);
	univ[pos[p]] = 'P';
	brute(p+1);
	
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string ord;
	cin >> ord;
	univ = ord;
	n = ord.size();
	ff(i, 0, n){
		if(ord[i] == '*') pos.pb(i);
	}
	//cout << "A" << ed;
	brute(0);
	//cout << "B" << ed;
	string ans = resultados[0];
	ff(i, 1, resultados.size()){
		ans = suma(ans, resultados[i]);
	}
	//cout << ed;
	cout << ans;
	
}
