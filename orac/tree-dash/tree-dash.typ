#let definition(body)=[*Definition.* #body]

#align(center + horizon, [
  #text(size: 3em)[= #smallcaps[Tree Dash]]
  Notes on various observations required in order to solve _Tree Dash_.
])

#outline()
#pagebreak()

= Notation

#let minanc=$mono("min anc")$
#let maxanc=$mono("max anc")$
#let mindesc=$mono("min desc")$
#let maxdesc=$mono("max desc")$
#let up=$mono("up")$
#let anc=$op("Anc")$
#definition[
  We define the minimum and maximum ancestors to be 
  $minanc(u)$ and $maxanc(u)$ respectively.

  Similarly we define the minimum and maximum descendants to be $mindesc(u)$ and $maxdesc(u)$.
  
  We also define the dependencies of a node $u$ to be the set of all nodes such that $u$ is reachable from that node. In that vein, the dependency sum is the sum of weights of all dependencies of a node (including itself).
]

We call the tree from the input data to be the *initial tree*, the graph created from the various operations to be the *initial graph* and the eventual condensation graph to be the *SCC graph*.


== Lemma 1
*Claim.* You can reduce the two ancestor edges into a single _up edge_.

*Proof.* For any node $u$, consider the two orderings of the min and max ancestor edge destinations. 

One of the following is true:
Either  $minanc u in anc(maxanc u)$ or $maxanc u in anc(minanc u)$. In English, one node must be above the other. 

If so, that means you can reach the higher node from the lower node. 

Since the lower node can reach anything the higher node can, there is no reason to keep both edges. 

We will henceforth refer the this compressed edge as the _up edge_ and denote it $up u$.

== Lemma 2
After running SCC, let's call any SCC that only has one node a *singleton* and any SCC with more than one node *real*.

#definition[
  For a given real SCC $S$, we define the _top_ of $S$ to be the node in $S$ whose depth is the lowest. We denote this $mono("top") S$.
]

*Claim.* There are no edges from real SCC's to singletons.

*Proof.* Proof by contradiction.

Let the real SCC be $S$ and the singleton be $u$. Say there was an edge from $S -> u$. 
If $u$ was below $S$, clearly $S$ is an ancestor of $u$. However, since $S$ is a real SCC, there must also be an up-edge into the top of $S$. Therefore $S$ must be a new minimum or maximum along $u$'s ancestor path. Therefore, $u$ must also be connected to $S$. However, we defined $u$ to be a singleton. Hence, contradiction.

A similar argument can be used to disprove the case where $u$ is above $S$.

== Lemma 3
With the same logic as _Lemma 2_, it can be shown that all real SCC's cannot have a downwards edge.

== Lemma 4
*Claim.* The real SCC's in the SCC graph can be reduced to form a tree while keeping connectivity.

*Proof.* Take an SCC $S$. It cannot have an edge to anything below it because of _Lemma 3_. However, you can repeatedly take up-edges until it hits the root. 

Let another real SCC $T$ be reachable from $S$. By properties of the initial tree, anything $T$ can reach can also be reached from $S$. Therefore, you only need the deepest real SCC reachable from $S$, since this preserves connectivity. Since every node is connected and there is one up-edge per real SCC (except for the root), these connections in the SCC graph can be reduced to a tree while keeping connectivity. 

Since the SCC graph forms a tree, we will call it the SCC tree. The path sum of a SCC $S$ is the sum of all weights of all SCC's on the path from $S$ to the root SCC.

== Lemma 5

We define the singleton-graph to be the subset of the SCC graph with only singleton nodes.

*Claim.* The order of dependency in the singleton-graph is the same as the depth order in the initial tree.

*Proof.* Trivial. Consider a singleton $u$. It has an up-edge and down-edge(s). If the down-edge led to above $u$, it ceases to be a down-edge. 

If somehow there was a case where $u stretch(arrow)^"up-edge" v stretch(arrow)^"down-edge" w$, breaking the depth order, $w$ must also have an edge back to $v$, and similarly for $u$. This creates a real SCC, contradiction.

== Lemma 6

Define the _up-component_ of a singleton $u$ to be the real SCC that is eventually reachable by repeatedly taking up-edges from $u$.

*Claim.* If a singleton $u$ has an up-component $S$, all of $u$'s descendants must also have up-component $S$.

*Proof.* Let $u$ be a singleton and $v$ be one of $u$'s children. Since $u$ has an up-edge, $v$ must either have the same up-edge, or point to $u$. Thus, they must reach the same up-component. Claim for all descendents can be proven by induction.

== Lemma 7

*Claim.* Let $u$ be a singleton. The set $X$ of its dependencies must satisfy $X subset.eq anc u$. 

*Proof.* Trivial. If a dependency $v$ was not in $anc u$, there could not have been an edge from $v$ to $u$.

== Lemma 8

You can prevent double-counting of ancestors in the singleton-graph by compressing down-edges.

Consider the case $a -> b -> u$, $a -> u$. Here, naively computing the the dependency sum would double-count $a$. However, we can observe that we can remove the edge $a -> u$, as it is already handled by $a -> b -> u$.

Whenever a node $u$ has two down-edges, call them $a$ and $b$. If $a in anc b$ there must be an edge from $u -> a$ and $u -> b$, therefore we can remove $u -> b$ and keep $u -> a -> b$. 

This transformation turns the singleton-graph into this weird hybrid directed tree thingy. This in turn also makes calculating the dependency sum for singleton nodes trivial.

== Lemma 9

*Claim.* If a singleton $u$ has a down-edge that leads to a real SCC, that real SCC must have the same up-component as $u$.

*Proof.* Let the destination of the down-edges be $A$. $A$ must not connect to $u$ by _Lemma 2_. However, that means that $A$ and $u$ must share an up-edge, so they must all have the same up-component.

#let weight=math.op("weight")
= Solution
- Compress up-edges and down-edges
- Run SCC
  - Compute SCC tree by sorting by $mono("top") S$
- Compute path sums for all SCC's in SCC tree.
- Go by reverse postorder through all singleton nodes:
  - Let $mono("wr")[u]$ denote the sum of weights of the real SCC's that are reachable from $u$.  Let $ weight u = cases(mono("wr")[u] &"if" u "is a singleton", "path sum of" u &"if" u "is a real SCC") $
    - Let $"base" = "path sum of" u$
    - If $u$ has no children, $mono("wr")[u] = "base"$
    - If $u$ has one child $a$, $mono("wr")[u] = weight a$
    - If $u$ has two children $a$ and $b$, $mono("wr")[u] = weight a + weight b - "base"$.
      - Why? If you have one child, you do not want to add $"base"$ since you would double count it.
      - If you have two children, you double-count $"base"$ once, so you need to subtract it to compensate. This reasoning follows for real SCC's by _Lemma 9_. If you had two real SCC's $A$ and $B$ from the two down edges, they must both overlap $"base"$ since they share the up-edge. Therefore you _still_ have to subtract it. Similar reasoning applys for one real SCC from down-edges.
  - Let $mono("ws")[u]$ denote the sum of weights of singletons that are reachable from $u$. This is trivially obtainable as a "tree" dp.
The answer is:
$
"ans" &= sum_("singleton" u) W_u dot (mono("ws")[u] + mono("wr")[u] - W_u) \
      &+ sum_("real SCC" S) ("path sum of" dot sum_(u in S) W_u) - sum_(u in S) W_u^2
$

All of this can be implemented in $O(N)$.
