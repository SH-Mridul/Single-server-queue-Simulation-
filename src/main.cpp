#include <bits/stdc++.h>
using namespace std;

int main() {

    int intervalSize;
    cout<<"enter interval size:";
    cin>>intervalSize;
    int intervalData[intervalSize];
    double probData[intervalSize];
    pair<int, int> intervalProbDataStore[intervalSize];
    
    //taking interval and prob data
    for(int i = 0; i<intervalSize; i++){
      cout<<"Enter interval data for "<<i+1<<":";
      cin>>intervalData[i];
      
      cout<<"Enter probability data for "<<i+1<<":";
      cin>>probData[i];
    }
    
   
    //Calculate arrival and service time table and get the random number assignment 
    double ca = 0;
    int caIntTrac = 000;
    cout<<"\n\n\n---------------- solution one -------------------"<<endl;
    cout<<"|\tT.B.V\t"<<"|"<<"\tProb\t"<<"|"<<"\tC.P\t\t"<<"|"<<"\tR.D.A\t"<<"|"<<endl;
    for (int i = 0; i < intervalSize; i++)
    {
      ca += probData[i];
      
      if((i+1) == intervalSize)
         ca = 0;
    
    
      cout<<"|\t"<<intervalData[i]<<"\t\t"<<"|"<<"\t"<<fixed<<setprecision(3)<<probData[i]<<"\t"<<"|"<<"\t"<<ca<<"\t"<<"|"<<"\t"<<caIntTrac<<"-"<<static_cast<int>(ca * 1000)<<"\t"<<"|"<<endl;
      intervalProbDataStore[i] = {caIntTrac,static_cast<int>(ca * 1000)};
      caIntTrac = static_cast<int>(ca * 1000)+1;
    }
    
    
    
    
    
    cout<<"----------------------------------------------------------------"<<endl;
    
    int disDataSize;
    cout<<"enter Distribution service size:";
    cin>>disDataSize;
    int disTimeData[disDataSize];
    double probDisData[disDataSize];
    pair<int, int> disProbDataStore[disDataSize];
    
    
    // Distribution of service time  and prob data
    for(int i = 0; i<disDataSize; i++){
      cout<<"Enter dis. ser. time data for "<<i+1<<":";
      cin>>disTimeData[i];
      
      cout<<"Enter prob. ser. time data for "<<i+1<<":";
      cin>>probDisData[i];
    }
    
   
    //Calculate service time distribution and assign a random number 
    double disCa = 0;
    int disCaIntTrac = 000;
    cout<<"\n\n\n---------------- solution two -------------------"<<endl;
    cout<<"|\tS.T\t\t"<<"|"<<"\tProb\t"<<"|"<<"\tC.P\t\t"<<"|"<<"\tR.D.A\t"<<"|"<<endl;
    for (int i = 0; i < disDataSize; i++)
    {
      disCa += probDisData[i];
      
      if((i+1) == disDataSize)
         disCa = 0;
    
    
      cout<<"|\t"<<disTimeData[i]<<"\t\t"<<"|"<<"\t"<<fixed<<setprecision(2)<<probDisData[i]<<"\t"<<"|"<<"\t"<<disCa<<"\t"<<"|"<<"\t"<<disCaIntTrac<<"-"<<static_cast<int>(disCa * 100)<<"\t"<<"|"<<endl;
      disProbDataStore[i] = {disCaIntTrac,static_cast<int>(disCa * 100)};
      disCaIntTrac = static_cast<int>(disCa * 100)+1;
    }
    
    
    
    
    return 0;
}

