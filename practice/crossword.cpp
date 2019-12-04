#include<bits/stdc++.h>
using namespace std;
#define N 10

bool findEmpty(vector<string> &cs, int &row, int &col){
   
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(cs[i][j]=='-'){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}
bool checkHorizontal(vector<string> &cs, int &row, int &col, int elem_len, string elem){
    int forw_len = 0;

    while(cs[row][col+forw_len]!='+' && (col+forw_len<N)){
            forw_len++;
    }
    int rev_len = 0;
    while(cs[row][col-rev_len-1]!='+' && col-rev_len-1>=0){
        rev_len ++;
    }
    if(elem_len != (rev_len + forw_len)){
        return false;
    }
    int i=0;
    while(i<elem_len){
        if(cs[row][col-rev_len+i]=='-' || cs[row][col-rev_len+i]==elem[i]){
            i++;
            continue;
        }
        else{
            return false;
        }
    }
    col = col-rev_len;
    return true;
}
bool checkVertical(vector<string> &cs, int &row, int &col, int elem_len, string elem){
    int down_len = 0;
    while(cs[row+down_len][col]!='+' && (row+down_len<N)){
            down_len++;
    }
    int up_len = 0;
    while((row-up_len-1>=0) && cs[row-up_len-1][col]!='+' ){
        up_len++;
    }

    if(elem_len != (down_len + up_len)){
        return false;
    }
    int i=0;
    while(i<elem_len){
        if(cs[row-up_len+i][col]=='-' || cs[row-up_len+i][col]==elem[i]){
            i++;
            continue;
        }
        else{
            return false;
        }
    }
    row = row-up_len;
    return true;
}
void setHorizontal(vector<string> &cs, int &row, int &col, string  elem){

  
      for(int i=0; i< elem.length(); i++){
          cs[row][col+i] = elem[i];
      }
      return;
}
void setVertical(vector<string> &cs, int &row, int &col, string elem){
    for(int i=0; i< elem.length(); i++){
          cs[row+i][col] = elem[i];
      }
    
      return;
}
string getVerticalString(vector<string> &cs, int row, int col, int elem_len){

    string vertical_string;
    for(int i=row; i<row+elem_len; i++){
        vertical_string += cs[i][col];
    }
    return vertical_string;
}
void cs_helper(vector<string> &cs, vector<string> word_list){
    int row, col;
    
    if(!findEmpty(cs, row, col)){
        for(int i=0; i<N; i++){
            cout << cs[i] << endl;

        }
        exit(0);
        return;
    }
    for(int i=0; i<word_list.size(); i++){
      string element = word_list[i];
      if(checkHorizontal(cs, row, col, element.length(), element)){
          string b4_string = cs[row].substr(col, element.length());
          setHorizontal(cs, row, col, element);
          cs_helper(cs, word_list);
          setHorizontal(cs, row, col, b4_string);
      }
      if(checkVertical(cs, row, col, element.length(), element)){
          string b4_string = getVerticalString(cs, row, col, element.length());
          
          setVertical(cs, row, col, element);
         
          cs_helper(cs, word_list);
          setVertical(cs, row, col, b4_string);
      }
    }
    return;
}

int main(){ 
    vector<string> cs;

    cs.push_back("+-++++++++");
    cs.push_back("+-++-+++++");
    cs.push_back("+-------++");
    cs.push_back("+-++-+++++");
    cs.push_back("+-++-+++++");
    cs.push_back("+-++-+++++");
    cs.push_back("++++-+++++");
    cs.push_back("++++-+++++");
    cs.push_back("++++++++++");
    cs.push_back("----------");

    vector<string> word_list;
    word_list.push_back("CALIFORNIA");
    word_list.push_back("NIGERIA");
    word_list.push_back("CANADA");
    word_list.push_back("TELAVIV");

    cs_helper(cs, word_list);

}


