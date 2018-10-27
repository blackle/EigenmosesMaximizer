#include "GrimTrigger.h"

Action GrimTrigger::decide(const PrisonerKnowledge& p) const {
	//This kinda sucks, but I'm gonna put off giving these classes state for now...
	uint curtime = p.time - 1;
	Action lastAction;
	while ((lastAction = p.ledger->get(curtime, p.theirIndex, p.thisIndex)) != Action::Undefined) {
		if (lastAction == Action::Defect) {
			return Action::Defect; 
		}
		curtime--;
	}
	return Action::Cooperate;
}
