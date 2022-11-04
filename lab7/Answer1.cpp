# include<bits/stdc++.h>
// #include "ExtractOps.h"
// #include "Logger.h"

using namespace std;

//user defined data type 
struct opdata
{
    bool sc;      
    vector<vector<double> > v_data;
};

// Logger class performs logging activities.
class Logger{
    public :
    int logg(string s){
    ofstream myfile;
    myfile.open ("logg.txt", std::ios_base::app);
    time_t now = time(0);
    char* dt = ctime(&now);
    myfile <<"\nAt time : "<<dt << "log message : "<<s <<"\n";
    myfile.close();
    return 0;
    }
};

// ExtractOps class performs data extraction from input 
class ExtractOps{
    public:
    // mathod for data extraction from input 
    opdata extract_data(){
    
    try
    {

    opdata op1;    
    string  str1;

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

    return op1;
        }
    catch(const std::exception& e)
    {
        Logger l;
        l.logg( e.what());
    }
    }

};

// MatrixOps class performs matrix operations
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
                }
                }
            else{
                Logger l;
                    l.logg("Error : Addition not possible , No matrix found");
            }
            // }
        }
        else{
           Logger l;
                    l.logg("Error : Addition not possible , operand missing .");
        }
        return res_add;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
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
                }
                
            }
            else{
                Logger l;
                l.logg("Error : Subtraction not possible , No matrix found .");
            }
            // }
        }
        else{
            Logger l;
            l.logg("Error : Subtraction not possible , operand missing .");
        }
        return res_sub;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
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
                }
                }
            else{
                Logger l ;
                l.logg(" Error : Multiplication not possible , No matrix found .");
            }
            // }
        }
        else{
            Logger l ;
            l.logg("Error :  Multiplication not possible , operand Missing.");
        }
        return res_mul;
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
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
            //cout<< " det is not computable ";
        }
        return calc_res;
    
        }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
        }
        }

};

// ManageOps class manages the operations 
class ManageOps:ExtractOps,MatrixOps{

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
        temp1 = ExtractOps::extract_data();
        v.push_back(temp1);
    }
    else if (op_type =='u' && i!=0){
        v.push_back(res);
    }
    else if (op_type =='b' && i==0){
        // ExtractOps e;
        temp1 = ExtractOps::extract_data();
        v.push_back(temp1);
        temp1 = ExtractOps::extract_data();
        v.push_back(temp1);
    }
    else if (op_type =='b' && i!=0){
        v.push_back(res);
        temp1 = ExtractOps::extract_data();
        v.push_back(temp1);
    }
    else {
        Logger l;
        l.logg("Error : Data extraction error. ") ;
    }
    

    return v;
    }
        catch(const std::exception& e)
        {
             Logger l;
            l.logg( e.what());
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
                res = MatrixOps::doAdd(op_datas);
                display(res);
                break;
            }
            //for option 's' perform subtraction
            case 's':{
                vector<opdata> op_datas = get_operands(i, sw);
                res = MatrixOps::doSub(op_datas);
                display(res);
                break;                
            }
            // for option 'm' perform multiplication
            case 'm':{
                vector<opdata> op_datas = get_operands(i, sw);
                res = MatrixOps::doMul(op_datas);
                display(res);
                break; 
            }
            // for option 'd' perform division
            case 'd':{
                vector<opdata> op_datas = get_operands(i, sw);
                res = MatrixOps::doDiv(op_datas);
                display(res);
                break;
            }
            // for option 't' perform transpose
            case 't':{
                vector<opdata> op_datas = get_operands(i, sw);
                res = MatrixOps::doTranspose(op_datas);
                display(res);
                break;
            }
            // for option 'x' perform determinant 
            case 'x':{
                vector<opdata> op_datas = get_operands(i, sw);
                res = MatrixOps::doDet(op_datas);
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

int main(int argc , char * argv[]){
    try
    {
    ManageOps mn;
    //decode command line options  and perform required operation
    string cmd_opt = mn.decode_cmd_opt(argc , argv);
    cout<< cmd_opt;
    mn.perf_cmd_ops(cmd_opt);
    }
    catch(const std::exception& e)
    {
        Logger l;
        l.logg( e.what());
    }
    return 0;
}