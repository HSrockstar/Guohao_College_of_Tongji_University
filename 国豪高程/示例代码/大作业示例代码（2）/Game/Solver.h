#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <cstdint>
#include <atomic>

struct Jump { int from, over, to; };

void Solver_Init();
bool solve(uint64_t start, std::atomic<bool>& cancel);

extern std::vector<Jump> bestPath;
extern int xy2idx[7][7];
extern int idx2x[];
extern int idx2y[];

#endif