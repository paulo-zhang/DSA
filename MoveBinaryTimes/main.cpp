#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int getMoveBinaryTimes(const string &s){
    if(s.size() <= 1) return 0;

    int last1FinalIndex = -1; // The final index for the rigtest '1'
    int moveTimes = -1;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') continue;

        last1FinalIndex ++; // See '1', the final index increases.
        int nonIntersectTimes = i - last1FinalIndex; // 'i' moves at every iteration without stopped by another '1' at the front.
        if(nonIntersectTimes > 0 && nonIntersectTimes <= moveTimes){ // nonIntersectTimes <= last move times, also means encounter '11'.
            moveTimes ++;
        }
        else{
            moveTimes = nonIntersectTimes;
        }
    }

    return moveTimes == -1 ? 0 : moveTimes;
}

int main(int, char**) {
    assert(getMoveBinaryTimes("000") == 0);
    assert(getMoveBinaryTimes("111") == 0);
    assert(getMoveBinaryTimes("011") == 2);
    assert(getMoveBinaryTimes("101") == 1);
    assert(getMoveBinaryTimes("110") == 0);
    assert(getMoveBinaryTimes("0101") == 2);
    assert(getMoveBinaryTimes("1010") == 1);
    assert(getMoveBinaryTimes("1100") == 0);
    assert(getMoveBinaryTimes("001011") == 4);
    assert(getMoveBinaryTimes("010101") == 3);
    assert(getMoveBinaryTimes("101010") == 2);
    assert(getMoveBinaryTimes("110100") == 1);
    assert(getMoveBinaryTimes("111000") == 0);
    assert(getMoveBinaryTimes("011010101001010") == 7);
    assert(getMoveBinaryTimes("101101010010100") == 6);
    assert(getMoveBinaryTimes("110110100101000") == 5);
    assert(getMoveBinaryTimes("111011001010000") == 4);
    assert(getMoveBinaryTimes("111101010100000") == 3);
    assert(getMoveBinaryTimes("111110101000000") == 2);
    assert(getMoveBinaryTimes("111111010000000") == 1);
    assert(getMoveBinaryTimes("111111100000000") == 0);
    
}
