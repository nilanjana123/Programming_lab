#ifndef SCALAROPS_H
#define SCALAROPS_H

class ScalarOps{
    public :
    // perform scalar- matrix Addition . 
    vector<vector<double> > getAdd(double num , vector<vector<double> > arr);

    // perform scalar- matrix subtraction . 
    vector<vector<double> > getSub(double num , vector<vector<double> > arr);

    // do scalar-matrix multiplication .
    vector<vector<double> > getMul(double num , vector<vector<double> > arr);

    // method for matrix Division 
    vector<vector<double> > getDiv(double num , vector<vector<double> > arr);

};

#endif