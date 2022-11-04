#include<bits/stdc++.h>
#include "dt.h"
#include "LoggerAns.h"
#include "ExtractOps.h"


opdata ExtractOps::extract_data(){
    opdata op1;    
    string  str1;

    try
    {
    while(getline(cin, str1)){
            if (str1[0] != '#'){
            double num = 0;
            int dim[2];
            int dimc=0; 
            bool dimf = false;
            double n = str1.length();
            for (int i = 0; i < n; i++) {
                if(str1[i]==' '){
                    dim[dimc] = num;
                    num = 0;
                    dimf = true;
                    dimc++;
                }
                else
                num = num * 10 + (double(str1[i]) - 48); 
            }
            if (dimf == true){
                dim[dimc] = num;
                
                vector<double> temp1;
                vector<vector<double> >temp2;
                string str2;

                for (int i=0; i<dim[0]; i++){
                    double num1=0;
                    getline(cin,str2);
                    //cout<<"str2: "<<str2<<"\n";
                    for (int j=0,k=0; j<=str2.size() && k<dim[1]; j++){
                        if (str2[j]==','){
                            temp1.push_back(num1);
                            k++;
                            num1 =0;
                        }
                        else{
                            num1= num1 * 10 + (double(str2[j] - '0'));
                        }
                    }
                    temp2.push_back(temp1);
                    temp1.clear();
                }
                op1.sc = false;
                op1.v_data = temp2;
                temp2.clear();
                break;
            }
            else {
                if (n > 0){
                vector<double> temp1;
                vector<vector<double> >temp2;
                temp1.push_back(num);
                temp2.push_back(temp1);
                op1.sc = true;
                op1.v_data = temp2;
                temp1.clear();
                temp2.clear();
                break;
                }
            }
                   
            
            }}

        }
    catch(const std::exception& e)
    {
        LoggerAns l;
        l.logg( e.what());
    }
        return op1;

    }
