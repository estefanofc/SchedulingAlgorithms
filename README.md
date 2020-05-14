# Scheduling Algorithms
Completing this project will require writing the following C files:

schedule_fcfs.c
schedule_sjf.c
schedule_rr.c
schedule_priority.c
schedule_priority_rr.c

The supporting files invoke the appropriate scheduling algorithm. 

For example, to build the FCFS scheduler, enter

make fcfs

which builds the fcfs executable file.
This project involves implementing several different process scheduling algorithms. The scheduler will be assigned a predefined set of tasks and will schedule the tasks based on the selected scheduling algorithm.  Each task is assigned a priority and CPU burst. The following scheduling algorithms will be implemented:

First-come, first-served (FCFS), which schedules tasks in the order in which they request the CPU.
Shortest-job-first (SJF), which schedules tasks in order of the length of the tasks' next CPU burst.
Priority scheduling, which schedules tasks based on priority.
Round-robin (RR) scheduling, where each task is run for a time quantum (or for the remainder of its CPU burst).
Priority with round-robin, which schedules tasks in order of priority and uses round-robin scheduling for tasks with equal priority.
Priorities range from 1 to 10, where a higher numeric value indicates a higher relative priority.  For round-robin scheduling, the length of a time quantum is 10 milliseconds.

I. Implementation
The implementation of this project should be completed in  C.  Program files supporting C are provided in the source code download for the text. (See http://www.os-book.com (Links to an external site.)) These supporting files read in the schedule of tasks, insert the tasks into a list, and invoke the scheduler. You can find the source code on GitHub at https://github.com/greggagne/osc10e/tree/master/ch5/project/posix   (Links to an external site.)as well.

The schedule of tasks has the form [task name] [priority] [CPU burst], with the following example format:

T1, 4, 20
T2, 2, 25
T3, 3, 25
T4, 3, 15
T5, 10, 10
Thus, task T1 has priority 4 and a CPU burst of 20 milliseconds, and so forth.  It is assumed that all tasks arrive at the same time, so your scheduler algorithms do not have to support higher-priority processes preempting processes with lower priorities. In addition, tasks do not have to be placed into a queue or list in any particular order.

There are a few different strategies for organizing the list of tasks, as first presented in Section 5.1.2 (Links to an external site.).  One approach is to place all tasks in a single unordered list, where the strategy for task selection depends on the scheduling algorithm.  For example, SJF scheduling would search the list to find the task with the shortest next CPU burst.  Alternatively, a list could be ordered according to scheduling criteria (that is, by priority).  One other strategy involves having a separate queue for each unique priority, as shown in Figure 5.7 (Links to an external site.).  

figure-5-7.png

These approaches are briefly discussed in Section 5.3.6 (Links to an external site.).  It is also worth highlighting that we are using the terms list and queue somewhat interchangeably.  However, a queue has very specific FIFO functionality, whereas a list does not have such strict insertion and deletion requirements. You are likely to find the functionality of a general list to be more suitable when completing this project.

II. C Implementation Details
The file driver.c reads in the schedule of tasks, inserts each task into a linked list, and invokes the process scheduler by calling the schedule() function.  The schedule() function executes each task according to the specified scheduling algorithm.  Tasks selected for execution on the CPU are determined by the pickNextTask() function and are executed by invoking the run() function defined in the CPU.c file.  A Makefile is used to determine the specific scheduling algorithm that will be invoked by driver.  For example, to build the FCFS scheduler, we would enter

make fcfs
and would execute the scheduler (using the schedule of tasks schedule.txt) as follows:

./fcfs schedule.txt
Refer to the README file in the source code download for further details.  Before proceeding, be sure to familiarize yourself with the source code provided as well as the Makefile.

Expected Output
./fcfs schedule.txt

For FCFS, you can simply choose first Task in the wait. Assuming schedule.txt as below:

T1, 4, 20
T2, 3, 25
T3, 3, 25
T4, 5, 15
T5, 5, 20
T6, 1, 10
T7, 3, 30
T8, 10, 25
The output will be

Running task = [T1] [4] [20] for 20 units.
        Time is now: 20
Running task = [T2] [3] [25] for 25 units.
        Time is now: 45
Running task = [T3] [3] [25] for 25 units.
        Time is now: 70
Running task = [T4] [5] [15] for 15 units.
        Time is now: 85
Running task = [T5] [5] [20] for 20 units.
        Time is now: 105
Running task = [T6] [1] [10] for 10 units.
        Time is now: 115
Running task = [T7] [3] [30] for 30 units.
        Time is now: 145
Running task = [T8] [10] [25] for 25 units.
        Time is now: 170
FCFS does not care about priorities AND all tasks arrive at the same time, so there are 8! possible combinations.
