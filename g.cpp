#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <string>

using namespace std;

int map[501][501];

bool f(int n, int p){
    if(map[n][p] == 1) return true;
    if(map[n][p] == 2) return false;
    if(n<=p && n>=1) return true;
    for(int i(1);i<=p;++i) {
        bool pa=f(n-i,i+1);
        if(!pa) {
            map[n][p] = 1;
            return true;
        }
    }
    map[n][p] = 2;
    return false;
}

int main(int, char**){
    int n,p;
    cin >> n >>p;

    cout << (f(n,p) ? "first" : "second") << endl;
    return 0;
}










