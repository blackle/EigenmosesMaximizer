#include "Jailhouse.h"
#include <assert.h>

Jailhouse::Jailhouse(PrisonerList* prisoners, uint numRounds)
	: _prisoners(prisoners)
	, _numRounds(numRounds)
	, _currRound(0)
	, _ledger(new ActionLedger(numRounds, prisoners->size()))
{}

Jailhouse::~Jailhouse() {
	delete _ledger;
}

const ReadableActionLedger* Jailhouse::ledger() const {
	return _ledger;
}

void Jailhouse::run() {
	for (uint t = 0; t < _numRounds; t++) {
		for (uint b1 = 0; b1 < _prisoners->size(); b1++) {
			for (uint b2 = 0; b2 < _prisoners->size(); b2++) {
				auto b1choice = runSingleSide(t, b1, b2);
				auto b2choice = runSingleSide(t, b2, b1);
				if (b1 == b2) {
					assert(b1choice == b2choice);
				}
				_ledger->set(b1choice, t, b1, b2);
				_ledger->set(b2choice, t, b2, b1);
			}
		}
	}
}

Action Jailhouse::runSingleSide(uint t, uint b1, uint b2) const {
	PrisonerKnowledge knowledge(_ledger, t, b1, b2);
	auto choice = (*_prisoners)[b1]->decide(knowledge);
	assert(choice != Action::Undefined);
	return choice;
}