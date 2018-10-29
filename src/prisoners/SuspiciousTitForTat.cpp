#include "SuspiciousTitForTat.h"

Action SuspiciousTitForTat::decide(const PrisonerKnowledge& p) const {
	auto lastAction = (*p.ledger)(p.theirIndex, p.thisIndex, p.time - 1);
	if (lastAction != Action::Cooperate) {
		return Action::Defect;
	} else {
		return Action::Cooperate;
	}
}
