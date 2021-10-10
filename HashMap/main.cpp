#include <iostream>
#include <string>
#include "HashMap.h"

using namespace std;

int main(int, char**) {
    struct MyKeyHash {
        unsigned long operator()(const int& k) const
        {
            return k % 10;
        }
    };

    // HashMap<int, string, MyKeyHash> hmap; // Use different hash key generator.
    HashMap<int, string> hmap;
    hmap[1] = "val1";
    hmap[2] = "val2";
    hmap[3] = "val3";

    cout << hmap[1] << endl;
    cout << hmap[2] << endl;
    cout << hmap[3] << endl;

    hmap[1] = "val1_1";
    hmap.erase(2);
    hmap[3] = "val3_3";

    cout << hmap[1] << endl;
    cout << hmap[2] << endl;
    cout << hmap[3] << endl;
}