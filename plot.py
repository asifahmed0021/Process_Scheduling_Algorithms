import csv
import matplotlib.pyplot as plt
data=[]
fcfs=[]
nsjb=[]
psjb=[]
rr=[]
pbs=[]
n_array=[10,20,30,40,50]

with open('ART.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        temp=[]
        for num in row:
            temp.append(float(num))
        data.append(temp)

sum=[0,0,0,0,0]
for i in range(len(data)):
    for j in range(5):
        sum[j]+=float(data[i][j+1])
    if(i!=0 and i%10==9):
        # print(sum)
        fcfs.append(sum[0]/10)
        nsjb.append(sum[1]/10)
        psjb.append(sum[2]/10)
        rr.append(sum[3]/10)
        pbs.append(sum[4]/10)
        sum=[0,0,0,0,0]
    

plt.plot(n_array,fcfs,label="FCFS")
plt.plot(n_array,nsjb,label="NSJB")
plt.plot(n_array,psjb,label="PSJB")
plt.plot(n_array,rr,label="RR")
plt.plot(n_array,pbs,label="PBS")
plt.title("Average response time of 5 scheduling algorithms")
plt.xlabel("Number of processes")
plt.ylabel("Average response time")
plt.legend(loc='best')
plt.show()


#######################################

data=[]
fcfs=[]
nsjb=[]
psjb=[]
rr=[]
pbs=[]
n_array=[10,20,30,40,50]

with open('ATAT.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        temp=[]
        for num in row:
            temp.append(float(num))
        data.append(temp)

sum=[0,0,0,0,0]
for i in range(len(data)):
    for j in range(5):
        sum[j]+=float(data[i][j+1])
    if(i!=0 and i%10==9):
        # print(sum)
        fcfs.append(sum[0]/10)
        nsjb.append(sum[1]/10)
        psjb.append(sum[2]/10)
        rr.append(sum[3]/10)
        pbs.append(sum[4]/10)
        sum=[0,0,0,0,0]
    

plt.plot(n_array,fcfs,label="FCFS")
plt.plot(n_array,nsjb,label="NSJB")
plt.plot(n_array,psjb,label="PSJB")
plt.plot(n_array,rr,label="RR")
plt.plot(n_array,pbs,label="PBS")
plt.title("Average turn around time of 5 scheduling algorithms")
plt.xlabel("Number of processes")
plt.ylabel("Average turn around time")
plt.legend(loc='best')

plt.show()


#################################################


data=[]
fcfs=[]
nsjb=[]
psjb=[]
rr=[]
pbs=[]
n_array=[10,20,30,40,50]

with open('AWT.csv') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=',')
    for row in csv_reader:
        temp=[]
        for num in row:
            temp.append(float(num))
        data.append(temp)

sum=[0,0,0,0,0]
for i in range(len(data)):
    for j in range(5):
        sum[j]+=float(data[i][j+1])
    if(i!=0 and i%10==9):
        # print(sum)
        fcfs.append(sum[0]/10)
        nsjb.append(sum[1]/10)
        psjb.append(sum[2]/10)
        rr.append(sum[3]/10)
        pbs.append(sum[4]/10)
        sum=[0,0,0,0,0]
    

plt.plot(n_array,fcfs,label="FCFS")
plt.plot(n_array,nsjb,label="NSJB")
plt.plot(n_array,psjb,label="PSJB")
plt.plot(n_array,rr,label="RR")
plt.plot(n_array,pbs,label="PBS")
plt.title("Average waiting time of 5 scheduling algorithms")
plt.xlabel("Number of processes")
plt.ylabel("Average waiting time")
plt.legend(loc='best')

plt.show()

