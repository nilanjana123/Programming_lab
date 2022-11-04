#include<bits/stdc++.h>
#include "dt.h"
#include "LoggerAns.h"
#include "ManageOps.h"
#include "MatrixOps.h"
#include "ScalarOps.h"
#include "ExtractOps.h"
using namespace std;

    // method for decode command line options .
    string ManageOps::decode_cmd_opt(){
        string cmd_opt , str1 ;
        try
        {
                
        getline(cin,str1);
        cmd_opt = str1.substr(1,str1.length());
        }
            catch(const std::exception& e)
            {
                LoggerAns l;
                l.logg( e.what());
                exit(1);
            }
            return cmd_opt;
        
    }
    
    // method for getting operands from input 
    vector<opdata> ManageOps::get_operands(int i , char sw){
        vector<opdata> v;
        try
        {
        opdata temp1;
            
        char op_type ;
        // 't' and 'x' is unary operation else binary operation . 
        // based on operation type , operand fetch will take place . 
        if (sw == 't' || sw == 'x')
        op_type = 'u';
        else
        op_type = 'b';

        if (op_type =='u' && i==0){
            ExtractOps e;
            temp1 = e.extract_data();
            if(temp1.v_data.size() > 0){
                v.push_back(temp1);
            }
            else{
                LoggerAns l;
                l.logg("Error : No more Data available in input file. ") ;
                exit(1);
            }
        }
        else if (op_type =='u' && i!=0){
            v.push_back(res);
        }
        else if (op_type =='b' && i==0){
            ExtractOps e;
            temp1 = e.extract_data();
            if(temp1.v_data.size() > 0){
                v.push_back(temp1);
            }
            else{
                LoggerAns l;
                l.logg("Error : No more Data available in input file. ") ;
                exit(1);
            }
            temp1 = e.extract_data();
            if(temp1.v_data.size() > 0){
                v.push_back(temp1);
            }
            else{
                LoggerAns l;
                l.logg("Error : No more Data available in input file. ") ;
                exit(1);
            }
        }
        else if (op_type =='b' && i!=0){
            v.push_back(res);
            ExtractOps e;
            temp1 = e.extract_data();
            if(temp1.v_data.size() > 0){
                v.push_back(temp1);
            }
            else{
                LoggerAns l;
                l.logg("Error : No more Data available in input file. ") ;
                exit(1);
            }
        }
        else {
            LoggerAns l;
            l.logg("Error : Data extraction error. ") ;
            exit(1);
        }
        

        }
            catch(const std::exception& e)
            {
                LoggerAns l;
                l.logg( e.what());
                exit(1);
            }
            return v;
        
        }

    //method to display output of a result .
    int ManageOps::display(opdata r){
        try
        {
        vector<vector<double> > temp = r.v_data;
        if (r.sc == 0){
        cout << '\n' << temp.size() << " " << temp[0].size() <<'\n';
        for( int i=0; i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                cout<<temp[i][j]<<",";
            }
            cout<<'\n';
        }
        }
        else if (r.sc == 1){
            cout<<'\n'<<temp[0][0]<<'\n';
        }        
        }
            catch(const std::exception& e)
            {
                LoggerAns l;
                l.logg( e.what());
            }
        
        return 0;
    }

    // method for perform cmd operations .
    int ManageOps::perf_cmd_ops(string cmd_opt){
        try
            {
            int l= cmd_opt.length();
            //for each cmd options perform operations 
            for( int i=0; i<l ; i++){
            char sw = cmd_opt[i];
            
            switch (sw){
                // for option 'a' perform addition.
                case 'a':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    ManageOps m;
                    res = m.doAdd(op_datas);
                    cout<< "\n# After addition.";
                    display(res);
                    break;
                }
                //for option 's' perform subtraction
                case 's':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    ManageOps m;
                    res = m.doSub(op_datas);
                    cout<< "\n# After subtraction.";
                    display(res);
                    break;                
                }
                // for option 'm' perform multiplication
                case 'm':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    
                    ManageOps m;
                    res = m.doMul(op_datas);
                    cout<< "\n# After multiplication.";
                    display(res);
                    break; 
                }
                // for option 'd' perform division
                case 'd':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    
                    ManageOps m;
                    res = m.doDiv(op_datas);
                    cout<< "\n# After division.";
                    display(res);
                    break;
                }
                // for option 't' perform transpose
                case 't':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    
                    ManageOps m;
                    res = m.doTranspose(op_datas);
                    cout<< "\n# After transpose.";
                    display(res);
                    break;
                }
                // for option 'x' perform determinant 
                case 'x':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    
                    ManageOps m;
                    res = m.doDet(op_datas);
                    cout<< "\n# After determinant.";
                    display(res);
                    break;
                }
                // for any other operation log error 
                default:{
                    LoggerAns l;
                    l.logg("Error : undefined option\n");
                    break;
                }
            }
        }
        }
            catch(const std::exception& e)
            {
                LoggerAns l;
                l.logg( e.what());
            }
        return 0;
    }

    opdata ManageOps::doAdd(vector<opdata> op_datas){
        opdata res_add;
        try
        {  
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        MatrixOps mo;
        ScalarOps so;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = so.getAdd(tempnum,temp1);
                res_add.v_data = tempres;
                res_add.sc = 0;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = so.getAdd(tempnum,temp1);
                res_add.v_data = tempres;
                res_add.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == false){
                temp1 = op_datas[0].v_data;
                temp2 = op_datas[1].v_data;
                if (temp1.size() == temp2.size() && temp1[0].size() == temp2[0].size()){
                    tempres = mo.getAdd(temp1 ,temp2);
                    res_add.v_data = tempres;
                    res_add.sc = false;
                }
                else{
                    LoggerAns l;
                    l.logg("Error : Addition not possible , Dimension Mismatch.");
                    exit(1);
                }
                }
            else{
                LoggerAns l;
                    l.logg("Error : Addition not possible , No matrix found");
                    exit(1);
            }
            // }
        }
        else{
           LoggerAns l;
                    l.logg("Error : Addition not possible , operand missing .");
                    exit(1);
        }
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return res_add;
        
    }
    
    // perform subtraction operation . 
    opdata ManageOps::doSub(vector<opdata> op_datas){
        opdata res_sub;
        try
        {
            
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        MatrixOps mo;
        ScalarOps so;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = so.getSub(tempnum,temp1);
                res_sub.v_data = tempres;
                res_sub.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = so.getSub(tempnum,temp1);
                res_sub.v_data = tempres;
                res_sub.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == false){
                temp1 = op_datas[0].v_data;
                temp2 = op_datas[1].v_data;
                if (temp1.size() == temp2.size() && temp1[0].size() == temp2[0].size()){
                    tempres = mo.getSub(temp1 ,temp2);
                    res_sub.v_data = tempres;
                    res_sub.sc = false;
                }
                else{
                    LoggerAns l;
                    l.logg("Error : Subtraction not possible , Dimension Mismatch.");
                    exit(1);
                }
                
            }
            else{
                LoggerAns l;
                l.logg("Error : Subtraction not possible , No matrix found .");
                exit(1);
            }
            // }
        }
        else{
            LoggerAns l;
            l.logg("Error : Subtraction not possible , operand missing .");
            exit(1);
        }
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return res_sub;
        
    }
    
    // Do multiplication operation . 
    opdata ManageOps::doMul(vector<opdata> op_datas){
        opdata res_mul;
        try
        {   
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        MatrixOps mo;
        ScalarOps so;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = so.getMul(tempnum,temp1);
                res_mul.v_data = tempres;
                res_mul.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = so.getMul(tempnum,temp1);
                res_mul.v_data = tempres;
                res_mul.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == false){
                temp1 = op_datas[0].v_data;
                temp2 = op_datas[1].v_data;
                if (temp1[0].size() == temp2.size()){
                    tempres = mo.getMul(temp1 ,temp2);
                    res_mul.v_data = tempres;
                    res_mul.sc = false;
                }
                else{
                    LoggerAns l ;
                    l.logg("Error : Multiplication not possible , dimension mismatch.");
                    exit(1);
                }
                }
            else{
                LoggerAns l ;
                l.logg(" Error : Multiplication not possible , No matrix found .");
                exit(1);
            }
            // }
        }
        else{
            LoggerAns l ;
            l.logg("Error :  Multiplication not possible , operand Missing.");
            exit(1);
        }
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return res_mul;
        
    }
    
    // method for calculating Division of a matrix by a scalar.
    opdata ManageOps::doDiv(vector<opdata> op_datas){
        opdata res_div;
        try
        {  
        vector<vector<double> > temp1,temp2, tempres;
        double tempnum;
        MatrixOps mo;
        ScalarOps so;
        if (op_datas.size() == 2){
            if(op_datas[0].sc == true && op_datas[1].sc == false){
                tempnum = op_datas[0].v_data[0][0];
                temp1 = op_datas[1].v_data;
                tempres = so.getDiv(tempnum,temp1);
                res_div.v_data = tempres;
                res_div.sc = false;
            }
            else if(op_datas[0].sc == false && op_datas[1].sc == true){
                tempnum = op_datas[1].v_data[0][0];
                temp1 = op_datas[0].v_data;
                tempres = so.getDiv(tempnum,temp1);
                res_div.v_data = tempres;
                res_div.sc = false;
            }
            else{
                LoggerAns l;
                l.logg("Error : Division not Possible");
            }
            // }
        }
        else{
            LoggerAns l ;
            l.logg("Error : operand missing");
        }
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
        return res_div;
        
    }
    
    // method for determining transpose 
    opdata ManageOps::doTranspose(vector<opdata> op_datas){

        opdata res_tr;
	try
        {
        
        vector<vector<double> > temp, tempres;
        MatrixOps mo;
        ScalarOps so;
        if (op_datas.size() == 1){
            if(op_datas[0].sc == false){
                temp = op_datas[0].v_data;
                tempres = mo.getTranspose(temp);
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
        
        }
        catch(const std::exception& e)
        {
             LoggerAns l;
            l.logg( e.what());
        }
        return res_tr;
    
        }
    
    // method for finding determinant     
    opdata ManageOps::doDet(vector<opdata> opdatas){
        opdata calc_res;
        try
        {
        vector<double> vd;
        vector<vector<double> > temp = opdatas[0].v_data;
        MatrixOps mo;
        ScalarOps so;
        if ( temp.size() == temp[0].size()){
            int s = temp.size();
            double res = mo.getDet(temp);
            // cout <<res;
            vd.push_back(res);
            calc_res.sc = true ;
            calc_res.v_data.push_back(vd);
        }
        else {
            LoggerAns l ;
            l.logg("Error : Determinant is not computable . not a sqaure matrix");
            exit(1);
            //cout<< " det is not computable ";
        }
        
        }
        catch(const std::exception& e)
        {
            LoggerAns l;
            l.logg( e.what());
            exit(1);
        }
        return calc_res;
    
        }

/*
class ManageOps{

    public: 

    opdata res;
    // method for decode command line options .
    string decode_cmd_opt(int argc , char * argv[]){
        try
            {
                
        string cmd_opt;
        for(int i=1;i<argc;i++){
            cmd_opt +=  argv[i]+1; 
        }
        return cmd_opt;
        }
            catch(const std::exception& e)
            {
                Logger l;
                l.logg( e.what());
                exit(1);
            }
    }
    // method for getting operands from input 
    vector<opdata> get_operands(int i , char sw){
        try
        {
        vector<opdata> v;
        opdata temp1;
            
        char op_type ;
        // 't' and 'x' is unary operation else binary operation . 
        // based on operation type , operand fetch will take place . 
        if (sw == 't' || sw == 'x')
        op_type = 'u';
        else
        op_type = 'b';

        if (op_type =='u' && i==0){
            ExtractOps e;
            temp1 = e.extract_data();
            v.push_back(temp1);
        }
        else if (op_type =='u' && i!=0){
            v.push_back(res);
        }
        else if (op_type =='b' && i==0){
            ExtractOps e;
            temp1 = e.extract_data();
            v.push_back(temp1);
            temp1 = e.extract_data();
            v.push_back(temp1);
        }
        else if (op_type =='b' && i!=0){
            v.push_back(res);
            ExtractOps e;
            temp1 = e.extract_data();
            v.push_back(temp1);
        }
        else {
            Logger l;
            l.logg("Error : Data extraction error. ") ;
            exit(1);
        }
        

        return v;
        }
            catch(const std::exception& e)
            {
                Logger l;
                l.logg( e.what());
                exit(1);
            }
        }

    //method to display output of a result .
    int display(opdata r){
        try
        {
        vector<vector<double> > temp = r.v_data;
        if (r.sc == 0){
        cout << '\n' << temp.size() << " " << temp[0].size() <<'\n';
        for( int i=0; i<temp.size();i++){
            for(int j=0;j<temp[0].size();j++){
                cout<<temp[i][j]<<",";
            }
            cout<<'\n';
        }
        }
        else if (r.sc == 1){
            cout<<'\n'<<temp[0][0]<<'\n';
        }        
        }
            catch(const std::exception& e)
            {
                Logger l;
                l.logg( e.what());
            }
        
        return 0;
    }

    // method for perform cmd operations .
    int perf_cmd_ops(string cmd_opt){
        try
            {
            int l= cmd_opt.length();
            //for each cmd options perform operations 
            for( int i=0; i<l ; i++){
            char sw = cmd_opt[i];
            
            switch (sw){
                // for option 'a' perform addition.
                case 'a':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    MatrixOps m;
                    res = doAdd(op_datas);
                    display(res);
                    break;
                }
                //for option 's' perform subtraction
                case 's':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    MatrixOps m;
                    res = doSub(op_datas);
                    display(res);
                    break;                
                }
                // for option 'm' perform multiplication
                case 'm':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    MatrixOps m;
                    res = doMul(op_datas);
                    display(res);
                    break; 
                }
                // for option 'd' perform division
                case 'd':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    MatrixOps m;
                    res = doDiv(op_datas);
                    display(res);
                    break;
                }
                // for option 't' perform transpose
                case 't':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    MatrixOps m;
                    res = doTranspose(op_datas);
                    display(res);
                    break;
                }
                // for option 'x' perform determinant 
                case 'x':{
                    vector<opdata> op_datas = get_operands(i, sw);
                    MatrixOps m;
                    res = doDet(op_datas);
                    display(res);
                    break;
                }
                // for any other operation log error 
                default:{
                    Logger l;
                    l.logg("Error : undefined option\n");
                    break;
                }
            }
        }
        }
            catch(const std::exception& e)
            {
                Logger l;
                l.logg( e.what());
            }
        return 0;
    }

};
*/
