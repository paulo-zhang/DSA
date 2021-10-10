#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>
#include <stack>
#include <algorithm>

// O(n^2)
int TheJungleBook1(std::vector<int> ints)
{
    // Inprovement: use visited[ints.size()];
    int max = 1;
    int arrLen = ints.size();
    for (int i = 0; i < arrLen; i++)
    {
        int a = i;
        int counter = 1;
        while (ints[a] > -1 && ints[a] < arrLen && counter < arrLen)
        {
            a = ints[a];
            counter++;
        }

        if (counter > max)
            max = counter;
    }

    return max;
}

// O(n * level) deteriorate to O(n^2) when there is only one linear tree.
int TheJungleBook2(std::vector<int> ints)
{
    // Inprovement: use visited[ints.size()];
    std::list<int> l(ints.begin(), ints.end());
    std::unordered_set<int> s;
    s.insert(-1);// level 1.
    int level = 0;
    while(true)
    {
        bool found = false;
        std::unordered_set<int> next;
        for(int i = 0;i < ints.size();i ++)
        {
            if(s.find(ints[i]) == s.end()) continue;

            next.insert(i);
            found = true;
        }

        if(!found) break;

        level ++;
        s.swap(next);
    }

    return level;
}

// Tree: O(n)
int TheJungleBook3(std::vector<int> ints)
{
    struct Node
    {
        std::list<int> children;
        int depth = 1;
    };

    std::vector<Node> nodes(ints.size());

    // Build tree. O(n)
    std::list<int> roots;
    for(int i = 0; i < ints.size(); i++)
    {
        if(ints[i] == -1) 
        {
            roots.push_back(i);
            continue; // No parent.
        }

        nodes[ints[i]].children.push_back(i);
    }

    // Depth first search. O(n)
    int maxLevel = 0;
    for(int root : roots)
    {
        std::stack<int> s;
        s.push(root);

        while(!s.empty())
        {
            int n = s.top();
            s.pop();
            for(int c : nodes[n].children)
            {
                nodes[c].depth = nodes[n].depth + 1;
                maxLevel = std::max(nodes[c].depth, maxLevel);
                s.push(c);
            }
        }
    }

    return maxLevel;
}

int main(int, char **)
{
    std::vector<int> ints = {-1, 8, 6, 0, 7, 3, 8, 9, -1, 6, 1};
    std::cout << "TheJungleBook1: " << TheJungleBook1(ints) << "\n";
    std::cout << "TheJungleBook2: " << TheJungleBook2(ints) << "\n";
    std::cout << "TheJungleBook3: " << TheJungleBook3(ints) << "\n";
}
