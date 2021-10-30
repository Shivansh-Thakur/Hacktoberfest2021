#include<bits/stdc++.h> 
using namespace std; 
  
string reverseStringWords(string s){ 
    int i = s.length() - 1, begin, end = i + 1; 
    string res = ""; 
      
    while(i >= 0){ 
        if(s[i] == ' '){ 
            begin = i + 1; 
            while(begin != end) 
                res += s[begin++]; 
              
            res += ' '; 
            end = i; 
        } 
        
        i--; 
    } 
    begin = 0; 
    while(begin != end) 
        res += s[begin++]; 
      
    return res; 
} 
  
int main(){ 
    string s = "requests pull my accept Please"; 
    cout << reverseStringWords(s); 
      
    return 0; 
} 
