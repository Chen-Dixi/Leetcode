#include <cstdio>
#include <iostream>
#include <cstring>
#include <utility>
#include <algorithm>
#include <vector>
#include <multiset>

using namespace std;

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> ans;
        int len = arr.size();
        if(len==0){
            return ans;
        }
        if(k>len||k<=0){
            return ans;
        }

        int start = 0;
        int end = len - 1;

        int index = Partition(arr, start, end);
        while(index != k-1 && index!=k){
            if(index>k){
                end = index-1;
                index = Partition(arr, start, end);
            }else if(index<k-1){
                start = index+1;
                index = Partition(arr, start,end);
            }
        }
        for(int i=0;i<k;i++){
            ans.push_back(arr[i]);
        }

        return ans;
    }

    int Partition(vector<int>& arr, int l, int r)
    {
        int x = arr[r];

        int i=l-1;
        for(int j=l;j<r;j++){
            if(arr[j]<x){
                i++;
                swap(arr[j],arr[i]);
            }
        }
        int tmp = arr[i+1];
        arr[i+1] = x;
        arr[r] = tmp;
        return i+1;
    }
};

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {

        vector<int> ans;
        
        multiset<int,greater<int> > leastNumbers;
        //multiset<int,greater<int> >::iterator setIterator;

        if (k<1 || arr.size()<k)
            return ans;
            
        vector<int>::iterator iter = arr.begin();
        for(; iter!=arr.end(); ++iter){
            if(leastNumbers.size()<k)
                leastNumbers.insert(*iter);
            else{
                multiset<int,greater<int> >::iterator iterGreatest = leastNumbers.begin();

                if(*iter < *(leastNumbers.begin()))
                {
                    leastNumbers.erase(iterGreatest);
                    leastNumbers.insert(*iter);
                }
            }

        }
        multiset<int,greater<int> >::iterator iterGreatest = leastNumbers.begin();
        for(;iterGreatest!=leastNumbers.end();iter++){
            ans.push_back(*iterGreatest);
        }

        return ans;

    }
};



}


