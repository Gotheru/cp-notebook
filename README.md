# README

Fork of [benq](https://github.com/bqi343/cp-notebook) notebook, with special focus on code verification.

Codes are verified using problems in [vjudge](https://vjudge.net/). The codes for verification are provided in [verify/](https://github.com/Gotheru/cp-notebook/tree/master/Implementations/verify).

To easily compile these codes and submit them to vjudge, ```oj-bundle``` from [online-judge-tools](https://github.com/online-judge-tools/verification-helper) is really helpful.

Here is a list of verified codes as of now:

- [ ] **combinatorial**
    - [ ] DeBrujinSeq.h
    - [ ] IntPerm.h
    - [x] MatroidIsect.h
    - [x] MatroidPart.h
    - [ ] NimProduct.h
    - [ ] PermGroup.h
    - [ ] RSK.h
    - [ ] RSKrecover.h
- [ ] **data-structures**
    - [ ] _1D-range-queries_
        - [ ] BIT.h
        - [ ] BIToff.h
        - [ ] BITrange.h
        - [ ] BitNd.h
        - [ ] ConsecutivePairs.h
        - [ ] LazySegAlt.h
        - [ ] LazySegmentTree.h
        - [ ] LichaoSeg.h
        - [ ] MaxQuery.h
        - [ ] Mo.h
        - [ ] PermTree.h
        - [ ] PSeg.h
        - [ ] RectUnion.h
        - [ ] SegTreeBeats.h
        - [ ] SegmentTree.h
        - [ ] SparseSeg.h
        - [ ] Wavelet.h
        - [ ] pseg1.h
        - [ ] pseg2.h
    - [ ] _2D-range-queries_
        - [ ] BIT2DOff.h
        - [ ] BITseg.h
        - [ ] BITtree.h
        - [ ] SegSeg.h
    - [ ] _STL_
        - [x] Bset.h
        - [ ] CoordCompress.h
        - [ ] HashMap.h
        - [ ] HashMapSmall.h
        - [ ] LineContainer.h
        - [ ] LineContainerNew.h
        - [ ] MapComparator.h
        - [ ] MinDeque.h
        - [ ] OrderStatisticsTree.h
        - [ ] PQ.h
        - [ ] Rope.h
    - [ ] _static-range-queries_
        - [ ] FasterRMQ.h
        - [ ] PrefixSums.h
        - [x] RMQ.h
        - [ ] RangeQuery.h
    - [ ] DynaCon.h
    - [ ] EulerTourTree.h
    - [ ] LeftistHeap.h
    - [ ] Treap.h
- [ ] **geometry**
    - [ ] _3D_
        - [ ] Hull3D.h
        - [ ] Hull3D_kactl.h
        - [ ] Point3D.h
        - [ ] PolySaVol.h
        - [ ] Quater.h
    - [ ] _Circles_
        - [ ] Circle.h
        - [ ] CircleIsect.h
        - [ ] CircleTangents.h
        - [ ] Circumcenter.h
        - [ ] MinEnclosingCirc.h
    - [ ] _Misc_
        - [ ] ClosestPair.h
        - [ ] Delaunay3.h
        - [ ] DelaunayFast.h
        - [ ] DelaunayIncremental.h
        - [ ] KDtree.h
        - [ ] ManhattanMST.h
        - [ ] MaxCollinear.h
        - [ ] kdtree_KACTL.h
    - [ ] _Polygons_
        - [ ] ConvexHull.h
        - [ ] ConvexHullGraham.h
        - [ ] HalfPlaneIsect.h
        - [ ] HalfPlaneSet.h
        - [ ] HullDiameter.h
        - [ ] HullTangents.h
        - [ ] InPolygon.h
        - [ ] LineHull.h
        - [ ] MinkowskiSum.h
        - [ ] PolygonCenArea.h
        - [ ] PolygonUnion.java
        - [ ] PolygonUnion.kt
        - [ ] _old_HalPlaneIsect.h
    - [ ] _Primitives_
        - [ ] AngleCmp.h
        - [ ] Complex.h
        - [ ] ComplexComp.h
        - [ ] Point.h
        - [ ] PointShort.h
        - [ ] SegDist.h
        - [ ] SegIsect.h
- [ ] **graphs**
    - [ ] _Advanced_
        - [ ] ChordalGraphRecognition.h
        - [ ] DirectedMST.h
        - [ ] DirectedMST_KACTL.h
        - [ ] DominatorTree.h
        - [ ] EdgeColor.h
        - [ ] EdgeColorBip.h
        - [ ] KthWalk.h
        - [ ] LCT.h
        - [ ] LoopyNim.h
        - [ ] MaxClique.h
        - [ ] StableRoommates.h
        - [ ] ThreeEdgeCC.h
        - [ ] TopTree.h
        - [ ] TreeDecomp2.h
    - [ ] _Basics_
        - [ ] BellmanFord.h
        - [ ] Dijkstra.h
        - [ ] DirectedCycle.h
        - [ ] FloydWarshall.h
        - [ ] GridBFS.h
        - [ ] NegativeCycle.h
        - [ ] TopoSort.h
        - [ ] TreeTour.h
    - [ ] _DFS_
        - [ ] BCC.h
        - [ ] BipolarOrientation.h
        - [ ] EulerPath.h
        - [ ] MaximalCliques.h
        - [ ] SCCK.h
        - [ ] SCCT.h
        - [ ] TwoSAT.h
    - [ ] _DSU_
        - [x] DSU.h
        - [x] DSUrb.h
        - [ ] DynaCon.h
        - [ ] TwoEdgeCC.h
    - [ ] _Flows_
        - [ ] CapacityScaling.h
        - [ ] Dinic.h
        - [ ] GlobalMinCut.h
        - [ ] GomoryHu.h
        - [ ] HLPP.h
        - [ ] MCMF.h
        - [ ] NetworkSimplex.h
    - [ ] _Matching_
        - [ ] DFSmatch.h
        - [ ] FakeMatch.h
        - [ ] GeneralMatchBlossom.h
        - [ ] GeneralMatchBlossom_Alt.h
        - [ ] GeneralMatchBlossom_Old.h
        - [ ] Hungarian.h
        - [ ] MaxMatchFast.h
        - [ ] MaxMatchHeuristic.h
        - [ ] MaxMatchLexMin.h
    - [ ] _Trees_
        - [ ] Centroid.h
        - [ ] HLD.h
        - [x] LCAjump.h
        - [x] LCArmq.h
        - [ ] SmallToLarge.h
        - [ ] TreeDiameter.h
- [x] **math**
- [ ] **number-theory**
    - [ ] _Euclid_
        - [x] CRT.h
        - [ ] Euclid.h
        - [ ] FracInterval.h
        - [ ] ModArith.h
    - [ ] _Modular Arithmetic_
        - [ ] DiscreteLog.h
        - [ ] FastMod.h
        - [ ] ModFact.h
        - [ ] ModFactInt.h
        - [ ] ModInt.h
        - [ ] ModInt128.h
        - [ ] ModIntDynamic.h
        - [ ] ModIntShort.h
        - [ ] ModMulLL.h
        - [ ] ModSqrt.h
        - [ ] ModSum.h
        - [ ] Order.h
    - [ ] _Primality_
        - [ ] FactorBasic.h
        - [ ] FactorFast.h
        - [ ] MillerRabin.h
        - [ ] MultiplicativePrefixSums.h
        - [ ] PrimeCnt.h
        - [ ] PrimeCntMin25.h
        - [ ] PrimeCntNeal.h
        - [ ] Sieve.h
- [ ] **numerical**
    - [ ] _Arithmetic_
        - [ ] BigInt.h
        - [ ] ExprParse.h
        - [ ] Frac.h
    - [ ] _Matrix_
        - [ ] CharPoly.h
        - [ ] Hafnian.h
        - [ ] Matrix.h
        - [ ] MatrixInv.h
        - [ ] MatrixTree.h
        - [ ] ShermanMorrison.h
        - [ ] SparseDet.h
        - [ ] XorBasis.h
    - [ ] _Misc_
        - [ ] GoldenSectionSearch.h
        - [ ] Integrate.h
        - [ ] IntegrateAdaptive.h
        - [ ] LinRec.h
        - [ ] LinearRecurrence.h
        - [x] Simplex.h
    - [ ] _Polynomials_
        - [ ] ChirpZ.h
        - [ ] FFT.h
        - [ ] Karatsuba.h
        - [ ] Poly.h
        - [ ] PolyConv.h
        - [ ] PolyEuclid.h
        - [ ] PolyInterpolate.h
        - [ ] PolyInv.h
        - [ ] PolyInvSimpler.h
        - [ ] PolyMultipoint.h
        - [ ] PolyRoots.h
- [ ] **strings**
    - [ ] _Heavy_
        - [ ] PalTree.h
        - [ ] SuffixAutomaton.h
        - [ ] SuffixTree.h
    - [x] _Light_
        - [x] AhoCorasickFixed.h
        - [x] AhoCorasickUnfixed.h
        - [x] HashRange.h
        - [x] KMP.h
        - [x] LyndonFactor.h
        - [x] Manacher.h
        - [x] MinRotation.h
        - [x] ReverseBW.h
        - [x] SuffixArray.h
        - [x] SuffixArrayLinear.h
        - [x] TandemRepeats.h
        - [x] Trie.h
        - [x] TrieAlpha.h
        - [x] Z.h
- [ ] **various**
    - [ ] Bit.kt
    - [ ] BumpAllocator.h
    - [ ] BumpAllocatorSTL.h
    - [ ] CircularLCS.h
    - [ ] Decimal.py
    - [ ] DynaLIS.h
    - [ ] FastIO.h
    - [ ] Knapsack.h
    - [ ] Kotlin.kt
    - [ ] Main.java
    - [ ] Ops.h
    - [ ] Python3.py
    - [ ] SMAWK.h
    - [ ] SmallPtr.h
    - [ ] Ycombinator.h