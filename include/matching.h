#ifndef MATCHING_H
#define MATCHING_H

#include "graph.h"
#include "utility.h"


void greedyMatching(NODE_T ,WeightEdgeList &, WeightList &, NODE_T [], WeightEdgeList &, SUM_T &, NODE_T &,int=1);

void greedyMatching(NODE_T ,WeightEdgeList &, NODE_T [], WeightEdgeList &, SUM_T &, NODE_T &,int = 1);

void greedyMatching(LightGraph &, NODE_T [], WeightEdgeList &, SUM_T &, NODE_T &,int = 1);
#endif
