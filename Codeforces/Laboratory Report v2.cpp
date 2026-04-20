//5 de Abril 2026 21:47
//Decimals version
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
#define vb vector<bool>
#define ed "\n"
#define vs vector<string>
#define vld vector<long double>

unordered_map<string, string> unit;
string minn = "---------------------------------------------------------------------------";
string eqq = "================================================================================";
string med = "Test                      Result  Unit            Flag                     ";



unordered_map<string, vector<pair<ll, pair<vld, string>>>> flag;
/*  test                 1         2     3
1: type from the function type
2: limits
3: if inside the limits, the answer
*/


/* TYPE
 operation val 
    <      1   A
    <=     2   A
    >      3   A
    >=     4   A
   [] ~    5   AB
    [)     6   AB
    (]     7   AB
    ()     8   AB
*/

pair<ll, vld> type(string S){
	string s = "";
	ff(i, 0, S.size()){
		if(S[i] == ' ') continue;
		s += S[i];
	}
	bool les = false, mor = false, eq = false, lin = false;
	bool sqop = false, sqcl = false, paop = false, pacl = false;
	ll n = s.size();
	ff(i, 0, n){
		if(s[i] == '[') sqop = true;
		if(s[i] == ']') sqcl = true;
		if(s[i] == '(') paop = true;
		if(s[i] == ')') pacl = true;
		if(s[i] == '>') mor = true;
		if(s[i] == '<') les = true;
		if(s[i] == '=') eq = true;
		if(s[i] == '~') lin = true;
	}
	if(les){
		if(eq){
			string x = "";
			ff(i, 2, n){
				x += s[i];
			}
			long double a = stod(x);
			vld ar = {a};
			return {2, ar};
		}
		else{
			string x = "";
			ff(i, 1, n){
				x += s[i];
			}
			long double a = stod(x);
			vld ar = {a};
			return {1, ar};
		}
	}
	if(mor){
		if(eq){
			string x = "";
			ff(i, 2, n){
				x += s[i];
			}
			long double a = stod(x);
			vld ar = {a};
			return {4, ar};
		}
		else{
			string x = "";
			ff(i, 1, n){
				x += s[i];
			}
			long double a = stod(x);
			vld ar = {a};
			return {3, ar};
		}
	}
	if(lin){
		string cur = "";
		long double a, b;
		ll id = 0;
		ff(i, 0, n) if(s[i] == '~'){ id = i; break;}
		ff(i, 0, id){
			cur += s[i];
		}
		a = stod(cur);
		cur = "";
		ff(i, id+1, n){
			cur += s[i];
		}
		b = stod(cur);
		vld ar = {a, b};
		return {5, ar};
	}
	if(sqop && sqcl){
		string cur = "";
		long double a, b;
		ll id = 0;
		ff(i, 0, n) if(s[i] == ','){ id = i; break;}
		ff(i, 1, id){
			cur += s[i];
		}
		a = stod(cur);
		cur = "";
		ff(i, id+1, n-1){
			cur += s[i];
		}
		b = stod(cur);
		vector<long double> ar = {a, b};
		return {5, ar};
	}
	if(sqop && pacl){
		string cur = "";
		long double a, b;
		ll id = 0;
		ff(i, 0, n) if(s[i] == ','){ id = i; break;}
		ff(i, 1, id){
			cur += s[i];
		}
		a = stod(cur);
		cur = "";
		ff(i, id+1, n-1){
			cur += s[i];
		}
		b = stod(cur);
		vld ar = {a, b};
		return {6, ar};
	}
	if(paop && sqcl){
		string cur = "";
		long double a, b;
		ll id = 0;
		ff(i, 0, n) if(s[i] == ','){ id = i; break;}
		ff(i, 1, id){
			cur += s[i];
		}
		a = stod(cur);
		cur = "";
		ff(i, id+1, n-1){
			cur += s[i];
		}
		b = stod(cur);
		vld ar = {a, b};
		return {7, ar};
	}
	if(paop && pacl){
		string cur = "";
		long double a, b;
		ll id = 0;
		ff(i, 0, n) if(s[i] == ','){ id = i; break;}
		ff(i, 1, id){
			cur += s[i];
		}
		a = stod(cur);
		cur = "";
		ff(i, id+1, n-1){
			cur += s[i];
		}
		b = stod(cur);
		vld ar = {a, b};
		return {8, ar};
	}
}

string bars = "///////////////////////////////////////////////////////////////////////////";

string calc(string id, long double val){
	string ret = "Abnormal";
	for(auto &[type, b] : flag[id]){
		vld limits = b.fi;
		string ans = b.se;
		long double A = limits[0];
		if(1 <= type && type <= 4){
			if(type == 1 && val < A){
				ret = ans;
				break;
			}
			if(type == 2 && val <= A){
				ret = ans;
				break;
			}
			if(type == 3 && val > A){
				ret = ans;
				break;
			}
			if(type == 4 && val >= A){
				ret = ans;
				break;
			}
		}
		long double B = limits[1];
		if(type == 5 && A <= val && val <= B){
			ret = ans;
			break;
		}
		if(type == 6 && A <= val && val < B){
			ret = ans;
			break;
		}
		if(type == 7 && A < val && val <= B){
			ret = ans;
			break;
		}
		if(type == 8 && A < val && val < B){
			ret = ans;
			break;
		}
		
	}
	return ret;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	bool v2 = false, nwlin = false;
	while(getline(cin, s)){
		if(s == eqq && !v2){
			v2 = true;
			continue;
		}
		
		if(!v2){
			string pos = s;
			getline(cin, s);
			unit[pos] = s;
			string a, b;
			while(true){
				
				getline(cin, a);
				if(a == minn) break;
				if(a == eqq){
					v2 = true;
					break;
				}
				
				getline(cin, b);
				
				if(b == minn || b == eqq){
					if(b == eqq) v2 = true;	
					pair<ll, vld> query = type(a);
					ll t = query.fi;
					vld vec = query.se;
					flag[pos].pb(make_pair(t, make_pair(vec, "")));
					break;
				}
				else{
					string ans = "";
					ff(i, 2, b.size()) ans += b[i];
					pair<ll, vld> query = type(a);
					ll t = query.fi;
					vld vec = query.se;
					flag[pos].pb(make_pair(t, make_pair(vec, ans)));
				}
			}
		}
		else{
			string pos = s;
			if(nwlin) cout << ed;
			cout << pos << ed << minn << ed << med << ed << minn << ed;
			nwlin = true;
			string a;
			while(getline(cin, a)){
				if(a == eqq) break;
				string cur = "";
				ll id = 0;
				for(ll i = a.size()-1; i >= 0; i--){
					if(a[i] == ' '){ id = i; break;}
					cur += a[i];
				}
				reverse(all(cur));
				long double num = stod(cur);
				
				
				for(ll i = id; i >= 0; i--){
					if(a[i] != ' '){id = i; break;}
				}
				string nam = "";
				ff(i, 0, id+1) nam += a[i];
				ll qqq = nam.size();
				string spp = string(26-qqq, ' ');
				string outt = nam+spp+cur;
				
				qqq = outt.size();	
				spp = string(34-qqq, ' ');
				outt += spp+unit[nam];
				
				qqq = outt.size();
				spp = string(50-qqq, ' ');
				outt += spp;
				
				string flagans = calc(nam, num);
				if(flagans == "Normal") flagans = "";
				outt += flagans;
				
				qqq = outt.size();
				spp = string(75-qqq, ' ');
				outt += spp;
				cout << outt << ed;
			}
			cout << minn << ed << eqq;
		}
	}
}
