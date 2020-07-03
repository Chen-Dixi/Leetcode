#include <stack>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <utility>
#include <cstdint>
#include <algorithm>
#include <cstring>
using namespace std;


class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {

        int len = postorder.size();

        if(len<=0){
            return true;
        }

        return recursive(postorder,0,len-1);
    }

    bool recursive(vector<int>& postorder, int l, int r){

        if(l>=r)
            return true;

        int root = postorder[r];

        int i=l;
        for(;i<r;i++){  
            if(postorder[i]>root)
                break;
        }
        int p=i++;

        for(;i<r;i++){
            if(postorder[i]<root)
                return false;
        }

        return recursive(postorder,l,p-1) && recursive(postorder,p,r-1);
    }
};



