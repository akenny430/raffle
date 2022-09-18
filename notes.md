some ideas about design of this 
we need to do two things: 
1. compute expected value 
2. simulate series of samples to confirm ev 

EXPECTED VALUE 
we have idea of formula 
basically, all randomness is generated from the simulated N 
so expected value is just looping over n 
also looping over k, 
but the probability of getting that k depends on n 
just have to implement the formulas 

so i am not sure how we should do this 
right now have a Multinomial object 
that just initializes the total size and four ns 
i think when we run simulation we should input all of 
the ns into this object 
given this Multinomial we should also be able to 
compute E(N) and V(N) 
so the constructor will take in an array (or something) 
of c's and v's to compute that 
and then that will be easy for the computations 
so i wonder if the constants we made 
should be passed in as arguments 
if we want to generalize then yeah it should 
should also have method to get density function 
maybe template functions, 
if we want to generalize we should be allowed to 
input any size array 


SIMULATION 
for any given simulation, 
we have to specity n 
and then choose the number of samples to generate 
say we want to generate M samples 
the entire generation is as follows: 
1. generate M multinomial rv's N 
2. for a given N, define the parameters for K, 
   the probability of choosing a specific cohort 
3. for each M, you now have n and k, 
   will always have loss plus probability of winning 
   as ck / En, as a potential added bonus 

when generating the M multinomial Ns, i think 
it is better to generate the N random variables for a given 
probability 
so that is, we generate M n1, then M n2, so on 
that way we dont have to waste time creating a new object 
every time we want to simulate a single one 

however, for each observation, 
we would have to initialize a new object 
every time, 
since for a given M the probabilities depend on 
the generated N. i wonder if there is a faster way 

same with computing the chances of winning 

note that once we have N, 
we can also compute E and V for all of the samples 

so there is some way we have to "reshape" the Ns 
after generating them 
since we will have 4 M-vectors 
and we want M 4-vectors 
so from that would have to reshape them all 

then once that is set up 
(i.e. have M 4-vectors), 
we then run through each M 

so to summarize, 
the only part that seems to have been "sped up" 
is the generation of M's 
the rest have to loop through all M 
generating new rvs 
but that isnt a huge problem bc we only have to create 
a single object for K and single for W 
whereas if we did it for N, 
we would have to create 4 binomial objects for each M 

whats faster? making 4 binomial per (total of 4M) 
or only making 4 and then reshaping 
my thinking is ladder will be faster, but harder to implement? 

once this is done, we are set 

HOW TO GENERATE 
we will use <random> header 
just have to make generator, and then plug in 
to your initialized distribution 

// making device 
std::random_device dev; 
std::mt19937 mt_generator(dev()); mt generator 

std::binomial_distribution<int> bdis(n, p); 
// then update n and p as needed 

std::discrete_distribution<int> disc(p1, p2, p3, p4); 
// pk = nk / n 
// will this return 0, 1, 2, 3 or 1, 2, 3, 4? should check 
// yeah its 0, 1, 2, 3
// this is so cool, they dont even have to be probabilities 
// just weights in general 

std::bernoulli_distribution bern(p); 
// p = ck / En 
