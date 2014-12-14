#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <string>
#include <map>

using namespace std;

long long f(string str, string s, string t, map<tuple<string,string,string>,long long>& map){
    if(map[make_tuple(str,s,t)] > 0) return map[make_tuple(str,s,t)] ;
    auto res =  std::mismatch(s.begin(), s.end(), str.begin());
    auto res2 = std::mismatch(t.begin(), t.end(), str.begin());

    long long cnt(0);
    if(str == s) cnt+= 1;
    else if (res.first == s.end())
    {
        string cut{str.begin()+s.size(),str.end()};
        cnt += f(cut,s,t, map);
        cnt %= (1000000000+7);
    }
    if(str == t) cnt+= 1;
    else if (res2.first == t.end())
    {
        string cut{str.begin()+t.size(),str.end()};
        cnt += f(cut,s,t, map);
        cnt %= (1000000000+7);
    }
    map[make_tuple(str,s,t)] = cnt;
    return cnt;
}

int main(int, char**){
    string x,s,t;
    cin >> x >> s>>t;
    map<tuple<string,string,string>,long long> map;

    cout << f(x,s,t,map) << endl;
    return 0;
}
