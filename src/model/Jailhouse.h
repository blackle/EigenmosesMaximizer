#pragma once

#include <prisoners/Prisoner.h>
#include "ActionLedger.h"

class Jailhouse {
public:
	Jailhouse(PrisonerList* prisoners, uint numRounds);
	Jailhouse(const Jailhouse&) = delete;
	~Jailhouse();

	const ReadableActionLedger* ledger() const;

	void run();

private:

	Action runSingleSide(uint t, uint b1, uint b2) const;

	const PrisonerList * const _prisoners;
	const uint _numRounds;
	uint _currRound;
	ActionLedger * const _ledger;
};
