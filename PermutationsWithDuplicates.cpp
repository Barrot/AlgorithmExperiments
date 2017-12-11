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

template <typename T, size_t SIZE>
void generatePermutations(unsigned int index, std::vector<T>& dat,
                          std::array<unsigned int, SIZE> selections) {
  if (index == selections.max_size()) {
    // Do something with the selection
    printList(selections, dat);
    //********************************
    return;
  } else {
    for (unsigned int i = 0; i < dat.size(); ++i) {
      selections[index] = i;
      generatePermutations(index + 1, dat, selections);
    }
  }
}

int main() {
  std::vector<char> a{'A', 'B', 'C'};
  generatePermutations<char, 2>(0, a, {});
  return 0;
}