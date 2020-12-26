#pragma once

template<class type>
void Merge( type &Array, int First, int Center, int Length ) {
  First--;
  int Last = Length - 1;
  Center = ((First + Last) / 2);
  type Sorted(Last - First + 1);

  int Left = First, Right = Center + 1;
  for (int i = First; i <= Last; ++i) {
    if (Left > Center)
      Sorted[i - First] = Array[Right++];
    else if (Right > Last)
      Sorted[i - First] = Array[Left++];
    else if (Array[Left] < Array[Right])
      Sorted[i - First] = Array[Left++];
    else
      Sorted[i - First] = Array[Right++];
  }
  for (int i = First; i <= Last; ++i)
    Array[i] = Sorted[i - First];
}

template<class type>
void Sort( type &Array, int First, int Last ) {
  if (First < Last) {
    int Center = ((First + Last) / 2);
    Sort(Array, First, Center);
    Sort(Array, Center + 1, Last);
    Merge(Array, First, Center, Last);
  }
}
