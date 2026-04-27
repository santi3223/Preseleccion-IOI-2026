//25 de Enero 2026 18:45
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
	string cur;
	cin >> str;
	ff(i, 0, str.size()){
		if(str[i] != 'W' && str[i] != 'A'){
			cout << cur;
			cout << str[i];
			cur = "";
			continue;
		}
		if(str[i] == 'W'){
			cur += 'W';
		}
		else{
			if(cur.size() > 0){
				string o(cur.size(), 'C');
				cur = "";
				cout << 'A' << o;
			}
			else{
				cout << 'A';
			}
		}
	}
	cout << cur;
	
	
}
