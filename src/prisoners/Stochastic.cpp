#include "Stochastic.h"

Stochastic::Stochastic(float coopProb, uint seed)
	: _coopProb(coopProb)
	, _seed(seed)
{}

Action Stochastic::decide(const PrisonerKnowledge& p) const {
	std::mt19937 gen;
	std::seed_seq sseq {_seed, (uint)p.time, p.thisIndex, p.theirIndex};
	gen.seed(sseq);
	std::bernoulli_distribution dist(_coopProb);

	if (dist(gen)) {
		return Action::Cooperate;
	} else {
		return Action::Defect;
	}
}
