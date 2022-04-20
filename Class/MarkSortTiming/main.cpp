/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Example of Mark Sort
 */

//System Libraries
#include <iostream>  //I/O Library
#include <cstdlib>   //Random Number Library
#include <ctime>     //Time to set the random number seed
using namespace std;

//User Libraries

//Global Constants Only
//Well known Science, Mathematical and Laboratory Constants

//Function Prototypes
int *filAray(int);
void prntAry(const int *,int,int);
void markSrt(int *,int);

//Execution of Code Begins Here
int main(int argc, char** argv) {
    //Set the random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables for this function
    int size=160000;
    int perLine=10;
    int *array;
    
    //Initialize all known variables
    array=filAray(size);
    //cout<<"Before Sorting"<<endl;
    //prntAry(array,size,perLine);
    
    //Process Inputs to Outputs -> Mapping Process
    //Maps known values to the unknown objectives
    int timBeg=time(0);
    markSrt(array,size);
    int timEnd=time(0);
    
    //Display the Inputs/Outputs
    //cout<<"After Sorting"<<endl;
    //prntAry(array,size,perLine);
    cout<<"Total Time for Mark Sort = "<<timEnd-timBeg
            <<" secs with N = "<<size<<endl;

    //Clean up the code, close files, deallocate memory, etc....
    delete []array;
    
    //Exit stage right
    return 0;
}

//Function Implementations
void markSrt(int *a,int n){
    //Find the smallest element in List i
    for(int i=0;i<n-1;i++){
        //Swap as you go to place the smallest element at the top
        for(int j=i+1;j<n;j++){
            //Logic swap
            if(a[i]>a[j]){
                //int temp=a[i];
                //a[i]=a[j];
                //a[j]=temp;
                *(a+i)=*(a+i)^*(a+j);
                *(a+j)=*(a+i)^*(a+j);
                *(a+i)=*(a+i)^*(a+j);
            }
        }
    }
}


void prntAry(const int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *filAray(int n){
    //Declare and allocate the array
    n=n<2?2:n;
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand();//2 Digit Random Array
    }
    return array;
}