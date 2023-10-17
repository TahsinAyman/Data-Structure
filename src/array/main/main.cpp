#include<iostream>
using namespace std;
#include<vector>

int main(void) {
  vector<int*> numbers;
  numbers.push_back(new int(1));
  numbers.push_back(new int(2));
  numbers.push_back(nullptr);
  // for (vector<*int>::iterator itr = numbers.begin(); itr != numbers.end(); ++itr){
  //   *itr = "ayman";
  // }
  for (int *num : numbers) {
    if (num == nullptr) {
      cout << "NULL" << endl;
      continue;
    }
    cout << *num << endl;
  }
    
   
  return 0;
}