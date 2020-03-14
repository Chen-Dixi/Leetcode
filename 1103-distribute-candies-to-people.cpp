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
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> results(num_people);
        int n=1;
        int i=0;
        while(candies>0){
            if(candies<n)
                results[i]+=candies;
            else
                results[i]+=n;
            candies-=n;
            n++;
            i=(i+1)%num_people;
        }

        return results;
    }
};


int main(){

    Solution sol = Solution();

    int candies = 10;
    int num_people = 3;

    vector<int> results = sol.distributeCandies(candies, num_people);
    for(vector::iterator it=results.begin(); it!=results.end(); it++){
        cout<< *it <<" "<<endl;
    }
}