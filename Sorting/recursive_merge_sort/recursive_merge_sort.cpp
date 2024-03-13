#include <vector>
#include <iostream>

void Merge(std::vector<int>& data, int left_index, int middle_index, int right_index) {
  // Create temporary arrays to hold left and right sub-arrays
  int left_size = middle_index - left_index + 1;
  int right_size = right_index - middle_index;
  std::vector<int> left_subarray(left_size), right_subarray(right_size);

  // Copy data to temporary arrays
  for (int i = 0; i < left_size; ++i) {
    left_subarray[i] = data[left_index + i];
  }
  for (int j = 0; j < right_size; ++j) {
    right_subarray[j] = data[middle_index + 1 + j];
  }

  int i = 0, j = 0, k = left_index;
  // Merge the temporary arrays back into data[left_index:right_index]
  while (i < left_size && j < right_size) {
    if (left_subarray[i] <= right_subarray[j]) {
      data[k] = left_subarray[i];
      i++;
    } else {
      data[k] = right_subarray[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of left_subarray, if there are any
  while (i < left_size) {
    data[k] = left_subarray[i];
    i++;
    k++;
  }

  // Copy the remaining elements of right_subarray, if there are any
  while (j < right_size) {
    data[k] = right_subarray[j];
    j++;
    k++;
  }
}

void MergeSort(std::vector<int>& data, int left_index, int right_index) {
  if (left_index < right_index) {
    // Find the middle point
    int middle_index = left_index + (right_index - left_index) / 2;

    // Sort first and second halves
    MergeSort(data, left_index, middle_index);
    MergeSort(data, middle_index + 1, right_index);

    // Merge the sorted halves
    Merge(data, left_index, middle_index, right_index);
  }
}

void display(std::vector<int>& arr) {

  // Print the sorted array
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;
}

void sort_numbers(std::vector<int>& data){
  MergeSort(data, 0, data.size() - 1);
  display(data);
}

int main() {

  std::vector<std::vector<int>> datas = {
    {6, 5, 3, 1, 8, 7, 2, 4}, 
    {6, 5, 3, 1, 8, 7, 2}
  };
  for (size_t index = 0; index < datas.size(); index++){
    sort_numbers(datas[index]);
  }

  return 0;
}
