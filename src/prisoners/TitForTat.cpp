#include "TitForTat.h"

Action TitForTat::decide(const PrisonerKnowledge& p) const {
	auto lastAction = p.ledger->get(p.time - 1, p.theirIndex, p.thisIndex);
	if (lastAction == Action::Undefined) {
		return Action::Cooperate;
	} else {
		return lastAction;
	}
}
