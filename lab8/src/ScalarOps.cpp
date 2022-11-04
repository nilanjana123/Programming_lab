#include <bits/stdc++.h>
#include "dt.h"
#include "LoggerAns.h"
#include "ScalarOps.h"

using namespace std;
    // perform scalar- matrix Addition . 
    vector<vector<double> > ScalarOps::getAdd(double num , vector<vector<double> > arr){
        vector<vector<double> > calc_add;
        try
        {
        for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] + num;
            }
        }
        calc_add = arr;
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
        return calc_add;
        
    }
    
    // perform scalar- matrix subtraction . 
    vector<vector<double> > ScalarOps::getSub(double num , vector<vector<double> > arr){
        vector<vector<double> > calc_sub;
        try
        {
        for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] - num;
            }
        }
        calc_sub = arr;
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return calc_sub;
        
    }
    
    // do scalar-matrix multiplication .
    vector<vector<double> > ScalarOps::getMul(double num , vector<vector<double> > arr){
        vector<vector<double> > calc_mul;
        try
        {
           
        for ( int i=0 ; i< arr.size();i++){
            for (int j = 0 ; j< arr[0].size(); j++){
                arr[i][j] = arr[i][j] * num;
            }
        }
        calc_mul = arr;
        
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return calc_mul;

    }
    
    // method for matrix Division 
    vector<vector<double> > ScalarOps::getDiv(double num , vector<vector<double> > arr){
        vector<vector<double> > calc_div;
        try
        {
            
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
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return calc_div;
        
    }
    
