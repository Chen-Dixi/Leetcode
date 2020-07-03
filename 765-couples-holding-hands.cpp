#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res=0;
        int len = row.size();
        for(int i=0;i<len; i = i+2){
            int x = row[i];
            if(row[i+1] == (x^1))
                continue;
             
            for(int j=i+2;i<len;j++){
                if(row[j]==(x^1)){
                    row[j]=row[i+1];
                    row[i+1]=x^1;
                    break;
                }
            }
            res++;
        }
        return res;
    }
};