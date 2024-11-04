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
    
    intervalProbDataStore[intervalSize-1].second = 1000;
    
    
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
    disProbDataStore[disDataSize-1].second = 100; 
    // Random digit arrival calculation 
    
    int randomDigitArrivalSize;
    cout<<"Enter random digit arrival size:";
    cin>>randomDigitArrivalSize;
    
    int randomDigitArrivalData[randomDigitArrivalSize];
    for(int i = 0;i<randomDigitArrivalSize; i++){
      cout<<"enter data for random digit arrival:"<<i+1<<":";
      cin>>randomDigitArrivalData[i];
    }
    
    cout<<"\n---------solution three----------"<<endl;
    //caculating random digit arrival
    cout<<"|\t C \t"<<"|\t R.D \t"<<"|\t T.B.A  |"<<endl;
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
     cout<<"\n\n"<<endl;
    //calculate random digit for service
     int randomDigitServiceSize;
     cout<<"Enter size of random digit service size:";
     cin>>randomDigitServiceSize;
     int randomDigitServiceData[randomDigitServiceSize];
     int randomDigitServiceDataCalculated[randomDigitServiceSize];
     
     for(int i = 0; i<randomDigitServiceSize; i++){
          cout<<"Enter random digit service for "<<i+1<<":";
          cin>>randomDigitServiceData[i];
     }
     
     cout<<"\n\n---------solution four-----------"<<endl;
     cout<<"|\t C \t"<<"|\t R.D \t"<<"|\t S.T  \t|"<<endl;
     
     for(int i = 0; i<randomDigitServiceSize; i++){
          for(int j = 0; j<disDataSize; j++){
               if(disProbDataStore[j].first<=randomDigitServiceData[i] && randomDigitServiceData[i] <= disProbDataStore[j].second){
                    randomDigitServiceDataCalculated[i] = j+1;
                    break;
               }
          }
          
          cout<<"|\t "<<i+1<<" \t"<<"|\t  "<<randomDigitServiceData[i]<<"  \t"<<"|\t  "<<randomDigitServiceDataCalculated[i]<<"  \t|"<<endl;
     }
    //end calculation
     
     //main table calculation
     int atCommulative = 0;
     int stCommulative = 0;
     int tse = randomDigitServiceDataCalculated[0];
     int tsb = 0;
     int wt = 0;
     int tss = 0;
     int its = 0;
     cout<<"\n\n-----------------------------------------final table-----------------------------------------------------"<<endl;
     cout<<"|\t C \t"<<"|\t I.A.T \t"<<"|\t A.T \t"<<"|\t S.T \t"<<"|\t T.S.B \t"<<"|\t W.T \t"<<"|\t T.S.E \t"<<"|\t T.S.S \t"<<"|\t I.T.S \t|"<<endl;
     for(int i = 0; i<randomDigitServiceSize; i++){
      if(i<1){
         cout<<"|\t"<<i+1<<"\t"<<"|\t   "<<"-"<<"   \t"<<"|\t "<<atCommulative<<"  \t"<<"|\t "<<randomDigitServiceDataCalculated[i]<<"\t\t"<<"|\t   "<<0<<"   \t"<<"|\t  "<<0<<" \t"<<"|\t   "<<tse<<"   \t"<<"|\t   "<<randomDigitServiceDataCalculated[i]<<"   \t"<<"|\t   "<<0<<"   \t|"<<endl;
      }else{
          atCommulative += randomDigitArrivalCalculatedData[i-1];
          tsb = max(tse,atCommulative);
          its = tsb-tse;
          tse = randomDigitServiceDataCalculated[i]+tsb;
          wt = tsb-atCommulative;
          tss = tse-atCommulative;
          
          cout<<"|\t"<<i+1<<"\t"<<"|\t   "<<randomDigitArrivalCalculatedData[i-1]<<"   \t"<<"|\t "<<atCommulative<<"  \t"<<"|\t "<<randomDigitServiceDataCalculated[i]<<"\t\t"<<"|\t   "<<tsb<<"   \t"<<"|\t  "<<wt<<" \t"<<"|\t   "<<tse<<"   \t"<<"|\t   "<<tss<<"   \t"<<"|\t   "<<its<<"   \t|"<<endl; 
      }
     }
    return 0;
}

