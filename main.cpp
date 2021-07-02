#include <iostream>
#include <iostream>
#include<fstream>
#include <cmath>
#include<math.h>
#include<iomanip>
#include<stdlib.h>

using namespace std;

//This is based on a thought experiment.

int main()
{
    double Tinf, Uinf, D, P, Pmax, i, n, q, u, k, Tf, R, Pr, Ndt, C1, C2, C3, Nde, h, A, L,Ts1, Ts2, Ts3, i, Ts;
    cout<<"Enter the value of Power supplied"<<endl;
    cin>>P;
    cout<<"Enter the value of maximum Power Rating"<<endl;
    cin>>Pmax;
    ofstream myfile;
    myfile.open("Different numbers of observations.csv");
    myfile <<"Experiment Number"<<","<<"Power Supplied"<<","<<"Theoretical Nusselt Number"<<","<<"Reynolds Number"<<","<<"Experimentally obtained Nusselt Number"<<endl;
    i =1;
    cout<<"Enter the values for "<<i<< " -th experiment"<<endl;
    for (P;P+5;P<Pmax)
 {
    cout<<"Enter the value of freestream temperature"<<endl;
    cin>>Tinf;
    cout<<"Enter the value of freestream Velocity"<<endl;
    cin>>Uinf;
    cout<<"Enter the value of diameter"<<endl;
    cin>>D;
    cout<<"Enter the value of power dissipation percentage"<<endl;
    cin>>n;
    cout<<"Enter the value of length of cylinder"<<endl;
    cin>>L;
    cout<<"Enter the value of first thermocouple temperature"<<endl;
    cin>>Ts1;
    cout<<"Enter the value of second thermocouple temperature"<<endl;
    cin>>Ts2;
    cout<<"Enter the value of third thermocouple temperature"<<endl;
    cin>>Ts3;
    Ts = (Ts1+Ts2+Ts3)/3;
    Tf = (Ts+Tf)/2;
    cout<<"Enter the value of kinematic viscosity at "<<Tf<<endl;
    cin>>u;
    cout<<"Enter the value of thermal conductivity at "<<Tf<<endl;
    cin>>k;
    R = (Uinf*D)/u;
    q = P*(1-n);
    A = 3.14*D*L;
    h = q/((Ts-Tinf)*A);
    cout<<"Enter the value of Prandtl number at "<<Tf<<endl;
    cin>>Pr;
    //We are using Churchill equation
    Nde = (h*D)/k;
    C1 = 0.62*(pow(R,0.5))*(pow(Pr,0.33));
    C2 = pow(1+pow((0.4/Pr),0.67),0.25);
    C3 = pow(1+pow((R/282000),0.62),0.8);
    Ndt = 0.3+ (C1*C3/C2);
    myfile <<i<<","<<P<<","<<Ndt<<","<<R<<","<<"Nde"<<endl;
    i++;
    cout<<"Enter the values for"<<i<< " -th experiment"<<endl;
}
    return 0;
}
