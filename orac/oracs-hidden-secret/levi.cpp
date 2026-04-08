// my real code isn't saved from TE
// this is levi's code
// dont @ me

#include "password.h"
#include<bits/stdc++.h>
using namespace std;
 
bool query(string guess){
    vector<bool> v;
    for(int i = 0; i < guess.size(); i++){
        v.push_back(guess[i] == '1');
    }
    return guess_password(v);
}
 
vector<bool> find_password(int N) {
    string guess = "1";
    while(guess.size() < N){
        string guess1 = guess + "0";
        string guess2 = guess + "1";
        bool val1 = query(guess1), val2 = query(guess2);
        if(val1){
            guess = guess1;
        }
        else if(val2){
            guess = guess2;
        }
        else{
            break;
        }
    }
    while(guess.size() < N){
        string guess1 = "0" + guess;
        string guess2 = "1" + guess;
        int val1 = query(guess1), val2 = query(guess2);
        if(val1){
            guess = guess1;
        }
        else if(val2){
            guess = guess2;
        }
        else{
            break;
        }
    }
    vector<bool> v;
    if(guess.size() == N){
        for(int i = 0; i < N; i++){
            v.push_back(guess[i] == '1');
        }
    }
    else{
        for(int i = 0; i < N; i++){
            v.push_back(false);
        }
    }
    return v;
}
