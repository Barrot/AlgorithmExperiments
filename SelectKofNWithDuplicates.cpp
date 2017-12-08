#include <iostream>
#include <vector>
#include <array>

using namespace std;

void SelectKofNWithDuplicates(unsigned int index,
                              array<unsigned int, 2> selections,
                              vector<char> &dat,
                              vector<vector<char>> &results) {
  if (index == selections.max_size() - 1) {
    vector<char> result;
    for (auto i : selections) {
      result.emplace_back(dat[i]);
    }
    results.emplace_back(move(result));
  } else {
    unsigned int start = 0;
    if (index > 0)
      start = selections[index - 1];
    for (unsigned int i = start; i < dat.size(); ++i) {
      selections[index] = i;
      SelectKofNWithDuplicates(index + 1, selections, dat, reults);
    }
  }
}

int main() { 

  vector<char> dat{'A', 'B', 'C'}; // N = 3
  vector<vector<char>> results;
  array<unsigned int, 2> selections; // K = 2
  SelectKofNWithDuplicates(0, selections, dat, results);

  return 0;
}