#include <iostream>
#include <string>
#include <fstream>
//#include <sstream>

using namespace std;

void read(double*, const string, int);
void filter(double*, int);
void print(double* , int);

int main(void){
int N=237; //wie N dynamisch?
const string filename= "noisy.txt";
double* pn=new double[N];
read(pn, filename, N);
filter(pn, N);
print(pn, N);
delete[] pn;
return 0;
}

void read(double* x, const string fname, int N){
ifstream in(fname.c_str());
for(int i=0;i<N;i++) in >> x[i];
in.close();
}


void filter(double* x, int N){
double temp2=x[0];
x[0]=(x[0]+x[1])/2;
for(int i=1;i<N-1;i++){


x[i]=(temp2+x[i]+x[i+1])/3;
temp2=x[i];
}
x[N-1]=(x[N-1]+temp2)/2;
}

void print(double* x , int N){
//for(int i=0;i<N;i++) cout << "pn[" << i << "]=" << pn[i] << endl;
ofstream out("filterdata");
for(int i=0;i<N;i++) out << x[i] << endl;
out.close();
}
