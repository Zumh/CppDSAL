#include <vector>
#include <iostream>


void merge(std::vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  std::vector<int> L(n1), R(n2);

  // Copy data to temporary arrays
  for (int i = 0; i < n1; ++i) {
    L[i] = arr[left + i];
  }
  for (int j = 0; j < n2; ++j) {
    R[j] = arr[mid + 1 + j];
  }

  int i = 0, j = 0, k = left;
  // Merge the temporary arrays back into arr[left:right+1]
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      ++i;
    } else {
      arr[k] = R[j];
      ++j;
    }
    ++k;
  }

  // Copy the remaining elements of L, if there are any
  while (i < n1) {
    arr[k] = L[i];
    ++i;
    ++k;
  }

  // Copy the remaining elements of R, if there are any
  while (j < n2) {
    arr[k] = R[j];
    ++j;
    ++k;
  }
}

void iterativeMergeSort(std::vector<int>& arr) {
  int n = arr.size();
  for (int current_size = 1; current_size < n; current_size *= 2) {
    // Outer loop (Merging Sub-arrays)
    for (int left = 0; left < n - 1; left += 2 * current_size) {
      int mid = std::min(left + current_size - 1, n - 1); // Handle odd length
      int right = std::min(mid + current_size, n - 1);     // Handle odd length

      // Merge sub-arrays arr[left:right] and arr[mid+1:right]
      merge(arr, left, mid, right);
    }
  }
}

void display(std::vector<int>& arr) {

  // Print the sorted array
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void sortNumbers(std::vector<int>& arr){
  iterativeMergeSort(arr);
  display(arr);
}
int main() {

  std::vector<std::vector<int>> arrs = {
    {6, 5, 3, 1, 8, 7, 2, 4}, 
    {6, 5, 3, 1, 8, 7, 2}
  };
  for (size_t index = 0; index < arrs.size(); index++){
    sortNumbers(arrs[index]);
  }

  return 0;
}
