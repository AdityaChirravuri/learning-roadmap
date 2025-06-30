#include <bits/stdc++.h>
using namespace std;

struct sortDec{
    bool operator()(const pair<int, int>&a , const pair<int, int>&b){
        return a.second< b.second;
    }
};

void print_arr_pair(vector<pair<int, int>>arr){
    for(pair<int, int> p: arr){
        cout << p.first << " " << p.second << "\n";
    }
    cout << "\n";
}

vector<int> maxSubSeq(vector<int>& arr, int k){
    vector<int>sol;
    vector<pair<int, int>>vec;

    for(int i=0; i<arr.size(); i++){
        pair<int, int>temp;
        temp.first = arr[i];
        temp.second = i;

        vec.emplace_back(temp);

    }
    
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());
    sort(vec.begin(), vec.begin()+k, sortDec());
    print_arr_pair(vec);
    for(int i=0; i<k; i++){
        sol.emplace_back(vec[i].first);
    }

    return sol;
}

int main(int argc, char* argv[]){
    if( argc < 2){
        cout << "Invalid Usage";
    }else if (argc < 3){
        cout << "INvalid Usage";
    }

    int size = stoi(argv[1]); // Size of the array
    vector<int>arr; // to store the array
    for(int i=2; i<argc; i++){
        int value = stoi(argv[i]);
        arr.push_back(value);
    }

    vector<int>sol = maxSubSeq(arr, size);

    for(int i: sol)cout << i << " ";
    return 0;
}