#include<bits/stdc++.h> 
using namespace std;
int main(){
float Basic, HRA, DA, CM, Tax, PF, TA, Total_Salary;
printf("\n Please Enter the Basic Salary of an Employee : ");
cin>>Basic;
HRA = (Basic * 3) / 100;
DA = (Basic * 8) / 100;
CM = 100;
Tax = 300;
PF = 780;
TA = 800;
cout<<"HRA: "<<HRA<<", DA: "<<DA<<", CM: "<<CM<<", Tax: "<<Tax<<", PF: "<<PF<<", TA: "<<TA;
Total_Salary = (Basic + HRA + DA + TA) - (Tax + CM + PF);
printf("\n Total Salary of this Employee = %.2f", Total_Salary);
return 0;
}

