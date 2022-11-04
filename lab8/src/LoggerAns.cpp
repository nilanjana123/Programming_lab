# include<bits/stdc++.h>
#include "LoggerAns.h"
using namespace std;

int LoggerAns::logg(std::string s){
    ofstream myfile;
    myfile.open ("../LOGG/logg.txt", std::ios_base::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    myfile <<"\nAt time : "<<dt << "log message : "<<s <<"\n";
    myfile.close();
    exit(1);
    return 0;
    }
