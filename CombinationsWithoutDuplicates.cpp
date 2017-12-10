#include <iostream>
#include <vector>
#include <array>

using namespace std;

template<typename T>
void printList(T& lst) {
    cout << "{";
    for (auto i : lst) {
        cout << i;
    }
    cout << "}" << endl;
}

template<typename T, size_t SIZE>
void generateCombinations(unsigned int index, vector<T> &dat, array<unsigned int, SIZE> selections) {
    if (index == selections.max_size()) {
        printList(selections);
        return;
    } else {
        unsigned int start = 0;
        if (index > 0) start = selections[index - 1] + 1;
        for (unsigned int i = start; i < dat.size(); ++i) {
            selections[index] = i;
            generateCombinations(index + 1, dat, selections);
        }
    }
}

int main() {

    vector<char> a{'A', 'B', 'C'};
    generateCombinations<char, 2>(0, a, {});

    return 0;
}