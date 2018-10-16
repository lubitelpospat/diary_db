#include <iostream>
#include <vector>
#include <cstring>
//////////////////////
using namespace std;
/////////   DAYCHANGER   ////////////////
void daychanger(const int& mon, int& n) {
    switch(mon)
    {
        case 1:
            n=31;
            break;
        case 2:
            n=28;
            break;
        case 3:
            n=31;
            break;
        case 4:
            n=30;
            break;
        case 5:
            n=31;
            break;
        case 6:
            n=30;
            break;
        case 7:
            n=31;
            break;
        case 8:
            n= 31;
            break;
        case 9:
            n=30 ;
            break;
        case 10:
            n=31 ;
            break;
        case 11:
            n=30 ;
            break;
        case 12:
            n=31 ;
            break;
        default:
            n=31;
            break;
    }
}
/////////   NEXT   ////////////////////////
void next(vector<vector<string>>& month, int& mon, int& NOfD){
    mon=(mon+1)%12;
    if (mon==0) {
        mon=12;
    }
    int tmp=NOfD;
    daychanger(mon,NOfD);
    if (NOfD<tmp){
        for (int k=NOfD; k<tmp; k++) {
            month[NOfD-1].insert(end(month[NOfD-1]), begin(month[k]), end(month[k]));
        }
    }
    month.resize(NOfD);
    tmp=0;
}
/////////   DUMP   ////////////////////////
void dump(vector<vector<string>>& month, vector<string>& res) {
    int w;
    cin >> w;
    res.push_back(to_string(month[w-1].size()));
    res.push_back(" ");
    for (const auto c :month[w-1]) {
        res.push_back(c);
        res.push_back(" ");
    }
    res.push_back("\n");
}
/////////   ADD   /////////////////////////
void add (vector<vector<string>>& month){
    int n;
    string s;
    cin >> n >> s;
    month[n-1].emplace_back(s);
}
/////////   MAIN   ////////////////////////
int main ()
{
   vector< vector<string>> month(31);
   vector <string> res;
   int q, mon=1, NOfD=31;
   string word;
   cin >>q;
   for (int v=0; v<q; v++) {
       cin >> word;
       if (word == "NEXT") {
           next(month,mon,NOfD);
       }
       else if (word=="DUMP"){
           dump(month,res);
       }
       else {
           add(month);
       }
   }
   res.pop_back();
   for (string c: res) {
       cout << c;
   }
 return 0;
}