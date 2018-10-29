#include "Jailhouse.h"
#include "Ledger.h"
#include <assert.h>

Jailhouse::Jailhouse(PrisonerList* prisoners, uint numRounds)
	: _prisoners(prisoners)
	, _numBots(prisoners->size())
	, _numRounds(numRounds)
	, _currRound(0)
	, _ledger(new Ledger(_numBots, _numRounds))
{}

Jailhouse::~Jailhouse() {
	delete _ledger;
}

const Ledger* Jailhouse::ledger() const {
	return _ledger;
}

void Jailhouse::run() {
	for (uint t = 0; t < _numRounds; t++) {
		for (uint b1 = 0; b1 < _numBots; b1++) {
			for (uint b2 = 0; b2 < _numBots; b2++) {
				auto b1choice = runSingleSide(b1, b2, t);
				auto b2choice = runSingleSide(b2, b1, t);
				if (b1 == b2) {
					assert(b1choice == b2choice);
				}
				(*_ledger)(b1, b2, t) = b1choice;
				(*_ledger)(b2, b1, t) = b2choice;
			}
		}
	}
}

Action Jailhouse::runSingleSide(uint b1, uint b2, uint t) const {
	PrisonerKnowledge knowledge(_ledger, b1, b2, t);
	auto choice = (*_prisoners)[b1]->decide(knowledge);
	assert(choice != Action::Undefined);
	return choice;
}