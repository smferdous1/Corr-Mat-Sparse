#ifndef EDGECOVER_H
#define EDGECOVER_H
#include "graph.h"
#include <unordered_set>

struct AdjEff
{
  NODE_T adjV;
  EDGE_T ind;
  VAL_T adjW;
  VAL_T adjWEff;
};
//hold the index and the effective weight of the edge
struct EffWtInd
{
  NODE_T u; 
  EDGE_T ind;
  VAL_T WtEff;
};
struct VtxInd
{
  NODE_T u;
  EDGE_T ind;
};

// class for hash function 
 class VtxIndHashFunction {
 public: 
     // adjV is returned as hash function 
     size_t operator()(const VtxInd& vtx) const
     {
         return vtx.ind;
     }
 };  

class VtxIndCompFunction {
 public: 
     // adjV is returned as hash function 
     size_t operator()(const VtxInd& vtx, const VtxInd& vtx1) const
     {
         return (vtx.ind == vtx1.ind);
     }
 };

typedef std::vector<EffWtInd> AdjacentListEffInd;
typedef std::vector<AdjacentListEffInd> AdjacencyListEffInd;
typedef std::unordered_set<VtxInd,VtxIndHashFunction, VtxIndCompFunction> AdmissIndSet;
typedef std::vector<AdmissIndSet> AdmissIndSetList;



typedef struct AdjEff AdjacentEff;
typedef std::vector<AdjacentEff> AdjacentListEff;
typedef std::vector<AdjacentListEff> AdjacencyListEff;


//typedef std::vector<AdjcanetListEffInd> AdjacencyListEffInd;

class EdgeCover
{
  public:
    EdgeCover()
    {
    
    }
    void nearestNeighbor(LightGraph &, WeightEdgeList& , NODE_T [],SUM_T &);
    void nearestNeighborb(LightGraph &, WeightEdgeList& , NODE_T [], NODE_T [], SUM_T &);

    void removeMaximalRedundantEdges(WeightEdgeList& ,NODE_T [],SUM_T&, EDGE_T[]);
    void removeMaximalRedundantbEdges(WeightEdgeList& ,NODE_T [],SUM_T&, EDGE_T[]);
    void removeGreedyRedundantbEdges(WeightEdgeList& ,NODE_T [],SUM_T&, EDGE_T[]);
    void removeMaximalRedundantEdges(WeightEdgeList& ,NODE_T [],NODE_T [],SUM_T&, EDGE_T[]);
    void lazyGreedyEdgeCover(LightGraph &, WeightEdgeList& , NODE_T [],NODE_T[],SUM_T &);
    void primalDual(LightGraph &, WeightEdgeList& , NODE_T [],SUM_T &);
    void primalDualb(LightGraph &, WeightEdgeList& , NODE_T [],NODE_T[],SUM_T &);
    void primalDualbNew(LightGraph &, WeightEdgeList& , NODE_T [],NODE_T,SUM_T &);
    void primalDualbNew(LightGraph &, WeightEdgeList& , NODE_T [],NODE_T,SUM_T &, SUM_T&);
    void threeHalfEpsilon(LightGraph &, WeightEdgeList& , NODE_T [],SUM_T &, float = 0.1);
    
    
    void greedyMatchingEdgeCover(LightGraph &, WeightEdgeList& , NODE_T [],SUM_T &);
    
    void greedyMatchingEdgeCover2(LightGraph &, WeightEdgeList& , NODE_T [],SUM_T &);
    void addCheapestEdges(NODE_T , NODE_T [],NODE_T [],EDGE_T [],WeightEdgeList &, WeightEdgeList &, SUM_T &, NODE_T &);

    void addCheapestbEdges(NODE_T , NODE_T [],NODE_T [],EDGE_T [],WeightEdgeList &, WeightEdgeList &, SUM_T &, NODE_T &);
};

#endif
