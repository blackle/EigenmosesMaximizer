#include "TitForTat.h"

Action TitForTat::decide(const PrisonerKnowledge& p) const {
	auto lastAction = (*p.ledger)(p.theirIndex, p.thisIndex, p.time - 1);
	if (lastAction == Action::Defect) {
		return Action::Defect;
	} else {
		return Action::Cooperate;
	}
}
