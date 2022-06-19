#include <bits/stdc++.h>

using namespace std;

long findTotalImbalance0(const vector<int> &rank) {
    int n = rank.size();
    long imbalances = 0;
    
    for(int i = 0;i < n;i ++){
        int minVal = rank[i], maxVal = rank[i];
        vector<int> temp = vector<int>(n + 1);
        temp[rank[i]] = 1;
        int imb = 0;
        
        for( int j = i + 1; j < n; j++){
            if(rank[j] < minVal){
                minVal = rank[j];
                if(temp[rank[j] + 1] == 0){
                    imb += 1;
                }
            }
            else if(rank[j] > maxVal){
                maxVal = rank[j];
                if(temp[rank[j] - 1] == 0){
                    imb += 1;
                }
            }
            else {
                if(temp[rank[j] + 1] == 0 && temp[rank[j] - 1] == 0){
                    imb += 1;
                }
                if(temp[rank[j] + 1] == 1 && temp[rank[j] - 1] == 1){
                    imb -= 1;
                }
            }
            
            temp[rank[j]] = 1;
            imbalances += imb;
        }
    }
    
    return imbalances;
}

// Optimized from findTotalImbalance0
long findTotalImbalance1(const vector<int> &rank) {
    int n = rank.size();
    long imbalances = 0;
    int subarray[n + 2] = {0}; // Only change 1, 2, ..., n, extend to 0 and n + 1 to avoid overflow checking.

    for(int i = 0;i < n; i ++){
        int minVal = rank[i], maxVal = rank[i];
        memset(subarray, 0, sizeof(subarray));
        subarray[rank[i]] = 1; // Start of subarray.
        int imb = 0;
        
        for( int j = i + 1; j < n; j++){
            if(subarray[rank[j] + 1] == 0 && subarray[rank[j] - 1] == 0){
                imb += 1;
            }
            else if(subarray[rank[j] + 1] == 1 && subarray[rank[j] - 1] == 1){
                imb -= 1;
            }
            
            subarray[rank[j]] = 1; // Current end of subarray.
            imbalances += imb;
        }
    }
    
    return imbalances;
}

int main(int, char**) {
    assert(findTotalImbalance0({1, 3, 2}) == 1);
    assert(findTotalImbalance0({1, 2, 3}) == 0);
    assert(findTotalImbalance0({2, 1, 3}) == 1);
    assert(findTotalImbalance0({2, 3, 1}) == 1);
    assert(findTotalImbalance0({3, 1, 2}) == 1);
    assert(findTotalImbalance0({3, 2, 1}) == 0);

    assert(findTotalImbalance0({1, 2, 3, 4}) == 0);
    assert(findTotalImbalance0({1, 2, 4, 3}) == 2);
    assert(findTotalImbalance0({1, 3, 2, 4}) == 2);
    assert(findTotalImbalance0({1, 3, 4, 2}) == 3);
    assert(findTotalImbalance0({1, 4, 2, 3}) == 3);
    assert(findTotalImbalance0({1, 4, 3, 2}) == 2);
    assert(findTotalImbalance0({2, 1, 3, 4}) == 2);
    assert(findTotalImbalance0({2, 1, 4, 3}) == 3);
    assert(findTotalImbalance0({2, 3, 1, 4}) == 3);
    assert(findTotalImbalance0({2, 3, 4, 1}) == 2);
    assert(findTotalImbalance0({2, 4, 1, 3}) == 5);
    assert(findTotalImbalance0({2, 4, 3, 1}) == 3);
    assert(findTotalImbalance0({3, 1, 2, 4}) == 3);
    assert(findTotalImbalance0({3, 1, 4, 2}) == 5);
    assert(findTotalImbalance0({3, 2, 1, 4}) == 2);
    assert(findTotalImbalance0({3, 2, 4, 1}) == 3);
    assert(findTotalImbalance0({3, 4, 1, 2}) == 3);
    assert(findTotalImbalance0({3, 4, 2, 1}) == 2);
    assert(findTotalImbalance0({4, 1, 2, 3}) == 2);
    assert(findTotalImbalance0({4, 1, 3, 2}) == 3);
    assert(findTotalImbalance0({4, 2, 1, 3}) == 3);
    assert(findTotalImbalance0({4, 2, 3, 1}) == 2);
    assert(findTotalImbalance0({4, 3, 1, 2}) == 2);
    assert(findTotalImbalance0({4, 3, 2, 1}) == 0);


    assert(findTotalImbalance1({1, 3, 2}) == 1);
    assert(findTotalImbalance1({1, 2, 3}) == 0);
    assert(findTotalImbalance1({2, 1, 3}) == 1);
    assert(findTotalImbalance1({2, 3, 1}) == 1);
    assert(findTotalImbalance1({3, 1, 2}) == 1);
    assert(findTotalImbalance1({3, 2, 1}) == 0);

    assert(findTotalImbalance1({1, 2, 3, 4}) == 0);
    assert(findTotalImbalance1({1, 2, 4, 3}) == 2);
    assert(findTotalImbalance1({1, 3, 2, 4}) == 2);
    assert(findTotalImbalance1({1, 3, 4, 2}) == 3);
    assert(findTotalImbalance1({1, 4, 2, 3}) == 3);
    assert(findTotalImbalance1({1, 4, 3, 2}) == 2);
    assert(findTotalImbalance1({2, 1, 3, 4}) == 2);
    assert(findTotalImbalance1({2, 1, 4, 3}) == 3);
    assert(findTotalImbalance1({2, 3, 1, 4}) == 3);
    assert(findTotalImbalance1({2, 3, 4, 1}) == 2);
    assert(findTotalImbalance1({2, 4, 1, 3}) == 5);
    assert(findTotalImbalance1({2, 4, 3, 1}) == 3);
    assert(findTotalImbalance1({3, 1, 2, 4}) == 3);
    assert(findTotalImbalance1({3, 1, 4, 2}) == 5);
    assert(findTotalImbalance1({3, 2, 1, 4}) == 2);
    assert(findTotalImbalance1({3, 2, 4, 1}) == 3);
    assert(findTotalImbalance1({3, 4, 1, 2}) == 3);
    assert(findTotalImbalance1({3, 4, 2, 1}) == 2);
    assert(findTotalImbalance1({4, 1, 2, 3}) == 2);
    assert(findTotalImbalance1({4, 1, 3, 2}) == 3);
    assert(findTotalImbalance1({4, 2, 1, 3}) == 3);
    assert(findTotalImbalance1({4, 2, 3, 1}) == 2);
    assert(findTotalImbalance1({4, 3, 1, 2}) == 2);
    assert(findTotalImbalance1({4, 3, 2, 1}) == 0);

    assert(findTotalImbalance0({1, 3, 5, 2, 4}) == 9);
    assert(findTotalImbalance1({1, 3, 5, 2, 4}) == 9);

    vector<int> arr(1000);
    for(int i = 0; i < 1000;i ++){
        arr[i] = i + 1;
    }

    for(int i = 0;i < 100; i++){
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
        shuffle(arr.begin(), arr.end(), std::default_random_engine(seed));
        assert(findTotalImbalance0(arr) == findTotalImbalance1(arr));
    }
}
