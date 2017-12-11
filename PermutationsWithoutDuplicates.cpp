#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

template <typename T, typename U>
void printList(T& lst, U& dat) {
  std::cout << "{";
  for (auto i : lst) {
    std::cout << dat[i];
  }
  std::cout << "}" << std::endl;
}

template <typename T, std::size_t SIZE>
void generatePermutations(unsigned int index, std::vector<T>& dat,
                          std::array<unsigned int, SIZE> selections) {
  if (index == selections.max_size()) {
    // Do something with the selection
    printList(selections, dat);
    //********************************
    return;
  } else {
    for (unsigned int i = 0; i < dat.size(); ++i) {
      auto res = std::find(std::begin(selections), std::end(selections), i);
      if (res != std::end(selections)) continue;
      selections[index] = i;
      generatePermutations<char, SIZE>(index + 1, dat, selections);
    }
  }
}

int main() {
  std::vector<char> a{'A', 'B', 'C', 'D', 'E'};
  generatePermutations<char, 3>(0, a, {});
  return 0;
}