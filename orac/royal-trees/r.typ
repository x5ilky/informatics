#let dist=math.op("dist")
= Royal Trees
Given $N$, $A$, $B$ and $D$, find number of trees of size $N$ in which $dist(A,B)=D$.
== Subtask 2
$D = 1$.
$
"#trees" = (N-1)! \
$
Since $B$ only has one choice
$
"#trees" = (N-1)! / (B-1) \
$
== Subtask 3
$A = 1, D = 2$.

Let $Q$ denote the node between $A$ and $B$.
$
"#trees" &= sum_(Q=2)^(B-1) (N-1)!/((Q-1)(B-1)) \
         &= (N-1)!/(B-1) sum_(Q=2)^(B-1) 1/(Q-1)
$
== Subtask 4
$D = 2$. In all subtasks, $dist(A,r) + dist(B,r) = D$ for a given node $r$.
Cases:

- $dist(A,r) = dist(B,r) = 1$:
$ 
"#trees"_1 &= sum_(r=1)^(A-1) frac((N-1)!,(A-1)(B-1)) \
         &= (N-1)!/((A-1)(B-1)) (A-1)  \
         &= (N-1)!/(B-1) "unless" A = 1 \
$
- $r = A$:

Let $Q$ denote the node between $A$ and $B$.
$
"#trees"_2 &= sum_(Q=A+1)^(B-1) (N-1)!/((Q-1)(B-1)) \
           &= (N-1)!/(B-1) sum_(Q=A+1)^(B-1) 1/(Q-1)
$

So,
$
"#trees" &= (N-1)!/(B-1)
  + ((N-1)!/(B-1) sum_(Q=A-1)^(B-1) 1/(Q-1)) \
    &= (N-1)!/(B-1) [{1 "if" A != 1} + sum_(Q=A+1)^(B-1) 1/(Q-1) ]
$

== Subtask 5
$A = 1$.

Let the nodes $Q_1, Q_2, ..., Q_(k-1), Q_k$ denote the $k = D - 1$ nodes between $A$ and $B$.

$
"#trees" = (N-1)!/(B-1) sum_(Q_1=2)^(B-k) (1/(Q_1-1) sum_(Q_2=Q_1+1)^(B-k+1)(1/(Q_2-1) sum_(Q_3=Q_2+1)^(B-k+2) (1/(Q_3-1) space.en dots.c)))
$

Let $
f(i,j) &= sum_(Q=j+1)^(B-k+i) 1/(Q-1) f(i+1,Q) \
f(k-1,j) &= sum_(Q=j+1)^(B-1) 1/(Q-1) \
f(i,j) &= f(i,j+1) + 1/j f(i+1,j+1) \
f(i,j) &= 0 "if" j > B-D+i 
$

Therefore $"#trees" = (N-1)!/(B-1)f(0,1)$.

== Full
Let $r$ be a node such that $A, B in op("Desc")(r)$ and $dist(A,r) + dist(B,r) = D$.

Define $c(i)$ as:
$
c(i) = cases(
  2 "if" i < A,
  1 "if" A < i < B,
  0 "if" i = A "or" i >= B
)
$
Define $g(i,j)$ as where $k = D-2$:
$
g(i,j) &= sum_(Q=j+1)^(B-k+i) c(Q)/(Q-1) g(i+1,Q) \
g(k,j) &= 1 \
g(i,B-1) &= 0 "if" i < k \
g(i,j) &= g(i,j+1) + c(j+1)/j g(i+1,j+1)
$

$
"#trees" &= (N-1)!/(B-1) f(0,1) &&quad [A = 1] \

"#trees" &= (N-1)!/((A-1)(B-1))sum_(r=1)^(A-1) g (0,r) + (N-1)!/(B-1) f_(D-1)(0,A) &&quad [A > 1] \ 
$
