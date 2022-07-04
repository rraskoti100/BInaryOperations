#include <iostream>
#include <math.h>
using namespace std;

void BinaryAddition(int, int[], int[], int[]);
void DecimalToBinary(int, int []); // decimal number for binary conversion and array to store it.
void BinaryToDecimal(int, int []);
void Display(int n, int []);

int main(){
    int deci1=0, deci2=0;
    int arr1[8] = {0,0,0,0,0,0,0,0}; // initilization is done to ensure array gets garbage free value.
    int arr2[8] = {0,0,0,0,0,0,0,0};
    int result[8] = {0,0,0,0,0,0,0,0};
    cout << "enter two decimal numbers(0-255): ";
    cin >> deci1 >> deci2;

    DecimalToBinary(deci1, arr1);
    cout << "Binary equivalent of " << deci1 << " is: ";
    Display(8, arr1); // 8 bit 

    DecimalToBinary(deci2, arr2);
    cout << "\nBinary Equivalent of " << deci2 << " is: ";
    Display(8, arr2); // 8-bit

    BinaryAddition(8, arr1, arr2, result); // 8-bit, two array for add and other array to store result

    cout << "\nBinary equivalent of sum is: ";
    Display(8, result);

    BinaryToDecimal(8, result); // send result array to binary to decimal function

    return 0;
}

// Funtion to convert decimal to binary.
void DecimalToBinary(int num, int arr[]){
    int i = 0, rem = 0;
    do{
        rem = num % 2;
        arr[i] = rem;
        num = num / 2;
        i++;
    }while(num > 0);
}

// Function to display the array
void Display(int n, int arr[]){
    int i;
    for(i=n-1;i>=0;i--){
        cout << arr[i];
    }
}

void BinaryToDecimal(int n, int arr[]){
    int i, result=0;
    for(i=0;i<n;i++){
        result += arr[i]*pow(2,i);
    }
    cout << "\nDecimal Equivalent of sum is: " << result << endl;
}

void BinaryAddition(int n, int arr1[], int arr2[], int result[]){
    int carry=0, i=0;
    for(i=0;i<n;i++){
        result[i] = (arr1[i] ^ arr2[i] ^ carry);
        carry = (arr1[i] & arr2[i]) | (arr2[i] & carry) | (carry & arr1[i]);
    }
    if(carry==1){
        cout << "\nOverflow!";
    }
}