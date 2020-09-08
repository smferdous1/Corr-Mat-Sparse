#ifndef EDGECOVER_H13423
#define EDGECOVER_H13423
#include "graph.h"
#include "input.h"
#include "utility.h"
#include <stddef.h>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
struct AdjEff
{
  NODE_T adjV;
  VAL_T adjW;
  VAL_T adjWEff;
};
struct VtxInd
{
  NODE_T u;
  EDGE_T ind;
};

//hold the index and the effective weight of the edge
struct EffWtInd
{
  EDGE_T ind;
  VAL_T WtEff;
};


typedef std::vector<EffWtInd> AdjacentListEffInd;
typedef std::vector<AdjacentListEffInd> AdjacencyListEffInd;
typedef std::unordered_set<EDGE_T > AdmissIndSet;
typedef std::vector<AdmissIndSet> AdmissIndSetList;

typedef struct AdjEff AdjacentEff;
typedef std::vector<AdjacentEff> AdjacentListEff;
typedef std::vector<AdjacentListEff> AdjacencyListEff;


struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const std::pair<T1, T2>& p) const
    { 
        auto hash1 = std::hash<T1>{}(p.first); 
        auto hash2 = std::hash<T2>{}(p.second); 
        //return hash1 ^ hash2;
        //cantor pairing function 
        return (hash1+hash2)*(hash1+hash2+1)/2+hash2;
        //return hash1*31+hash2;
    } 
};

typedef std::vector<VAL_T>  AdjacentWeight;
typedef std::unordered_map<std::pair<NODE_T,NODE_T>, EDGE_T, hash_pair> EdgeHash;
 
void constructPrimalDual(LightGraph &, int , LightGraph &);
void constructPrimalDualShm(LightGraph &, int , LightGraph &, double *,int);
void constructPrimalDualShmCorr(LightGraph &, int , LightGraph &, double *,int);
void constructNearestNeighbor(LightGraph &, int , LightGraph &, double *,int);
#endif
