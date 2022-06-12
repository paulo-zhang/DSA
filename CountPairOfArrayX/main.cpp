#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

/*
You are given the following integer N, array A of length N, integer x.
Given a single non-negative integer x, determine the count of pairs (i,j) where 1<=i<j<=N and | Ai + Aj | + | Ai - Aj | >=x.
Here |x| denotes the absolute value of x. For example |-3| = 3.

Example-1:

N = 3, A = [7, 8, 9], x=17

For i=1, j=2, | Ai + Aj | + | Ai - Aj | = 16
For i=1, j=3, | Ai + Aj | + | Ai - Aj | = 18
For i=2, j=3, | Ai + Aj | + | Ai - Aj | = 18
Therefore, 2 such pairs exist.
Example-2:
N = 2, A = [4, 5], x=12
For i=1, j=2, | Ai + Aj | + | Ai - Aj | = 10

Therefore, no such pair which gives a value greater than or equal to 'x'.

Therefore, No such pairs exist.
*/

/*
Observe: | Ai + Aj | + | Ai - Aj | >= x
if(|Ai| >= |Aj|) => 2|Ai| >= x;
if(|Ai| <= |Aj|) => 2|Aj| >= x;
We need to find the count of elements which satisfy: 2|Ai| >= x;
*/
int countPairWithX(const vector<int> &arr, int x){
    int count = 0; // The number of elements satisfy: 2|Ai| >= x;
    for(int i = 0; i < arr.size();i ++){
        if(2 * abs(arr[i]) >= x){
            count ++;
        }
    }

    return count * (arr.size() - count) + // Pairs with only one 2|Ai| >= x
        count * (count - 1) / 2; // Pairs with both two 2|Ai| >= x
}

int main(int, char**) {
    assert(countPairWithX({7, 8, 9}, 17) == 2);
    assert(countPairWithX({4, 5}, 17) == 0);
}
