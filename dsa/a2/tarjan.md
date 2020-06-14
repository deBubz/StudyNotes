# Tarjan notes

used to find strongly connected component

## Low link

The low-link value of a node is the smallest node id reachable
from that node when doing a dfs ( including itself )

Low link values are dependent on the travel path of the dfs

hence the low-link value used to identify scc could be wrong

hence the need of Tarjan

## Stack invariant

to handle the visiting order of dfs, Tarjan uses a stack of calid nodes from which to update low-link values from

Nodes are added to the stack of valid nodes as they're explored for the first time

Nodes are removed from the stack each time a complete SCC is found.

## New low-link update condition

if `u` and `v` are nodes in a graph and currently exploring `u`, new low-link condition:

> to update `u` ll value to `v` ll value, there has to be a path of edges from `u` -> `v`
> and `v` must be on the stack

## Tarjan overview

-