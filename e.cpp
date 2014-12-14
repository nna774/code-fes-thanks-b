#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <utility>
#include <queue>


using namespace std;

int main(int, char**){
    int r,c;
    int r_s,c_s, r_g, c_g,n;
    cin >> r >>c >> r_s >> c_s >> r_g>>c_g>>n;

    // r--;c--;
    vector<int> map(r*c);

    for(int i(0);i<n;++i){
        int r_n, c_n,h,w;
        cin >> r_n >> c_n >> h>>w;
        for(int j(0);j<h;++j){
            for(int k(0);k<w;++k){
                map[(r_n-1)*c+(c_n-1)+(j)*c+(k)]=1;
            }
        }
    }

    if(map[(r_s-1)*c+c_s-1] != 1||map[(r_g-1)*c+c_g-1] != 1){
        cout << "NO" << endl;
        return 0;
    }

    queue<pair<int,int>> que;
    que.push(make_pair(r_s-1,c_s-1));
    vector<pair<int,int>> vec;
    vec.push_back(make_pair(r_s-1,c_s-1));
    while(1){
        if(que.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        auto v = que.front();
        que.pop();
        int x = v.first;
        int y = v.second;
        if(x==r_g-1&&y==c_g-1){
            cout << "YES" << endl;
            return 0;
        }
        if(x-1>=0 && map[(x-1)*c+y] ==1){
            if(find(vec.begin(),vec.end(), make_pair(x-1,y)) == vec.end()){
                que.push(make_pair(x-1,y));
                vec.push_back(make_pair(x-1,y));
            }
        }
        if(x+1<r && map[(x+1)*c+y] ==1 ){
            if(find(vec.begin(),vec.end(), make_pair(x+1,y)) == vec.end()){
                vec.push_back(make_pair(x+1,y));
                que.push(make_pair(x+1,y));
            }
        }
        if(y-1>=0 && map[(x)*c+y-1] ==1 ){
            if(find(vec.begin(),vec.end(), make_pair(x,y-1)) == vec.end()){
                vec.push_back(make_pair(x,y-1));
                que.push(make_pair(x,y-1));
            }
        }
        if(y+1<c && (map[(x)*c+y+1] ==1)){
            if(find(vec.begin(),vec.end(), make_pair(x,y+1)) == vec.end()){
                vec.push_back(make_pair(x,y+1));
                que.push(make_pair(x,y+1));
            }
        }
    }
    // for(int j(0);j<r;++j){
    //         for(int k(0);k<c;++k){
    //             if(map[j*c+k]) cout << '#' ;
    //             else cout << '.';
    //         }
    //         cout << endl;
    //     }
    

    return 0;
}










