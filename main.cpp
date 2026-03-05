#include <iostream>

template< class T >
T* mergeN(const T* const * a, size_t sa, const size_t* sai, T* c)
{
  size_t* inds = new size_t[sa]{};
  size_t totalSize = 0;
  for (size_t i = 0; i < sa; i++) {
    totalSize += sai[i];
  }

  size_t i = 0;
  try {
    for (; i < totalSize; i++) {
      size_t minInd = 0;
      for (size_t j = 0; j < sa; j++) {
        if (inds[j] < sai[j]) {
          minInd = j;
          break;
        }
      }
      for (size_t j = 0; j < sa; j++) {
        if (inds[j] < sai[j]) {
          if (a[j][inds[j]] < a[minInd][inds[minInd]]) {
            minInd = j;
          }
        }
      }
      c[i] = a[minInd][inds[minInd]];
      inds[minInd]++;
    }
  } catch (...) {
    delete[] inds;
    return c + i;
  }

  delete[] inds;
  return c + totalSize;
}

int main()
{
  size_t a = 8;
  size_t b = 5;
  size_t c = 6;
  size_t sai[]{a, b, c};
  int aa[] {1,2,3,4,5,6,7,108};
  int bb[] {25,31,36,40,58};
  int cc[] {1,2,52,54,67,68};
  int* arr[]{aa, bb, cc};

  int* r = new int[a+b+c];
  int* e = nullptr;
  try {
    e = mergeN(arr, 3, sai, r);
  } catch (...) {
    delete[] r;
    return 1;
  }

  for (int* s = r; s < e; s++) {
    std::cout << *s << ' ';
  }

  delete[] r;
  return 0;
}

