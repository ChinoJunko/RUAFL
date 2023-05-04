/*
 * CFGReachabilityAnalysis.h
 *
 * Basic CFG reachabilityAnalysis
 *
 *  Created on: Jun 19, 2015
 *      Author: Fan Gang
 *
 *  Modified on 02/04/2016
 *  	Author: Qingkai
 *  	Description: make it thread-safe by changing
 *  	the type of reachable from map<unsigned, ReachableSet>
 *  	to ReachableSet[].
 */

#ifndef ANALYSIS_CFG_CFGREACHABILITYANALYSIS_H
#define ANALYSIS_CFG_CFGREACHABILITYANALYSIS_H

#include <utility>
#include <unordered_map>
#include <vector>
// namespace SVF
// {

// class CFGReachability {
// 	typedef llvm::BitVector ReachableSet;
// 	ReachableSet analyzed;
// 	ReachableSet* reachable;

// 	// ID mapping
// 	std::vector<const llvm::BasicBlock *> IDtoBB;
// 	std::unordered_map<const llvm::BasicBlock *, int> BBID;

// public:
// 	CFGReachability(const llvm::Function &F);
// 	~CFGReachability();

// 	/// Returns true if the block 'Dst' can be reached from block 'Src'.
// 	bool isReachable(const llvm::BasicBlock *Src, const llvm::BasicBlock *Dst);

// private:
// 	void mapReachability(const llvm::BasicBlock *Dst);
// };

// class CFGReachabilityAnalysis: public llvm::ModulePass {
// private:
// 	std::unordered_map<const llvm::Function *, CFGReachability *> funcReachMap;

// public:
// 	static char ID;
// 	CFGReachabilityAnalysis() :
// 		ModulePass(ID) {
// 	}

// 	virtual ~CFGReachabilityAnalysis();

// 	bool runOnModule(llvm::Module& M);

// 	void getAnalysisUsage(llvm::AnalysisUsage &AU) const {
// 		AU.setPreservesAll();
// 	}

// public:
// 	/// Returns true if the block 'Dst' can be reached from block 'Src'.
// 	bool isBBReachable(const llvm::BasicBlock *Src, const llvm::BasicBlock *Dst);

// 	/// Determine reachability within one basic block.
// 	bool isReachableInBlock(const llvm::Instruction *Src, const llvm::Instruction *Dst) const;

// 	// Check the reachability from any two instructions in the same function
// 	bool isReachable(const llvm::Instruction *Src, const llvm::Instruction *Dst);

// private:
// 	CFGReachability* getReachabilityResultFor(const llvm::Function*);
// };

// }
#endif /* ANALYSIS_CFG_CFGREACHABILITYANALYSIS_H */
