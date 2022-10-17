# Problem statement 

The Yankees are holding a 50/50 raffle that works as follows: 
- The patrons will buy entries for a certain amount of money. All of the money is collected together. 
- A single ticket is chosen at random from the submitted entries of all the patrons. 
- The selected winner gets 50% of the prize money, and the other 50% is donated to charity. 
Let $n$ be the total number of patrons that partake in the raffle. 

Patrons can buy entries using one of the four configurations: 
1. 5 entries for 10 USD ($\mathcal{C}_1$). 
2. 20 entries for 20 USD ($\mathcal{C}_2$). 
3. 100 entries for 40 USD ($\mathcal{C}_3$). 
4. 300 entries for 100 USD ($\mathcal{C}_4$). 

We will call each of these four groups a *cohort*. 

Suppose also that patrons have the following probabilities of belonging to a given cohort: 
1. 15% are in $\mathcal{C}_1$. 
1. 10% are in $\mathcal{C}_2$. 
1. 30% are in $\mathcal{C}_3$. 
1. 45% are in $\mathcal{C}_4$. 

Given these probabilities, we have the two following questions:  
1. **what is the expected value of the prize money?**
2. **what is the expected value of a patron's earnings for the raffle?** 

## Assumptions 

Even though it is not stated, we make the following assumptions about the raffle: 
- A patron can only belong to a single cohort. 
- A patron can only buy a single set of entries. 
i.e. if they are in $\mathcal{C}_2$, they will only contribute 20 entries and 20 USD total. 

# Definitions and notation 

Let $n$ be the number of patrons that participate in the raffle. 

For a given cohort $\mathcal{C}_k$, let: 
- $e_k$ be the number of entries submitted by a patron in that cohort ($e_1 = 5$, $e_2 = 20$, $e_3 = 100$, $e_4 = 300$). 
- $v_k$ be the value *per entry*, which is just the total value divided by the number of entries 
(e.g. $v_1 = 10 / 5 = 2$). 
So $v_1 = 2$, $v_2 = 1$, $v_3 = 2 / 5$, and $v_4 = 1 / 3$. 

We define the following: 
- $\mathbf{p} = [0.15, 0.10, 0.30, 0.45]^\top$ is the vector of *probabilities* of belonging to a given cohort. 

- $\mathbf{N} = [N_1, N_2, N_3, N_4]^\top$ is the number of patrons that belong to each cohort. 
Given $n$ and $\mathbf{p}$, we can see $\mathbf{N}$ is a multinomial random variable, 
i.e. 
$$
\mathbf{N} \sim \mathrm{MN}(n, \mathbf{p}) 
\text{, with density }
f_{\mathbf{N}}(\mathbf{n}) = \frac{n!}{n_1 ! \cdot n_2 ! \cdot n_3 ! \cdot n_4 !} \, p_1^{n_1} p_2^{n_2} p_3^{n_3} p_4^{n_4}. 
$$

- It's worth noting that for each cohort, we have 
$\mathbb{E}[N_k] = n p_k$ and $\mathbb{V}\mathrm{ar}[N_k] = n p_k (1 - p_k)$. 

- $\mathcal{P}_n$ be the set of all $\mathbf{n}$ such that $\mathbf{1}^\top\mathbf{n} = n$, i.e. the domain of $\mathbf{N}$. 

- $\mathbf{E} = [E_1, E_2, E_3, E_4]^\top$ is the number of entries submitted by each cohort. 
For each cohort we have 
$$
E_k = e_k \cdot N_k. 
$$ 

- $E$ is the *total number of entries*. This is just 
$$
E 
= \mathbf{1}^\top\mathbf{E} 
= \sum_{k = 1}^4 e_k N_k. 
$$

- $\mathbf{V} = [V_1, V_2, V_3, V_4]^\top$ is the total value from each cohort. 
For each cohort we have 
$$
V_k = v_k \cdot E_k = v_k \cdot e_k \cdot N_k. 
$$

- $V$ is the *total value*, just 
$$
V = \mathbf{1}^\top\mathbf{V} 
= \sum_{k = 1}^4 v_k E_k  
= \sum_{k = 1}^4 v_k e_k N_k. 
$$

- $T$ is the *patron value*, just $V / 2$. 

From these definitions, we see that both the entry random variables ($\mathbf{E}$ and $E$) 
and the value random variables ($\mathbf{N}$ and $V$) 
depend on $\mathbf{N}$. 
Thus these are really just functions of the random variable $\mathbf{N}$, 
which is how we will go about solving the problem. 

# Revisiting first problem 

The first problem now amounts to determining $\mathbb{E} \left[ T \right]$. 
Expanding out $T$ gives us 
$$
T(\mathbf{N})
= \frac{1}{2} V(\mathbf{N})
= \frac{1}{2} \sum_{k = 1}^4 v_k e_k N_k. 
$$
The naive approach would be to compute 
$$
\mathbb{E}[T] 
= \mathbb{E} \left[ \frac{1}{2} \sum_{k = 1}^4 v_k e_k N_k \right]
= \frac{1}{2} \sum_{k = 1}^4 v_k e_k \mathbb{E}[N_k] 
= \frac{n}{2} \sum_{k = 1}^4 v_k e_k p_k, 
$$
but the random variables $\mathbf{N}$ are not independent. 

Instead, we should compute 
$$
\mathbb{E}[T] 
= \sum_{\mathbf{n} \in \mathcal{P}_n} T(\mathbf{n}) \cdot f(\mathbf{n}), 
= \frac{1}{2} \sum_{\mathbf{n} \in \mathcal{P}_n} f(\mathbf{n}) \sum_{k = 1}^4 v_k e_k n_k, 
$$
i.e. we would have to sum over all plausible combinations of cohort. 

## Revisiting second problem 

