#ifndef MATRIXOPS_H
#define MATRIXOPS_H

class MatrixOps{
    public :
    // perform matrix-matrix addition .
    vector<vector<double> > getAdd(vector<vector<double> > arr1 , vector<vector<double> > arr2);

    // perform matrix-matrix subtraction .
    vector<vector<double> > getSub(vector<vector<double> > arr1 , vector<vector<double> > arr2);
    
    // Do matrix-matrix multiplication 
    vector<vector<double> > getMul(vector<vector<double> > arr1 , vector<vector<double> > arr2);

    // method for determining transpose .
    vector<vector<double> > getTranspose(vector<vector<double> > arr);

    // calculate Determinant of valid matrix.
    double getDet(vector<vector<double> > arr);
    
};

#endif