#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
void harmonic(double a[],int N, int M);
void var_harmonic(double a[],int N, int M);
void binary(double a[],int N, int M);
void display(double a[],int N);
void average(int,int,int);
int main() {
 int N;
 cout << "Enter the number of elements\n";
 cin >> N;
 double a[N];
 int b[N];
 srand(time(NULL));
 int i = 0;
 for (; i < N; i++) {
 b[i] = rand() % 100;
 if(b[i]==0) b[i] = b[i]+1;
 a[i] = b[i] / 100.0;
 }
 cout << "Enter number of partitions\n";
 int M ; cin>>M;
 char choice = 'y'; int option ;
 do
 {
 cout << "Menu\n";
 cout << "1.Display\n2.Harmonic Bin Packing(Lee and Lee)\n3.Variable Harmonic Bin Packing(Epstein)\n4.Kth Binary Packing\n5.Exit\n";
 cout << "Enter you option\n"; cin >> option;
 switch (option)
 {
 case 1 : display(a,N);break;
 case 2 : harmonic(a,N,M); break;
 case 3 : var_harmonic(a,N,M);break;
 case 4 : binary(a,N,M); break;
 case 5 : exit(0);
 default: cout << "Wrong option entered\n";
 }
 cout << "Do you want to continue(Y/N)\n";
 cin >> choice;
 }while(choice=='y'||choice=='Y');
 return 0;
}
void display(double a[],int N)
{
 int i =0;
 cout << "Numbers are\n";
 for(;i<N;i++)
 {
 cout << a[i] << endl;
 }
 cout << endl;
}
void average(int NB[],int TB,int M)
{
 double average=0; int i =0;
 for(i=0;i<M;i++) cout << endl << NB[i];
 cout << endl;
 for(i=0;i<M;i++)
 {
 average = average + (NB[i]-(TB/M))*(NB[i]-(TB/M));
 cout << average << endl;
 }
 cout << "\nAvergae bins are " << average/TB;
}
void harmonic(double a[],int N,int M)
{
 int i = 0 ;
 int temp = M;
 double partition[M];
 for(i=0;i<M;i++)
 {
 partition[i] = 1.0/temp;
 temp = temp-1;
 }
 double bin[M][N][N];
 double sum1[M][N][N];
 int j, k,p,q,r;
 for(k=0;k<M;k++)
 {
 for(j=0;j<N;j++)
 {
 for(i=0;i<N;i++)
 {
 bin[k][j][i]=0;
 sum1[k][j][i]=0;
 }
 }
 }
 for(i=0;i<N;i++)
 {
 for(j=0;j<M;j++)
 {
 if(a[i]<=partition[j])
 {
 for(k=0;k<N;k++)
 {
 if(a[i]<=1-sum1[j][k][0])
 {
 sum1[j][k][0] = sum1[j][k][0]+a[i];
 for(p=0;p<N;p++)
 {
 if(bin[j][k][p]==0)
 {
 bin[j][k][p]=a[i];
 break;
 }
 }
break;
 }
 }
 break;
 }
 }
 }
 cout << endl;
 int count=0;int num_bins[M];
 for(i=0;i<M;i++) num_bins[i]=0;
 for(i=0;i<M;i++)
 {
 cout << "Partition-" << i+1 << endl;
 for(j=0;j<N;j++) {
 if (bin[i][j][0] != 0) {
 cout << "Bin" <<j+1 <<" ";
 for(k=0;k<N;k++)
 {
 if(bin[i][j][k]!=0)
 {
 cout << bin[i][j][k] << " ";
 }
 }
 num_bins[i]++;
 count++;
 cout << endl;
 }
 }
 cout << endl;
 }
 cout << "No of bins used are " << count;
 average(num_bins,count,M);
 cout << endl;
}
void var_harmonic(double a[],int N,int M)
{
 int i=0;
 int temp = M;
 double partition[M];
 for(i=0;i<M;i++)
 {
 partition[i] = 1.0/temp;
 temp = temp-1;
 }
 double bin[M][N][N];
 double sum1[M][N][N];
 int j, k,p,q,r;
 for(k=0;k<M;k++)
 {
 for(j=0;j<N;j++)
 {
 for(i=0;i<N;i++)
 {
 bin[k][j][i]=0;
 sum1[k][j][i]=0;
 }
 }
 }
 for(i=0;i<N;i++)
 {
 for(j=0;j<M;j++)
 {
 if(a[i]<=partition[j])
 {
 for(k=0;k<N;k++)
 {
 if(a[i]<=1-sum1[j][k][0])
 {
 for(p=0;p<N;p++)
 {
 if(bin[j][k][p]==0 && p<M-j)
 {
 bin[j][k][p]=a[i];
sum1[j][k][0] = sum1[j][k][0]+a[i];
 break;
 }
 }
 break;
 }
 }
 break;
 }
 }
 }
 cout << endl;
 int count=0;int num_bins[M];
 for(i=0;i<M;i++) num_bins[i]=0;
 for(i=0;i<M;i++)
 {
 cout << "Partition-" << i+1 << endl;
 for(j=0;j<N;j++) {
 if (bin[i][j][0] != 0) {
 cout << "Bin" <<j+1 <<" ";
 for(k=0;k<N;k++)
 {
 if(bin[i][j][k]!=0)
 {
 cout << bin[i][j][k] << " ";
 }
 }
 num_bins[i]++;
 count++;
 cout << endl;
 }
 }
 cout << endl;
 }
 cout << "No of bins used are " << count+1;
 average(num_bins,count,M);
 cout << endl;
}
void binary(double a[],int N,int M)
{
 int i = 0;
 int temp = M; int div;
 double partition[M];
 for(i=0;i<M;i++)
 {
 div = pow(2,temp-1);
 partition[i] = 1.0/div;
 temp = temp-1;
 }
 double bin[M][N][N];
 double sum1[M][N][N];
 int j, k,p,q,r;
 for(k=0;k<M;k++)
 {
 for(j=0;j<N;j++)
 {
 for(i=0;i<N;i++)
 {
 bin[k][j][i]=0;
 sum1[k][j][i]=0;
 }
 }
 }
 for(i=0;i<N;i++)
 {
 for(j=0;j<M;j++)
 {
 if(a[i]<=partition[j])
 {
 for(k=0;k<N;k++)
 {
 if(a[i]<=1-sum1[j][k][0])
 {
 sum1[j][k][0] = sum1[j][k][0]+a[i];
 for(p=0;p<N;p++)
 {
 if(bin[j][k][p]==0)
 {
 bin[j][k][p]=a[i];
 break;
 }
 }
break;
 }
 }
 break;
 }
 }
 }
 cout << endl;
 int count=0;;int num_bins[M];
 for(i=0;i<M;i++) num_bins[i]=0;
 for(i=0;i<M;i++)
 {
 cout << "Partition-" << i+1 << endl;
 for(j=0;j<N;j++) {
 if (bin[i][j][0] != 0) {
 cout << "Bin" <<j+1 <<" ";
 for(k=0;k<N;k++)
 {
 if(bin[i][j][k]!=0)
 {
 cout << bin[i][j][k] << " ";
 }
 }
 num_bins[i]++;
 count++;
 cout << endl;
 }
 }
 cout << endl;
 }
 cout << "No of bins used are " << count;
 average(num_bins,count,M);
 cout << endl;
}
