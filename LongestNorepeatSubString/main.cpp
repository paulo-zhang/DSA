#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
// https://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

int longestUniqueSubsttr(string input)
{
    unordered_map<char, int> visitedIndex;
    int maxCount = 0, currCount = 0;
    string theString;

    for (int i = 0; i < input.size(); ++i)
    {
        if (visitedIndex.find(input[i]) != visitedIndex.end())
        {
            i = visitedIndex[input[i]]; // Move to next index, start over again.
            visitedIndex.clear();
            currCount = 0;
        }
        else
        {
            currCount++;
            if (currCount > maxCount)
            {
                maxCount = currCount;
                theString = input.substr(i + 1 - currCount, currCount);
            }

            visitedIndex[input[i]] = i;
        }
    }

    cout << theString << "\n";
    return maxCount;
}

int main(int, char **)
{
    string str = "geeksforgeeks";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len << "\n";
    return 0;
}
