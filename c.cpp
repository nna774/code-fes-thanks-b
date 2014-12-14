#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>

using namespace std;

int main(int, char**){
    int n;
    cin >> n;

    vector<int> x,y;

    for(int i(0);i<n;++i){
        int t;
        cin >> t;
        x.push_back(t);
    }
    for(int i(0);i<n;++i){
        int t;
        cin >> t;
        y.push_back(t);
    }
    int cnt(0);

    for(int i(0);i<n;++i){
        if(x[i] < y[i]*2) ++cnt;
    }
    cout << cnt << endl;

    return 0;
}










