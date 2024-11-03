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
      intervalData[i] = i+1;
      probData[i] = 0.125;
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
    
    intervalProbDataStore[7].second = 1000;
    
    
    
    
    cout<<"----------------------------------------------------------------"<<endl;
    
    int disDataSize;
    cout<<"enter Distribution service size:";
    cin>>disDataSize;
    int disTimeData[disDataSize];
    double probDisData[disDataSize];
    pair<int, int> disProbDataStore[disDataSize];
    
    
    // Distribution of service time  and prob data
    for(int i = 0; i<disDataSize; i++){
      disTimeData[i] = i+1;
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
    
    // Random digit arrival calculation 
    
    int randomDigitArrivalSize;
    cout<<"Enter random digit arrival size:";
    cin>>randomDigitArrivalSize;
    
    int randomDigitArrivalData[randomDigitArrivalSize];
    for(int i = 0;i<randomDigitArrivalSize; i++){
      cout<<"enter data for random digit arrival:"<<i+1<<":";
      cin>>randomDigitArrivalData[i];
    }
    
    cout<<"\n------------solution three------------"<<endl;
    //caculating random digit arrival
    cout<<"|\t c \t"<<"|\t R.d \t"<<"|\t t.b.a  |"<<endl;
    cout<<"|\t 1 \t"<<"|\t  -  \t"<<"|\t   -   \t|"<<endl;
    int randomDigitArrivalCalculatedData[randomDigitArrivalSize-1];
    for(int i = 0; i<randomDigitArrivalSize; i++){
     for(int j = 0; j<intervalSize; j++){
        if(intervalProbDataStore[j].first<= randomDigitArrivalData[i] && randomDigitArrivalData[i] <= intervalProbDataStore[j].second){
          randomDigitArrivalCalculatedData[i] = j+1;
          break;
        }
     }
     cout<<"|\t "<< i+2 <<" \t"<<"|\t "<<randomDigitArrivalData[i]<<" \t"<<"|\t   "<<randomDigitArrivalCalculatedData[i]<<"   \t|"<<endl;
    }
    
    // Random digit arrival calculation end
    return 0;
}

