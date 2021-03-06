
<h1>Innovative Process Scheduling Algorithm</h1>
<br>
This project deals with the simulation of CPU scheduling algorithms with C. The following 
algorithms are simulated:<br>
1.First Come First Serve (FCFS)<br>
2.Shortest Job First<br>
3.SRTF Algorithm <br>
4.Round Robin <br>
<h2>Our innovative algorithm</h2> <br>
The metrics such as finishing time, waiting time, total time taken for the processes to 
complete, number of rounds, etc are calculated.<br>
<h3>Need for a new algorithm</h3><br>
➢ Round Robin, considered as the most widely adopted CPU scheduling <br>
algorithm but it undergoes severe problems which are directly related to 
quantum size.<br>
➢ If time quantum chosen is too large, the response time of the processes is 
considered too high.<br>
➢ On the other hand, if this quantum is too small, it increases the overhead of 
the CPU.<br>
➢ In this paper, after referring to a number of papers on this topic we have 
proposed a new algorithm , based on a new approach called dynamic-time quantum.<br>
➢ The idea of this approach is to make the operating systems adjusts the time 
quantum according to the burst time of the set of waiting processes in the 
ready queue. <br>
➢ Based on the simulations and experiments, we show that the new proposed 
algorithm solves the fixed time quantum problem and increases the 
performance of Round Robin<br>
<h3>Our innovative algorithm(OIA)</h3>
➢ The proposed algorithm focuses on the improvement on CPU scheduling 
algorithm. The algorithm reduces the waiting time and turnaround time 
drastically compared to the other Scheduling algorithm and simple Round 
Robin scheduling algorithm.<br>
➢ This proposed algorithm works in a similar way as but with some 
modification. It executes the shortest job having minimum burst time first 
instead of FCFS simple Round robin algorithm and it also uses Smart time 
quantum instead of static time quantum. Instead of giving static time 
quantum in the CPU scheduling algorithms, our algorithm calculates the 
Smart time quantum itself according to the burst time of all processes.<br>
➢ The proposed algorithm eliminates the discrepancies of implementing simple 
round robin architecture.<br>
➢ In the first stage of the innovative algorithm CPU scheduling algorithms all 
the processes are arranged in the increasing order of CPU burst time. It 
means it automatically assign the priority to the processes. <br>
➢ Process having low burst time has high priority to the process have high burst 
time. <br>
➢ Then in the second stage the algorithm calculates the mean of the CPU burst 
time of all the processes. After calculating the mean, it will set the time 
quantum dynamically i.e. (average of mean and highest burst time)/2. <br>
➢ Then in the last stage algorithm pick the first process from the ready queue 
and allocate the CPU to the process for a time interval of up to 1 Smart time 
quantum. If the remaining burst time of the current running process is less 
than 1 Smart time quantum then algorithm again allocate the CPU to the 
Current process till it execution. <br>
➢ After execution it will remove the terminated process from the ready queue 
and again go to the stage 3<br>
