/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on April 6th, 2022, 8:25 PM
 * Purpose:  Retirement Recursion
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <cmath>      //Math Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
float recRetire(float,float,float,int);//Recursive Retirement
float forRetire(float,float,float,int);//For-Loops
float closfrm(float,float,float,int);//Closed Form Solution

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Declare variables here
    float pv,//Present Value in $'s
     intRate,//Interest Rate %
    depPrcnt,//Percent of Salary used for Regular Retirement Deposit
     deposit,//Regular Deposit $'s;
      salary,//Yearly Salary $'s
          fv;//Future Value
    int numCmpd;//Number of compounding periods
    
    //Initialize variables here
    pv=0;//$0
    intRate=0.06f;//6%
    numCmpd=34;
    salary=115000.0f;//$115k
    depPrcnt=0.166f;//16.6%
    deposit=salary*depPrcnt;//Yearly deposit
    
    //Map inputs to outputs here, i.e. the process
    cout<<"Recursion  Solution fv("<<pv<<","<<intRate<<
            ","<<numCmpd<<")=$"
            <<recRetire(pv,intRate,deposit,numCmpd)<<endl;
    cout<<"For-Loop   Solution fv("<<pv<<","<<intRate<<
            ","<<numCmpd<<")=$"
            <<forRetire(pv,intRate,deposit,numCmpd)<<endl;
    cout<<"Closed Frm Solution fv("<<pv<<","<<intRate<<
            ","<<numCmpd<<")=$"
            <<closfrm(pv,intRate,deposit,numCmpd)
            <<endl;
    cout<<"Savings needed to retire = $"<<salary/intRate<<endl;
    
    //Display the results

    return 0;
}

float closfrm(float pv,float i,float d,int n){
    float c=(1+i);
    float cton=pow(c,n);
    return cton*pv+d*(1-cton)/(1-c);
}

float forRetire(float pv,float i,float d,int n){
    float c=(1+i);
    float fv=pv;
    for(int j=1;j<=n;j++){
        fv*=c;
        fv+=d;
    }
    return fv;
}

float recRetire(float pv,float i,float d,int n){
    //Base Case
    if(n<=0)return pv;
    //Recursion
    float c=(1+i);
    return c*recRetire(pv,i,d,n-1)+d;
}