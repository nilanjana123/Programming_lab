#include <bits/stdc++.h>
#include "dt.h"
#include "LoggerAns.h"
#include "MatrixOps.h"

using namespace std;
    
    // perform matrix-matrix addition .
    vector<vector<double> > MatrixOps::getAdd(vector<vector<double> > arr1 , vector<vector<double> > arr2){
        vector<vector<double> > calc_add;
        try
        {
        for ( int i=0 ; i< arr1.size();i++){
            for (int j = 0 ; j< arr1[0].size(); j++){
                arr1[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        calc_add = arr1;
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
        return calc_add;
        
    }
    
    // perform matrix-matrix subtraction .
    vector<vector<double> > MatrixOps::getSub(vector<vector<double> > arr1 , vector<vector<double> > arr2){
        vector<vector<double> > calc_sub;
        try
        {
        for ( int i=0 ; i< arr1.size();i++){
            for (int j = 0 ; j< arr1[0].size(); j++){
                arr1[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        calc_sub = arr1;
        
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return calc_sub;

    }
    
    // Do matrix-matrix multiplication 
    vector<vector<double> > MatrixOps::getMul(vector<vector<double> > arr1 , vector<vector<double> > arr2){
        vector<vector<double> > calc_mul;
        try
        {
        double tempsum=0;
        vector<double> temp;

        for (int i = 0 ; i< arr1.size() ; i++){
            for (int j=0 ; j<arr2[0].size(); j++){
                for (int k=0 ; k<arr2.size(); k++){
                tempsum = tempsum+( arr1[i][k] * arr2[k][j] );  
            }
            temp.push_back(tempsum);
            tempsum = 0;
        }
        calc_mul.push_back(temp);
        temp.clear();
        }
        
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return calc_mul;
    }
    
    // method for determining transpose .
    vector<vector<double> > MatrixOps::getTranspose(vector<vector<double> > arr){
        vector<vector<double> > calc_tr (arr[0].size(), vector<double> (arr.size()));
        try
        {
        for (int i = 0 ; i< arr.size() ; i++){
        for (int j=0 ; j<arr[0].size(); j++){
          calc_tr[j][i] = arr[i][j];
        }
        }
        
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
        return calc_tr;
  
      }
    
    // calculate Determinant of valid matrix.
    double MatrixOps::getDet(vector<vector<double> > arr)
    {
        double det = 0; 
        try
        {
        if (arr.size() == 1)
        {
            return arr[0][0]; 
        }
        else if (arr.size() == 2)
        {
            det = (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
            return det;
        }
        else
        {
            for (int p = 0; p < arr[0].size(); p++)
            {
                vector<vector<double> > Temparr; // to hold the shaped arr;
                for (int i = 1; i < arr.size(); i++)
                {
                    vector<double> TempRow;
                    for (int j = 0; j < arr[i].size(); j++)
                    {
                        if (j != p)
                        {
                           TempRow.push_back(arr[i][j]);//add current cell to TempRow 
                        }
                    }
                    if (TempRow.size() > 0)
                        Temparr.push_back(TempRow);
                }
                det = det + arr[0][p] * pow(-1, p) * getDet(Temparr);
            }
            
        }
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
        return det;
        
    }
    

/*

class MatrixOps{
    public :
    // perform scalar- matrix Addition . 
    vector<vector<double> > getAdd(double num , vector<vector<double> > arr){
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
             Logger l;
            l.logg( e.what());
        }
    }
    // perform matrix-matrix addition .
    vector<vector<double> > getAdd(vector<vector<double> > arr1 , vector<vector<double> > arr2){
        try
        {
        vector<vector<double> > calc_add;
        for ( int i=0 ; i< arr1.size();i++){
            for (int j = 0 ; j< arr1[0].size(); j++){
                arr1[i][j] = arr1[i][j] + arr2[i][j];
            }
        }
        calc_add = arr1;
        return calc_add;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
        }
    }
    // perform additon operation . 
    opdata doAdd(vector<opdata> op_datas){
        try
        {  
        opdata res_add;
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = getAdd(tempnum,temp1);
                res_add.v_data = tempres;
                res_add.sc = 0;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = getAdd(tempnum,temp1);
                res_add.v_data = tempres;
                res_add.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == false){
                temp1 = op_datas[0].v_data;
                temp2 = op_datas[1].v_data;
                if (temp1.size() == temp2.size() && temp1[0].size() == temp2[0].size()){
                    tempres = getAdd(temp1 ,temp2);
                    res_add.v_data = tempres;
                    res_add.sc = false;
                }
                else{
                    Logger l;
                    l.logg("Error : Addition not possible , Dimension Mismatch.");
                    exit(1);
                }
                }
            else{
                Logger l;
                    l.logg("Error : Addition not possible , No matrix found");
                    exit(1);
            }
            // }
        }
        else{
           Logger l;
                    l.logg("Error : Addition not possible , operand missing .");
                    exit(1);
        }
        return res_add;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // perform scalar- matrix subtraction . 
    vector<vector<double> > getSub(double num , vector<vector<double> > arr){
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
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // perform matrix-matrix subtraction .
    vector<vector<double> > getSub(vector<vector<double> > arr1 , vector<vector<double> > arr2){
        try
        {
        vector<vector<double> > calc_sub;
        for ( int i=0 ; i< arr1.size();i++){
            for (int j = 0 ; j< arr1[0].size(); j++){
                arr1[i][j] = arr1[i][j] - arr2[i][j];
            }
        }
        calc_sub = arr1;
        return calc_sub;

        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // perform subtraction operation . 
    opdata doSub(vector<opdata> op_datas){
        try
        {
            
        opdata res_sub;
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = getSub(tempnum,temp1);
                res_sub.v_data = tempres;
                res_sub.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = getSub(tempnum,temp1);
                res_sub.v_data = tempres;
                res_sub.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == false){
                temp1 = op_datas[0].v_data;
                temp2 = op_datas[1].v_data;
                if (temp1.size() == temp2.size() && temp1[0].size() == temp2[0].size()){
                    tempres = getSub(temp1 ,temp2);
                    res_sub.v_data = tempres;
                    res_sub.sc = false;
                }
                else{
                    Logger l;
                    l.logg("Error : Subtraction not possible , Dimension Mismatch.");
                    exit(1);
                }
                
            }
            else{
                Logger l;
                l.logg("Error : Subtraction not possible , No matrix found .");
                exit(1);
            }
            // }
        }
        else{
            Logger l;
            l.logg("Error : Subtraction not possible , operand missing .");
            exit(1);
        }
        return res_sub;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // do scalar-matrix multiplication .
    vector<vector<double> > getMul(double num , vector<vector<double> > arr){
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
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // Do matrix-matrix multiplication 
    vector<vector<double> > getMul(vector<vector<double> > arr1 , vector<vector<double> > arr2){
        try
        {
        vector<vector<double> > calc_mul;
        double tempsum=0;
        vector<double> temp;

        for (int i = 0 ; i< arr1.size() ; i++){
            for (int j=0 ; j<arr2[0].size(); j++){
                for (int k=0 ; k<arr2.size(); k++){
                tempsum = tempsum+( arr1[i][k] * arr2[k][j] );  
            }
            temp.push_back(tempsum);
            tempsum = 0;
        }
        calc_mul.push_back(temp);
        temp.clear();
        }
        return calc_mul;
    
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
            exit(1);
        }
        }
    // Do multiplication operation . 
    opdata doMul(vector<opdata> op_datas){
        try
        {   
        opdata res_mul;
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = getMul(tempnum,temp1);
                res_mul.v_data = tempres;
                res_mul.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = getMul(tempnum,temp1);
                res_mul.v_data = tempres;
                res_mul.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == false){
                temp1 = op_datas[0].v_data;
                temp2 = op_datas[1].v_data;
                if (temp1[0].size() == temp2.size()){
                    tempres = getMul(temp1 ,temp2);
                    res_mul.v_data = tempres;
                    res_mul.sc = false;
                }
                else{
                    Logger l ;
                    l.logg("Error : Multiplication not possible , dimension mismatch.");
                    exit(1);
                }
                }
            else{
                Logger l ;
                l.logg(" Error : Multiplication not possible , No matrix found .");
                exit(1);
            }
            // }
        }
        else{
            Logger l ;
            l.logg("Error :  Multiplication not possible , operand Missing.");
            exit(1);
        }
        return res_mul;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // method for matrix Division 
    vector<vector<double> > getDiv(double num , vector<vector<double> > arr){
        try
        {
            
        vector<vector<double> > calc_div;
        if (num == 0){
            Logger l;
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
             Logger l;
            l.logg( e.what());
            exit(1);
        }
    }
    // method for calculating Division of a matrix by a scalar.
    opdata doDiv(vector<opdata> op_datas){
        try
        {  
        opdata res_div;
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = getDiv(tempnum,temp1);
                res_div.v_data = tempres;
                res_div.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = getDiv(tempnum,temp1);
                res_div.v_data = tempres;
                res_div.sc = false;
            }
            else{
                Logger l;
                l.logg("Error : Division not Possible");
            }
            // }
        }
        else{
            Logger l ;
            l.logg("Error : operand missing");
        }
        return res_div;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
        }
    }
    // method for determining transpose .
    vector<vector<double> > getTranspose(vector<vector<double> > arr){
        try
        {
         vector<vector<double> > calc_tr (arr[0].size(), vector<double> (arr.size()));
        for (int i = 0 ; i< arr.size() ; i++){
        for (int j=0 ; j<arr[0].size(); j++){
          calc_tr[j][i] = arr[i][j];
        }
        }
        return calc_tr;
  
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
        }
      }
    // method for determining transpose 
    opdata doTranspose(vector<opdata> op_datas){

        try
        {
        opdata res_tr;

        vector<vector<double> > temp, tempres;
        if (op_datas.size() == 1){
            if(op_datas[0].sc == false){
                temp = op_datas[0].v_data;
                tempres = getTranspose(temp);
                res_tr.v_data = tempres;
                res_tr.sc = false;
            }
            else{
                cout<< "Transpose not possible ";
            }
            // }
        }
        else{
            cout<< "error";
        }
        return res_tr;
    
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
        }
        }
    // calculate Determinant of valid matrix.
    double getDet(vector<vector<double> > arr)
    {
        try
        {
        double det = 0; 
        if (arr.size() == 1)
        {
            return arr[0][0]; 
        }
        else if (arr.size() == 2)
        {
            det = (arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0]);
            return det;
        }
        else
        {
            for (int p = 0; p < arr[0].size(); p++)
            {
                vector<vector<double> > Temparr; // to hold the shaped arr;
                for (int i = 1; i < arr.size(); i++)
                {
                    vector<double> TempRow;
                    for (int j = 0; j < arr[i].size(); j++)
                    {
                        if (j != p)
                        {
                           TempRow.push_back(arr[i][j]);//add current cell to TempRow 
                        }
                    }
                    if (TempRow.size() > 0)
                        Temparr.push_back(TempRow);
                }
                det = det + arr[0][p] * pow(-1, p) * getDet(Temparr);
            }
            return det;
        
        }
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
        }
    }
    // method for finding determinant     
    opdata doDet(vector<opdata> opdatas){
        try
        {
        opdata calc_res;
        vector<double> vd;
        vector<vector<double> > temp = opdatas[0].v_data;
        if ( temp.size() == temp[0].size()){
            int s = temp.size();
            double res = getDet(temp);
            // cout <<res;
            vd.push_back(res);
            calc_res.sc = true ;
            calc_res.v_data.push_back(vd);
        }
        else {
            Logger l ;
            l.logg("Error : Determinant is not computable . not a sqaure matrix");
            exit(1);
            //cout<< " det is not computable ";
        }
        return calc_res;
    
        }
        catch(const std::exception& e)
        {
            Logger l;
            l.logg( e.what());
            exit(1);
        }
        }

};
*/
