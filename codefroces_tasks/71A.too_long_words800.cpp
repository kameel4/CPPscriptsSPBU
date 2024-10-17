#include <iostream>
using namespace std;

int main(){
    string word;
    int n_words;
    cin>>n_words;
    for (int i=0; i<n_words; i++){
        cin>>word;
        if(word.length()>10){
            cout<<*word.begin()<<word.length()-2<<word[word.length()-1]<<endl;}
        else
            {cout<<word<<endl;}
    }
}