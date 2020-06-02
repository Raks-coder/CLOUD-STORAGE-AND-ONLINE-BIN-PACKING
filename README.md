# CLOUD-STORAGE-AND-ONLINE-BIN-PACKING

[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c-plus-plus.svg)](https://forthebadge.com)

> This project talks about cloud storage and how bin packing can be used in order to efficiently store data in servers. Each server which will be made has a cost to it, and using the least amount of bins will in a way reduce the costs for both the user and the company. Also Bin packing will provide an efficient way to access this data. Cloud computing is one such example of this, with the rapid rise of cloud computing in gaming, banking, networks, it has become imperative to find a way to store this data, and since the size of server is limited, we have to employ algorithms to store data. This paper will use three specific algorithms Harmonic Bin Packing, Variable Harmonic Bin Packing and K Binary Bin Packing to achieve this. All of these three algorithms, rely on making partitions of certain intervals and bins are then allocated to these partitions. We will compare the performance of each algorithm and plot the number of inputs with the number of bins.


## Algorithms
We will use bin packing algorithms. Offline bin packing deals with pre-known data, and then using algorithms to put it in bins. But in this case offline bin packing is not at all possible, because we will not now what will come after. The data has to be put in the bins at that very instant without having prior knowledge about the data ahead of it. The online bin packing method is a variation of the classical bin packing problem.
Online bin packing has the same constraints as classical bin packing with the minor difference being the way the elements are given.
For solving this problem, we use three main algorithms – 1)Harmonic Algorithm
2)Variable Harmonic Algorithm (Epstein Algorithm) 3)K-Binary Algorithm.
In the bin packing problem, objects of different volumes must be packed into a finite number of bins or containers each of volume V in a way that minimizes the number of bins used. In computational complexity theory, it is
a combinatorial NP-hard problem. The decision problem (deciding if objects will fit into a specified number of bins) is NP-complete.
1)Harmonic Algorithm (Lee and Lee)
For a given value of N, M, and the set of items L= {a1, a2, .... an}
Ø Partition the interval (0, 1] for the given M into subintervals as given below:
(0,1/M], (1/M,1/(M-1)], (1/(M-1),1/(M-2)] ......... (1/2,1]
Ø Assign each item ai to the open bin of that type (the size of ai fits into the corresponding subinterval).
Ø If an item does not fit into the corresponding bin, then close it and open a new one.
Ø Calculate the total number of bins used of each type. 2)Variable Harmonic Algorithm(Epstein)
ØFor a given value of N, M, and the set of items L= {a1, a2, .... an}
Ø Step 1: Partition the interval (0, 1] for the given M into subintervals:
Ø Step 2: Assign each item ai to the open bin of that type (the size of ai fits
into the corresponding subinterval). 
Ø Step 3: If there are M items of type M into the small bin, then close it and
open a new one.
Ø Step 4: If an item does not fit into the corresponding bin, then close it and
open a new one. 
Ø Step 5: Calculate the total number of bins used of each type.
3)K-Binary Algorithm
ØFor a given value of N, M, and the set of items L= {a1, a2, .... an}
Ø Step 1: Partition the intervals for the given M value such that they are
partitioned into given intervals as given below.
(0,1/2(M-1)], (1/2(M-1),1/2(M-2)], (1/2(M-3),1/2(M-4)] ....... (1/2,1]
Ø Step 2: Assign the items to bins according to each interval.
Ø Step 3: Pack the items into each bin, if the next small element does not fit
into the opened bin, then we close this bin and open a new one.
Ø Step 4: Calculate the total number of bins formed for each interval.
Example –
For 10 random values between (0,1) – 0.63,0.03,0.11,0.11,0.55,0.17,0.95,0.93,0.74,0.23
Harmonic Packing -
Partition-1 - Bin1 - 0.03 0.11 0.11 0.17

Partition-2 - Bin1 - 0.23
Partition-3 – No Bins
Partition-4 – No Bins
Partition-5 Bin1- 0.63, Bin2-0.55, Bin3-0.95, Bin4 -0.93, Bin5-0.74 Total Bins – 7
Variable Harmonic Packing –
Partition-1 - Bin1 - 0.03 0.11 0.11 0.17 Partition-2 - Bin1 - 0.23
Partition-3 – No Bins
Partition-4 – No Bins
Partition-5 Bin1- 0.63, Bin2-0.55, Bin3-0.95, Bin4 -0.93, Bin5-0.74 Total Bins - 7
K Binary Packing-
Partition-1 Bin1 0.03
Partition-2 Bin1 0.11 0.11
Partition-3 Bin1 0.17 0.23
Partition-4 No Bins.
Partition-5 Bin1- 0.63, Bin2-0.55, Bin3-0.95 Bin4-0.93 Bin5-0.74 Total Bins - 8
## Analysis-

Table- No of bins with items for different algorithms

Items	Harmonic   |    Variable	K-Binary
			
20	12			14	15
			
40	27			28	28
			
80	41			41	40
			
100	53			55	53
			
150	66			68	67
			
200	99			100	98
			
Now using these values, a table with average values is made-:
			
N(Bins)	Harmonic   |	Variable	K-Binary
			
20	5.017		4.0902	      4.5151
			
40	9.5304		8.522	      8.8152
			
80	20.756		19.027	      20.02
			
 
100	26.381		23.951	     25.4988
			
150	40.028		36.9672	     38.9824
			
200	52.8476		49.39	     51.8582
			

Partition-3 – No Bins

