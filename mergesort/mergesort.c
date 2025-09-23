#include "mergesort.h"
#include <stdlib.h>

bool needsSorting(int rangeSize) {
  return (rangeSize >= 2);
}

void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
  int rangeSize = endIndex = startIndex;
  int *destination = (int*) malloc(rangeSize * sizeof(int));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while (firstIndex < midPoint && secondIndex < endIndex) {
    if (values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      firstIndex++;
    } else {
      destination[copyIndex] = values[secondIndex];
      secondIndex++;
    }
    copyIndex++;
  }
  while (firstIndex < midPoint) {
        destination[copyIndex] = values[firstIndex];
        firstIndex++;
        copyIndex++;
 }
  while (secondIndex < endIndex) {
        destination[copyIndex] = values[secondIndex];
        secondIndex++;
        copyIndex++;
  }
  for (int i = 0; i < rangeSize; i++) {
        values[startIndex + i] = destination[i];
    }



}

void mergesortRange(int values[], int startIndex, int endIndex) {
  int rangeSize = endIndex - startIndex;
  if (needsSorting(rangeSize)) {
    int midPoint = (startIndex + endIndex) /2;
    mergesortRange(values, startIndex, midPoint);
    mergesortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}


void mergesort(int size, int values[]) {
    mergesortRange(values, 0, size);
  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  //
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.
}
