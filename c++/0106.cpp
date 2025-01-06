#include <iostream>
#include <vector>
#include <algorithm>
#include<string>

using namespace std;

int main(){
    std::vector<int> numbers(9);
    int k=0;
    int sum=0;
    bool flag=false;
    int a=0, b=0;
    for(int i=0; i<9; i++){
        std::cin>>numbers[i];
        k+=numbers[i];
    }
    k=k-100;
    sort(numbers.begin(), numbers.end());
    
    for(int i=8; i>=0&&!flag; i--){
        for(int j=0; j<=8; j++){
            sum=numbers[i]+numbers[j];
            if(sum==k){
                a = i;
                b = j;
                flag=true;
                break;
            }else if(sum>k){
                break;
            }
        }
    }

    for(int k=0; k<9; k++){
        if(k!=a&&k!=b){
            std::cout<<numbers[k]<<'\n';
        }
    }

    return 0;
}