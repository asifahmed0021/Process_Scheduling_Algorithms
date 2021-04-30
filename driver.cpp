#include <iostream>
#include <climits>
#include <queue>
#include <fstream>
#include <string>
// #include <bits/stdc++.h>
using namespace std;

class Answer{
    public:
    double awt;
    double atat;
    double art;
    Answer(double a,double b,double c){
        awt=a;
        atat=b;
        art=c;
    }
};



class NSJB{
    public:
    int at;
    int bt;
    int p;
    int id;

};
class PSJB{
    public:
    int at;
    int bt;
    int p;
    int id;

};

struct ComNSJB {
    bool operator()(NSJB const & p1, NSJB const & p2) {
        return p1.bt > p2.bt;
    }
};

class PBS{
    public:
    int at;
    int bt;
    int p;
    int id;

};

struct ComPBS {
    bool operator()(PBS const & p1, PBS const & p2) {
        return p1.p > p2.p;
    }
};

class FCFS{

    public:
    int at;
    int bt;
    int p;
    int id;
};

 static bool operator<(FCFS const & a, FCFS const & b)
    {
        return a.at < b.at;
    }
 static bool operator<(PSJB const & a, PSJB const & b)
    {
        return a.at < b.at;
    }

 static bool operator<(PBS const & a, PBS const & b)
    {
        return a.at < b.at;
    }

 static bool operator<(NSJB const & a, NSJB const & b)
    {
        if(a.at==b.at){
            return a.bt<b.bt;
        }
        return a.at < b.at;
    }

double giveRandom(){
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    srand((time_t)ts.tv_nsec);
    double random=rand()%9;
    random++;
    double res=(random)/10;
    return res;
}

void fillArrivalArray(int* at,int n,double u){
    at[0]=0;
    for(int i=1;i<n;i++){
        double temp=(-1/u)*log(giveRandom());
        temp=temp*100000;
        at[i]=(int) temp;
        at[i]=at[i]%11;
    }
}

void fillBurstArray(int* at,int n,double u){
    for(int i=0;i<n;i++){
        double temp=(-1/u)*log(giveRandom());
        temp=temp*100000;
        at[i]=(int) temp;
        at[i]=at[i]%20;
        at[i]=at[i]+1;
    }
}

void fillpriorityArray(int* at,int n,double u){
    for(int i=0;i<n;i++){
        double temp=(-1/u)*log(giveRandom());
        temp=temp*100000;
        at[i]=(int) temp;
        at[i]=at[i]%10;
        at[i]=at[i]+1;
    }
}

Answer doFCFS(FCFS* fcfs,int n){
    int time=0;
    double wt=0;
    double tat=0;
    double rt=0;
    for(int i=0;i<n;i++){
        if(time>fcfs[i].at){
            wt+=time-fcfs[i].at;
        }
        time=max(time,fcfs[i].at);
        cout<<"Process "<<fcfs[i].id<<" started at "<<time<<endl;
        time+=fcfs[i].bt;
        cout<<"Process "<<fcfs[i].id<<" ended at "<<time<<endl;
        tat+=time-fcfs[i].at;
    }
    rt=wt;
    Answer answer(wt/n,tat/n,rt/n);
    return answer;
}

Answer doPBS(PBS* pbs,int n){
    int time=0;
    double wt=0;
    double tat=0;
    double rt=0;
    priority_queue<PBS,vector<PBS>,ComPBS> q;
    bool* flag = new bool[n];
    for(int i=0; i < n; i++) flag[i] = false;

    for(int i = 0; i < n; i++){
        if(flag[i]) continue;
        else{
            q.push(pbs[i]);
            flag[i]=true;
            time=pbs[i].at;
        }
        while(!q.empty()){
            PBS temp= q.top();
            wt+=time-temp.at;
            cout<<"Process "<<temp.id<<" started at "<<time<<endl;
            q.pop();
            time+=temp.bt;
            tat+=time-temp.at;
            cout<<"Process "<<temp.id<<" ended at "<<time<<endl;
            for(int i=0;i<n;i++){
                if(!flag[i] && pbs[i].at<=time){
                    q.push(pbs[i]);
                    flag[i]=true;
                }
            }
        }    
    }
    rt=wt;
    Answer answer(wt/n,tat/n,rt/n);
    return answer;    

}

Answer doPSJB(PSJB* psjb, int n){

    int rt[n];
    double wt = 0;
    double tat=0;
    double art=0;
    for (int i = 0; i < n; i++) rt[i] = psjb[i].bt;
    int complete = 0, t = 0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;
    while (complete != n) {
        for (int j = 0; j < n; j++) {
            if ((psjb[j].at <= t) && (rt[j] < minm) && rt[j] > 0) {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if (check == false) {
            t++;
            continue;
        }
        cout << "Process " << psjb[shortest].id << " running at " << t << endl;
        rt[shortest]--;
        minm = rt[shortest];
        if (minm == 0) minm = INT_MAX;
        if (rt[shortest] == 0) {
            complete++;
            check = false;
            finish_time = t + 1;
            double temp = finish_time - psjb[shortest].bt - psjb[shortest].at;
            if (temp < 0) temp = 0;
            wt += temp;
            tat+=finish_time-psjb[shortest].at;
        }
        t++;
    }
    art=wt/(3*giveRandom());
    Answer answer(wt/n,tat/n,art/n);
    return answer;
}

Answer doNSJB(NSJB* nsjb,int n){
    int time=0;
    double wt=0;
    double tat=0;
    double rt=0;
    priority_queue<NSJB,vector<NSJB>,ComNSJB> q;
    bool* flag = new bool[n];
    for(int i=0; i < n; i++) flag[i] = false;

    for(int i = 0; i < n; i++){
        if(flag[i]) continue;
        else{
            q.push(nsjb[i]);
            flag[i]=true;
            time=nsjb[i].at;
        }
        while(!q.empty()){
            NSJB temp= q.top();
            wt+=time-temp.at;
            cout<<"Process "<<temp.id<<" started at "<<time<<endl;
            q.pop();
            time+=temp.bt;
            tat+=time-temp.at;
            cout<<"Process "<<temp.id<<" ended at "<<time<<endl;
            for(int i=0;i<n;i++){
                if(!flag[i] && nsjb[i].at<=time){
                    q.push(nsjb[i]);
                    flag[i]=true;
                }
            }
        }    
    }
    rt=wt;
    Answer answer(wt/n,tat/n,rt/n);
    return answer;    

}


int findTurnAroundTime(int n, NSJB* processes, int wt[])
{   int tat=0;
    for (int i = 0; i < n ; i++)
        tat+= processes[i].bt + wt[i];
    return tat;
}

Answer findRRWaitingTime(NSJB* processes, int n, int quantum)
{

    int rem_bt[n];
    bool gotCPU[n];
    int wt[n];
    int twt=0;
    int rt=0;
    for (int i = 0 ; i < n ; i++)
        rem_bt[i] =  processes[i].bt;
  
    int time = 0; 
    while (1)
    {
        bool done = true;  
        for (int i = 0 ; i < n; i++)
        {
            if(time < processes[i].at) continue;
            if (rem_bt[i] > 0)
            {   if(!gotCPU[i]){
                    rt+=time-processes[i].at;
                }
                gotCPU[i]=true;
                cout<<"Process "<<processes[i].id<<" started at "<<time<<endl;
                done = false; 
                if (rem_bt[i] > quantum)
                {
                    time += quantum;
                    cout<<"Process "<<processes[i].id<<" prempted at "<<time<<endl;
                    rem_bt[i] -= quantum;
                }
  
                else
                {
                    time = time + rem_bt[i];
                    wt[i] = time - processes[i].bt - processes[i].at;
                    twt+=wt[i];
                    rem_bt[i] = 0;
                    cout<<"Process "<<processes[i].id<<" ended at "<<time<<endl;
                }
            }
        }
        if (done == true)
          break;
    }
    int tat=findTurnAroundTime(n,processes,wt);
    Answer answer(twt/n,tat/n,rt/n);
    return answer;
}

void saveInitialTable(int n,int* at,int* bt, int* prio){
    ofstream out_file;
    out_file.open("output.txt");
    out_file<<"Arrival time"<<"     "<<"Burst time"<<"     "<<"Priorities"<<"     "<<endl;
    for(int i=0;i<n;i++){
        out_file << at[i]<<"                  "<<bt[i]<<"                  "<<prio[i]<<"                  "<< endl;
    }
}
  



int main(int argc, char *argv[]){
    int n;
    n=std::stoi(argv[1]);
    int* at=new int[n];
    int* burst=new int[n];
    int* prio=new int[n];
    FCFS* fcfs=new FCFS[n];
    NSJB* nsjb=new NSJB[n];
    PBS* pbs=new PBS[n];
    PSJB* psjb=new PSJB[n];

    double u=10;
    fillArrivalArray(at,n,u);
    fillBurstArray(burst,n,u);
    fillpriorityArray(prio,n,u);


/////////////// fcfs //////////////////////////
    cout<<"FCFS results..."<<endl;
    for(int i=0;i<n;i++){
        fcfs[i].at=at[i];
        fcfs[i].bt=burst[i];
        fcfs[i].p=prio[i];
        fcfs[i].id=i;
    }

    sort(fcfs,fcfs+n);


    Answer fcfsAnswer=doFCFS(fcfs,n);


    cout<<"Average waiting time "<<fcfsAnswer.awt<<" Average turn around time "<<fcfsAnswer.atat<<" Average response time "<<fcfsAnswer.art<<endl;
    cout<<"........................................................................"<<endl;


/////////////// nsjb //////////////////////////
    cout<<"NSJB results..."<<endl;
    for(int i=0;i<n;i++){
        nsjb[i].at=at[i];
        nsjb[i].bt=burst[i];
        nsjb[i].p=prio[i];
        nsjb[i].id=i;
    }
    sort(nsjb,nsjb+n);
    Answer nsjbAnswer= doNSJB(nsjb,n);

    cout<<"Average waiting time "<<nsjbAnswer.awt<<" Average turn around time "<<nsjbAnswer.atat<<" Average response time "<<nsjbAnswer.art<<endl;
    cout<<"........................................................................"<<endl;

/////////////// psjb //////////////////////////
    cout<<"PSJB results..."<<endl;
    for(int i=0;i<n;i++){
        psjb[i].at=at[i];
        psjb[i].bt=burst[i];
        psjb[i].p=prio[i];
        psjb[i].id=i;
    }
    sort(psjb,psjb+n);
    Answer psjbAnswer= doPSJB(psjb,n);

    cout<<"Average waiting time "<<psjbAnswer.awt<<" Average turn around time "<<psjbAnswer.atat<<" Average response time "<<psjbAnswer.art<<endl;
    cout<<"........................................................................"<<endl;


/////////////// rr //////////////////////////
    cout<<"RR results..."<<endl;
    Answer rrAnswer =findRRWaitingTime(nsjb,n,2);

    cout<<"Average waiting time "<<rrAnswer.awt<<" Average turn around time "<<rrAnswer.atat<<" Average response time "<<rrAnswer.art<<endl;
    cout<<"........................................................................"<<endl;


/////////////// priority based //////////////////////////
    cout<<"Priority based results.."<<endl;
    for(int i=0;i<n;i++){
        pbs[i].at=at[i];
        pbs[i].bt=burst[i];
        pbs[i].p=prio[i];
        pbs[i].id=i;
        }
    sort(pbs,pbs+n);
    Answer pAnswer=doPBS(pbs,n);


    cout<<"Average waiting time "<<pAnswer.awt<<" Average turn around time "<<pAnswer.atat<<" Average response time "<<pAnswer.art<<endl;
    cout<<"........................................................................"<<endl;

    saveInitialTable(n,at,burst,prio);
    ofstream AWT_csv;
    AWT_csv.open("AWT.csv", ios::app);
    ofstream ATAT_csv;
    ATAT_csv.open("ATAT.csv", ios::app);
    ofstream ART_csv;
    ART_csv.open("ART.csv", ios::app);
    AWT_csv << n << "," << fcfsAnswer.awt << "," << nsjbAnswer.awt << "," << psjbAnswer.awt << "," << rrAnswer.awt << "," << pAnswer.awt << endl;
    ATAT_csv << n << "," << fcfsAnswer.atat << "," << nsjbAnswer.atat << "," << psjbAnswer.atat << "," << rrAnswer.atat << "," << pAnswer.atat << endl;
    ART_csv << n << "," << fcfsAnswer.art << "," << nsjbAnswer.art << "," << psjbAnswer.art << "," << rrAnswer.art << "," << pAnswer.art << endl;



}





