
#include<bits/stdc++.h>
#include <unordered_map>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string st; 
    cin >> st; 
    unordered_map<char, int> char_map;
    
    char_map['a'] = 0;
    char_map['s'] = 0;
    char_map['p'] = 0;
    
    for(int i=0; i<n; i++){
        if(st[i]=='a'){
            char_map['a']++;
            
        }
        else if(st[i]=='s'){
            char_map['s']++;
            
        }
        else if(st[i]=='p'){
            char_map['p']++;
            
        }
        
    }
    unordered_map<char, int>::iterator it;
        for(it=char_map.begin(); it!=char_map.end(); ++it){
            cout<< it->first <<  it->second;
        }
	return 0;
}

