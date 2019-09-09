#include<bits/stdc++.h>
using namespace std;


// void remove(char *input, int newIndex, int index){
//   if(input[index]=='\0') {
//         input[newIndex] = input[index-1];
//         input[newIndex+1]='\0';
//         return;
//   }
//   if(input[index]==input[index-1])
//   {
//       remove(input, newIndex, index+1);
//       return;
//   }
//   else{
//         input[newIndex]=input[index-1];
//         remove(input, newIndex+1, index+1);
//   }

// }

// void removeConsecutiveDuplicates(char *input){

//         remove(input, 0, 1);

// }
void removeConsecutiveDuplicates(char *input) {
        /* Don't write main().
        * Don't read input, it is passed as function argument.
        * Change in the given string itself.
        * No need to return or print anything
        * Taking input and printing output is handled automatically.
        */
    cout << input << endl;
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==input[1]){
        int i=1;
      for(; input[i]='\0'; i++){
         input[i-1] = input[i];
      }
     input[i-1] = input[i];
        cout << input << endl;
     removeConsecutiveDuplicates(input+2);
 }
 else{
        removeConsecutiveDuplicates(input+1);
    }
    return;
}
// void replaceCharacter(char input[], char c1, char c2) {
//     /* Don't write main().
//      * Don't read input, it is passed as function argument.
//      * No need to print or return the output.
//      * Change in the given input string itself.
//      * Taking input and printing output is handled automatically.
//      */


//     if(input[0] =='\0'){
//         return;
//     }

//     if(input[0]==c1){
//         input[0]=c2;
//     }
//     replaceCharacter(input+1, c1, c2);
// }

int main(){
    // char str[100];
    char str[] = "aabbaccd";
    char c1='a';
    char c2='x';
    cout << str << endl;
    removeConsecutiveDuplicates(str);
    // replaceCharacter(str, c1,c2)
    cout<< str<< endl;
}

