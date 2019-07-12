/*
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

*/
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //不在这里进行变换
        /*bool endInList=false;
        for(int i=0;i<wordList.size();i++)
        {
            string word = wordList[i];
            if (word==endWord){
                endInList=true;
                break;
            }
        }
        if(!endInList) 
            return 0;
        */
        
        int L = beginWord.size();
        //进行预处理，方便找到邻接节点
        map<string,vector<string> > mainDict;
        unordered_map<string,int> visWord;
        for(string word : wordList){
            for(int i=0;i<L;i++){
                string key = word.substr(0,i)+"*"+word.substr(i+1);
                if(mainDict.find(key)==mainDict.end()){
                    vector<string> words = {word};
                    mainDict[key]=words;
                }else{
                    mainDict[key].push_back(word);
                }
            }
        }
        // for(map<string,vector<string> >::iterator iter = mainDict.begin(); iter != mainDict.end(); iter++) {
        //     cout<<iter->first<<": "<<endl;
        //     vector<string> vec = iter->second;
        //     for(string word : vec){
        //         cout<<word<<" ";
        //     }
        //     cout<<endl;
        // }
        queue<pair<string,int> > que;
        que.push(make_pair(beginWord, 1));
        while(!que.empty()){
            pair<string,int> p = que.front();que.pop();
            string word = p.first;
            int step = p.second;

            for(int i=0;i<L;i++){
                string key = word.substr(0,i)+"*"+word.substr(i+1);
                if(mainDict.find(key)!=mainDict.end()){
                    for(string w : mainDict[key]){
                        if(w==endWord)
                            return step+1;
                        if(visWord.find(w)==visWord.end()){
                            visWord[w]=1;
                            que.push(make_pair(w, step+1));
                        }
                    }
                }else
                    continue;
            }
        }

        return 0;
    }
};


int main(){
    Solution sol = Solution();
    vector<string> list={"hot","dot","dog","lot","log","cog"};
    string beginWord="hit";
    string endWord="cog";
    cout<<sol.ladderLength(beginWord, endWord, list);


}
