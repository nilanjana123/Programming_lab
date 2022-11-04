#ifndef MANAGEOPS_H
#define MANAGEOPS_H
#include "dt.h"
class ManageOps{

    public: 

    opdata res;
    // method for decode command line options .
    string decode_cmd_opt();
    // method for getting operands from input 
    vector<opdata> get_operands(int i , char sw);

    //method to display output of a result .
    int display(opdata r);

    // method for perform cmd operations .
    int perf_cmd_ops(string cmd_opt);

    opdata doAdd(vector<opdata> op_datas);

    // perform subtraction operation . 
    opdata doSub(vector<opdata> op_datas);

    // Do multiplication operation . 
    opdata doMul(vector<opdata> op_datas);

    // method for calculating Division of a matrix by a scalar.
    opdata doDiv(vector<opdata> op_datas);

    // method for determining transpose 
    opdata doTranspose(vector<opdata> op_datas);

    // method for finding determinant     
    opdata doDet(vector<opdata> opdatas);


};
#endif