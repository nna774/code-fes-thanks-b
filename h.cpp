#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <map>

using namespace std;


int main(int, char**){
    int n;
    cin >> n;

//    vector<string> x;
    vector<pair<char,char>> y,rev;
    map<char,int> map, maprev;
    using cpair = pair<char,char>;
    vector<pair<char, cpair>> vec, revvec;
    
    for(int i(0);i<n;++i){
        string t;
        cin >> t;
//        x.push_back(t);
        vec.push_back(make_pair(t[0],make_pair(t[0],*(t.end()-1))));
        y.push_back(make_pair(t[0],*(t.end()-1)));
        revvec.push_back(make_pair(*(t.end()-1),make_pair(*(t.end()-1),t[0])));
        rev.push_back(make_pair(*(t.end()-1), t[0]));
    }
    sort(y.begin(), y.end());
    
    // // for(char f('a'); f <= 'z' ;++f){
    // // }
    // for(auto e: y) {
    //     ++map[e.first];
    //     ++maprev[e.second];
    // }
    // for(char f('a'); f <= 'z' ;++f){
    //     if(map[f]+maprev[f] == 2){
    //         auto it = find(y.begin(), y.end(), [=](pair<char,char>& c){ return f == c.first; });
    //     }

    // }
    for(auto e: y) cout << e.first <<", " << e.second << endl;
    return 0;
}
