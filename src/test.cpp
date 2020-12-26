#include <functional>
#include <vector>

#include "merge_sort.h"

template<class type>
static bool IsSorted( type Ar, int Size ) {
  for (int i = 0; i + 1 < Size; ++i)
    if (Ar[i] > Ar[i + 1])
      return false;
  return true;
}

static const int GremlinTestSize = 10000;
static std::vector<std::function<bool(void)>> TestCases = {
  []() -> bool {
    std::vector<int> Ar = { 5, 2, 4, 6, 1, 3, 2, 6 };
    Sort(Ar, 1, Ar.size());
    return IsSorted(Ar, Ar.size());
  },
  []() -> bool {
    std::vector<int> Ar = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    Sort(Ar, 1, Ar.size());
    return IsSorted(Ar, Ar.size());
  },
  []() -> bool {
    std::vector<int> Ar = { 9, 8, 7, 6, 5, 4, 3, 2 };
    Sort(Ar, 1, Ar.size());
    return IsSorted(Ar, Ar.size());
  },
  []() -> bool {
    std::vector<double> Ar(GremlinTestSize);
    for (double &It : Ar)
      It = (double)rand() / RAND_MAX;
    Sort(Ar, 1, Ar.size());
    return IsSorted(Ar, Ar.size());
  },
  []() -> bool {
    std::vector<double> Ar(0);
    Sort(Ar, 1, Ar.size());
    return IsSorted(Ar, Ar.size());
  }
};


int main() {
  for (auto &Case : TestCases)
    if (!Case())
      // Fail
      return -1;
  return 0;
}
