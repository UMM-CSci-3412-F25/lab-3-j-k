// array_merge.c
#include <stdlib.h>
#include "array_merge.h"
#include "../mergesort/mergesort.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  if (num_arrays <= 0 || sizes == NULL || values == NULL) {
    int *out = (int*) malloc(sizeof(int));
    if (out) out[0] = 0;
    return out;
  }

  int total = 0;
  for (int i = 0; i < num_arrays; i++) {
    if (sizes[i] > 0 && values[i] != NULL)
      total += sizes[i];
  }

  if (total == 0) {
    int *out = (int*) malloc(sizeof(int));
    if (out) out[0] = 0;
    return out;
  }

  int *all = (int*) malloc(sizeof(int) * (size_t) total);
  if (!all) {
    int *out = (int*) malloc(sizeof(int));
    if (out) out[0] = 0;
    return out;
  }

  int pos = 0;
  for (int i = 0; i < num_arrays; i++) {
    int sz = sizes[i];
    if (sz > 0 && values[i] != NULL) {
      for (int j = 0; j < sz; j++) {
        all[pos++] = values[i][j];
      }
    }
  }

  mergesort(total, all);

  int *out = (int*) malloc(sizeof(int) * (size_t)(total + 1));
  if (!out) {
    free(all);
    int *fallback = (int*) malloc(sizeof(int));
    if (fallback) fallback[0] = 0;
    return fallback;
  }
  int k = 0;
  if (total > 0) {
    out[1] = all[0];
    k = 1;
    for (int i = 1; i < total; i++) {
      if (all[i] != out[k]) {
        out[++k] = all[i];
      }
    }
  }

  out[0] = k;

  int *shrunk = (int*) realloc(out, sizeof(int) * (size_t)(k + 1));
  if (shrunk) out = shrunk;

  free(all);
  return out;
}
