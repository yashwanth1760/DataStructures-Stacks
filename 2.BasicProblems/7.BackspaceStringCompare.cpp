// https://leetcode.com/problems/backspace-string-compare/description/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1;
        stack<char> s2;

        for (auto it : s) {
            if (s1.empty() && it == '#') {
                continue;
            }
            if (!s1.empty()) {

                if (it == '#') {
                    s1.pop();
                }

            }
            if(it!='#') s1.push(it);
        }

        for (auto it : t) {
            if (s2.empty() && it == '#') {
                continue;
            }
            if (!s2.empty()) {

                if (it == '#') {
                    s2.pop();
                }

            }
           if(it!='#') s2.push(it);
        }

        if(s1.size()!=s2.size()) return false;

        while(!s1.empty()){
            if(s1.top()!=s2.top()){
                return false;
            }
            s1.pop();
            s2.pop();
        }

        return true;
    }
};


// tc - o(n+m) sc - o(n+m)  where n and m are the size of the strings s and t

//same complexity but with string 

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string res1;
        for(auto ch : s){
            if(ch=='#'){
                if(res1.size()==0) continue;
                res1.pop_back();
            }
            else res1.push_back(ch);
        }
        string res2;
        for(auto ch : t){
            if(ch=='#'){
                if(res2.size()==0) continue;
                res2.pop_back();
            }
            else res2.push_back(ch);
        }
        return res1==res2;
    }
};