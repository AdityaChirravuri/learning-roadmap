#include <bits/stdc++.h>
using namespace std;

// This is solution for LeetCode problem: Longest Harmonious Subsequence
// Link: Day 1: https://leetcode.com/problems/longest-harmonious-subsequence/description/
// Used STL: Map

void solve(vector<int>nums){
    map<int, int>mp;

    if( nums.size() == 1)cout << "0";

    for(int i: nums)mp[i]++;
    int max_length=0, length = 0;

    map<int, int>::iterator cur = mp.begin();
    map<int, int>::iterator next = cur++;


    while( next != mp.end() ){
        if(abs(cur->first - next->first) == 1){
            length = abs(cur->second- next->second);
            max_length = max(length, max_length);
        }
        ++cur;
        ++next;
    }

    cout << max_length;

}

int main(int argc, char* argv[]){
    vector<int>nums;
    int temp;
    for(int i=1; i<argc; i++){
        temp = stoi(argv[i]);
        nums.push_back(temp);
    }

    solve(nums);


    return 0;
}