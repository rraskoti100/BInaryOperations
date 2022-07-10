#include <iostream>
#include <math.h>
using namespace std;

void BinaryAddition(int, int[], int[], int[]);
void DecimalToBinary(int, int []); // decimal number for binary conversion and array to store it.
void BinaryToDecimal(int, int []);
void Display(int n, int []);
void OnesComplement(int, int []);

int main(){
    int deci1=0, deci2=0;
    int arr1[8] = {0,0,0,0,0,0,0,0}; // initilization is done to ensure array gets garbage free value.
    int arr2[8] = {0,0,0,0,0,0,0,0};
    int arr3[8] = {1,0,0,0,0,0,0,0};
    int result[8] = {0,0,0,0,0,0,0,0}; // stores 2's complement
    int difference[8] = {0,0,0,0,0,0,0,0}; // stores the differece 
    cout << "enter two decimal numbers(0-255): ";
    cin >> deci1 >> deci2;

    // convert first decimal number to binary and display
    DecimalToBinary(deci1, arr1);
    cout << "Binary equivalent of " << deci1 << " is: ";
    Display(8, arr1); // 8 bit 

    // Convert second decimal number to binary and display
    DecimalToBinary(deci2, arr2);
    cout << "\nBinary Equivalent of " << deci2 << " is: ";
    Display(8, arr2); // 8-bit

    // find 1's complement of subtrahend(smaller number)
    OnesComplement(8, arr2);
    cout << "\nThe 1's complement is: ";
    Display(8, arr2);

    // Add 1 to 1's complement of subtrahend to find 2's complement
    BinaryAddition(8, arr2, arr3, result); // 8-bit, two array for add and other array to store result
    cout << "\n2's Complement equivalent is: ";
    Display(8, result);
    
    //Add Minuend and 2's complement of Subtrahend
    BinaryAddition(8, arr1, result, difference);
    cout<< "\nThe differece equivalent in binary: ";
    Display(8, difference);

    //convert difference of two number to decimal    
    BinaryToDecimal(8, difference);

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

//Function to convert binary to decimal
void BinaryToDecimal(int n, int arr[]){
    int i, result=0;
    for(i=0;i<n;i++){
        result += arr[i]*pow(2,i);
    }
    cout << "\nDecimal Equivalent of difference is: " << result << endl;
}

// Function to add two binary numbers
void BinaryAddition(int n, int arr1[], int arr2[], int result[]){
    int carry=0, i=0;
    for(i=0;i<n;i++){
        result[i] = (arr1[i] ^ arr2[i] ^ carry);
        carry = (arr1[i] & arr2[i]) | (arr2[i] & carry) | (carry & arr1[i]);
    }
}

// Function to find 1's complement
void OnesComplement(int n, int arr[]){
    for(int i=0;i<n;i++){
        if(arr[i]==0) arr[i] = 1;
        else arr[i] = 0;
    }
}
