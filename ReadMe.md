# Process Scheduling Algorithms
### This program is on performance evaluation for various CPU scheduling algorithms. Arrival times and CPU bursts for a set of processes are generated randomly following some probability distribution. A scheduler is implemented to evaluate the performance metrics for the chosen scheduling algorithms through simulation.<br></br>


To run script file:
#### Command 
```./script.sh```

To run only driver file:
#### Command 
1) ```g++ driver.cpp```
2) ```./a.out n``` (n is the number of processes passed as command line argument)

#### Shortforms of scheduling algorithms are used as:
FCFS: First come first serve<br>
NSJB: Non preemptive shortest job first<br>
PSJB: Preemptive shortest job first<br>
RR: Round Robin (Time quantum=2)<br>
PBS: Priority based scheduling<br>

The table simulated is for n=50

### Role of different files:<br>
1) driver.cpp: Main scheduling algorithm's code is written in this file in different functions.<br>
2) output.txt: This txt file is made by the driver code on its execution displaying the processes arrival table.<br>
3) plot.py: After execution of the driver code by script command this program shows performance plots of all algorithms by taking data from the csv files made.<br>
4) script.sh: Only this file has to be run in the terminal for execution of all other files in correct order.<br>

Note: After every run of the script we need to delete the csv files that are made for a new execution of the program. Close every image to see the next one while python script is running.
