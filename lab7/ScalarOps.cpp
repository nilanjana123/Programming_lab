#include <bits/stdc++.h>
#include "dt.h"
#include "LoggerAns.h"
#include "ScalarOps.h"

using namespace std;
    // perform scalar- matrix Addition . 
    vector<vector<double> > ScalarOps::getAdd(double num , vector<vector<double> > arr){
        try
        {
        vector<vector<double> > calc_add;
        for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] + num;
            }
        }
        calc_add = arr;
        return calc_add;
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
    }
    
    // perform scalar- matrix subtraction . 
    vector<vector<double> > ScalarOps::getSub(double num , vector<vector<double> > arr){
        try
        {
        vector<vector<double> > calc_sub;
        for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] - num;
            }
        }
        calc_sub = arr;
        return calc_sub;
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
    }
    
    // do scalar-matrix multiplication .
    vector<vector<double> > ScalarOps::getMul(double num , vector<vector<double> > arr){
        try
        {
           
        vector<vector<double> > calc_mul;
        for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] * num;
            }
        }
        calc_mul = arr;
        return calc_mul;

        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
    }
    
    // method for matrix Division 
    vector<vector<double> > ScalarOps::getDiv(double num , vector<vector<double> > arr){
        try
        {
            
        vector<vector<double> > calc_div;
        if (num == 0){
            LoggerAns l;
            l.logg("Error : Division by zero not allowed");
            exit(1);
        }
        else{
            for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] / num;
            }
        }

        calc_div = arr;
        
        }
        return calc_div;
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
    }
    