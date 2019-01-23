#include <string>
#include <iostream>
#include <sstream>
using namespace std;


int findMaxSum(int* origArr, int arrSize,
	     int numTributes, int currSum) {

  if (arrSize <= 0) {
    return currSum;
  }

  if (arrSize == 1) {
    return currSum + origArr[0];
  }

  int tempSum = currSum;
  for (int i = 0; i < arrSize - 2*(numTributes - 1); i++) {
    int trialSum = findMaxSum(origArr + i + 2, arrSize - i - 2, 
			    numTributes - 1, currSum + origArr[i]);
    if (trialSum > tempSum) {
      tempSum = trialSum;
    }
  }
  
  return tempSum;
}



int main(int argc, char* argv[]) {
  
  // string line;
  
  int trials;
  cin >> trials;
  
  for (int i = 0; i < trials; i++) {
    int arrSize;
    cin >> arrSize;
  
    int numTributes;
    cin >> numTributes;

    int arr[arrSize];
    for (int i = 0; i < arrSize; i++) {
      cin >> arr[i];
    }

    cout << findMaxSum(arr, arrSize, numTributes, 0) << endl;
  }
}







/*
int markIndex(int* arr, int arrSize, int numTributes, int& currSum) {
  
  if (arrSize <= 0) {
    return;
  }
  
  int tempSum = currSum;
  
  // make temp array
  int tempArr[arrSize];
  for (int i = 0; i < arrSize; i++) {
    tempArr[i] = 0;
  }

  for (int i = 0; i < arrSize - numTributes - 1; i++) {
    // make temp array for each item equivalent to current array
    int trialArr[arrSize];
    for (int k = 0; k < arrSize; k++) {
      trialArr[k] = 0;
    }

    trialArr[i] = 1;
    
    int trialSum = 

    // run markIndex again
    

    // if markIndex has sum larger than currSum,
    // change currsum and temp array

  }
  
  // change arr to temp array
  // return sum

}
*/
