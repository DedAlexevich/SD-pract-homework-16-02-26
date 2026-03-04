#include <iostream>

template< class T >
T* mergeN(const T* const * a, size_t sa, const size_t* sai, T* c)
{
  size_t* inds = new size_t[sa]{};
  size_t totalSize = 0;
  for (size_t i = 0; i < sa; i++) {
    totalSize += sai[i];
  }

  for (size_t i = 0; i < totalSize; i++) {
    size_t minInd = 0;
    T min;
    for (size_t j = 0; j < sa; ++j) {
      if (inds[j] < sai[j]) {
        minInd = j;
        min = a[j][inds[j]];
        break;
      }
    }
    for (size_t j = 0; j < sa; j++) {
      if (inds[j] < sai[j]) {
        if (a[j][inds[j]] < min) {
          min = a[j][inds[j]];
          minInd = j;
        }
      }
    }
    c[i] = a[minInd][inds[minInd]];
    inds[minInd]++;
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
  int* aa = new int[a]{1,2,3,4,5,6,7,108};
  int* bb = new int[b]{25,31,36,40,58};
  int* cc = new int[c]{1,2,52,54,67,68};
  int* arr[]{aa, bb, cc};

  int* r = new int[a+b+c];
  int* e = mergeN(arr, 3, sai, r);

  for (int* s = r; s < e; s++) {
    std::cout << *s << ' ';
  }

  delete[] aa;
  delete[] bb;
  delete[] cc;
  delete[] r;
}

