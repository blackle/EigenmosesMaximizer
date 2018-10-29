#pragma once

#include <prisoners/Prisoner.h>

class Ledger;

class Jailhouse {
public:
	Jailhouse(PrisonerList* prisoners, uint numRounds);
	Jailhouse(const Jailhouse&) = delete;
	~Jailhouse();

	const Ledger* ledger() const;

	void run();

private:

	Action runSingleSide(uint b1, uint b2, uint t) const;

	const PrisonerList * const _prisoners;
	const uint _numBots;
	const uint _numRounds;
	uint _currRound;
	Ledger * const _ledger;
};
