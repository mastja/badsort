/*  Project Name : Bad Sort
    Date: 4/12/2020
    Programmer: Jacob Mast
    Description: The program to run the badsort algorithm in c++
*/


#include<iostream>
#include<fstream>
#include<assert.h>
#include<cmath>
using namespace std;

void bad_sort(int arr[], int m, int n, float alpha);

int main(){

    //open the input file to read from it
    ifstream infile("data.txt");

    // steps for merge sort
    // create variable for array length
    int len;

    // open output file in write mode
    ofstream outfile1("bad.out");

    // declare/set alpha variable
    float alpha;
    cout << "Enter the value of alpha:\t";
    cin >> alpha;

    // read from file, so long as we have not reached the end of file
    while (!infile.eof( )){
        // In HW prompt - the first value in the input stream is the number 
        // of values to be sorted
        infile>>len;

        // create array of size len, add 1 spot to hold integer list length value
        int arr1[len + 1];

        // store the array length as the first value of the sorted array
        arr1[0] = len;

        // counter variable
        int i;

        // read content from file, and write to the array
        for( i = 1 ; i <= len ; i++ ){
            infile>>arr1[i];
        }

        /* run merge sort function, declared above and written below
        program takes an array of unsorted positive integers and sorts into
        increasing order using the merge sort algorithm
        */    
        bad_sort(arr1, 1, len, a);

        // write content from the sorted array into the output file
        for( i = 1 ; i <= len ; i++ ){
            outfile1<<arr1[i]<<" ";
        }   
        outfile1<<endl;
    }

    // close the opened files.
    infile.close();
    outfile1.close();

    return 0;
}


// bad_sort function sorts an array using the bad sort alorithm

void bad_sort(int arr[], int m, int n, float alpha){

    if ((n == 2) && (arr[m] > arr[n])){
        int temp = arr [m];
        arr[m] = arr[n];
        arr[n] = temp;
    }

    // if there is more than one value in the array
    else if(n > 2){

        // get mid index
        int mid = round(alpha * n);

        if (mid = n){
            mid = mid - 1;
        }

        // recursive call to sort the left subarray
        bad_sort(arr, m, mid - 1, alpha);

        // recursive call to sort the right subarray
        bad_sort(arr, n - mid, n - 1, alpha);

        // recursive call to sort the left subarray again
        bad_sort(arr, m, mid - 1, alpha);
    }
}
