#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
};

bool compareVal(Item a, Item b){
    double val1 = a.value/a.weight;
    double val2 = b.value/b.weight;

    return val1>val2;
}

double fKnapsack(Item *arr, int w, int n){
    int cw=0;
    double fValue = 0;
    sort(arr, arr+n, compareVal);
    for(int i=0;i<n;i++){
        cout << arr[i].value << arr[i].weight << endl;
    }
    for(int i=0; i<n; i++){
        cout << cw << endl;
        cout << fValue<<endl;
        if(cw+arr[i].weight<w){
            cw+=arr[i].weight;
            fValue+=arr[i].value;
        }
        else{
            int r_weight = w-cw;
            cout << "reached here" << endl;
            fValue = (arr[i].value/arr[i].weight)*r_weight;
            break;
        }

    }
    return fValue;
}

int main(){
    int w=70;
    Item arr[3] = {{60,20}, {70,15},{80,40}};
    cout << fKnapsack(arr,w,3) << endl;
}
