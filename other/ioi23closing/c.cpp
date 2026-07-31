// Decompose into path a <-> b and subtree of a and subtree of b
// Loop over all cases of connection between a <-> b
// If a path and b path disjoint, precompute most score with <= K budget
// 
// to find cases of connection between a <-> b:
// find the crossing point on prefix sum of a and prefix sum of b
// optimal connection that doesn't reach crossing point can be gotten with dijkstra up to crossing
// else start with crossing point and then dijkstra on modification price after.
//
// precompute most score <= K with: disjoint, b -> st(A), a -> st(B)
