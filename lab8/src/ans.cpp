# include<bits/stdc++.h>
#include "dt.h"
#include "LoggerAns.h"
#include "ExtractOps.h"
#include "MatrixOps.h"
#include "ManageOps.h"
using namespace std;

int main(){
    try
    {
    ManageOps mn;
    //decode command line options  and perform required operation
    string cmd_opt = mn.decode_cmd_opt();
    cout<< "# cmd options :"<<cmd_opt;
    mn.perf_cmd_ops(cmd_opt);
    }
    catch(const std::exception& e)
    {
        LoggerAns l;
        l.logg( e.what());
        exit(1);
    }
    return 0;
}