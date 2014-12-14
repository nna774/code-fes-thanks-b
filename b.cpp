#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>

using namespace std;

int main(int, char**){
    int a, b,c;
    cin >> a >> b>>c;
    cout << max(a+b+c,max((a+b)*c,max(a*b+c,a*b*c))) <<endl;
    return 0;
}










