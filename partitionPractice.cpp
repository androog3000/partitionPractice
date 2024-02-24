//Program that demonstrates two ways to partition a collection of numbers moving all negative numbers before the positive numbers without consideration for a full sorting

#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
  int temp = a;
  a = b;
  b = temp;
}

void printVec(vector<int> vec){
  for (int i = 0; i < vec.size(); i++) {
    if (i != vec.size() - 1){
      cout << vec[i] << " ";
    } else {
      cout << vec[i];
    }
  }
  cout << "\n";
}

//scans start from opposite ends
void partitionFirst(vector<int> numbers){
  int i, j;
  for (i = 0; i < numbers.size(); i++) {
    if (numbers[i] > 0) {
      for (j = numbers.size() - 1; j > i; j--) {
        if (numbers[j] < 0) {
          swap(numbers[i], numbers[j]);
          break;
        }  
      }
    }
  }
  printVec(numbers);
}

//both scans start from left side
void partitionSecond(vector<int> numbers){
  int i, j;
  for (i = 0; i < numbers.size(); i++) {
    if (numbers[i] > 0) { 
      for (j = i + 1; j < numbers.size(); j++) {
        if (numbers[j] < 0) {
          swap(numbers[i], numbers[j]);
          break;
        }  
      }
    }
  }
  printVec(numbers);
}


int main()
{
  int size, i, j;
  vector<int> numbers;
  //cout << "Enter quantity of numbers: \n";
  cin >> size;
  for (i = 0; i < size; i++) {
    int number;
    //cout << "Enter number: \n";
    cin >> number;
    numbers.push_back(number);
  }

  partitionFirst(numbers);
  partitionSecond(numbers);
  
  return 0;
}

