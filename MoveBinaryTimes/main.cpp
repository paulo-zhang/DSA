#include <iostream>
#include <string>

using namespace std;

int getMoveBinaryTimes(const string &s){
    if(s.size() <= 1) return 0;

    int last1FinalIndex = -1; // The final index for the rigtest '1'
    int moveTimes = -1;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == '0') continue;

        last1FinalIndex ++; // See '1', the final index increases.
        int nonIntersectTimes = i - last1FinalIndex; // 'i' moves at every iteration without stopped by another '1' at the front.
        if(nonIntersectTimes <= moveTimes){ // nonIntersectTimes <= last move times, also means encounter '11'.
            moveTimes ++;
        }
        else{
            moveTimes = nonIntersectTimes;
        }
    }

    return moveTimes == -1 ? 0 : moveTimes;
}

int main(int, char**) {
    std::cout << getMoveBinaryTimes("011") << "\n";
    std::cout << getMoveBinaryTimes("0101") << "\n";
    std::cout << getMoveBinaryTimes("001011") << "\n";
    std::cout << getMoveBinaryTimes("011010101001010") << "\n";
}
