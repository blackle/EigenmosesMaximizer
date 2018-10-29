#include "TitForTwoTats.h"

Action TitForTwoTats::decide(const PrisonerKnowledge& p) const {
	auto lastAction = (*p.ledger)(p.theirIndex, p.thisIndex, p.time - 1);
	auto secondAction = (*p.ledger)(p.theirIndex, p.thisIndex, p.time - 2);
	if (lastAction == Action::Defect && secondAction == Action::Defect) {
		return Action::Defect;
	} else {
		return Action::Cooperate;
	}
}
