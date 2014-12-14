#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <map>

using namespace std;

int main(int, char**){
    int n ,t;
    cin >> n >>t;

    vector<int> x,y;
    map<int,int> map;

    for(int i(0);i<n;++i){
        int t;
        cin >> t;
        x.push_back(t);
    }
    int cnt(0);

    for(int i(0);i<n;++i){
        for(int j(x[i]);j<=t; j+= x[i]) {
            if(map[j] == 0) map[j] = 1;
            else map[j]++;
        }
            
    }
    for(int i(0);i<=t;++i){
        cnt = max(cnt, map[i]);
    }
    cout << cnt << endl;

    return 0;
}




