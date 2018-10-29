#include "TitForTat.h"

Action TitForTat::decide(const PrisonerKnowledge& p) const {
	auto lastAction = (*p.ledger)(p.theirIndex, p.thisIndex, p.time - 1);
	if (lastAction == Action::Undefined) {
		return Action::Cooperate;
	} else {
		return lastAction;
	}
}
