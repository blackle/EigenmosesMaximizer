#pragma once

#include "Prisoner.h"
#include <model/ActionLedger.h>

class Playback : public Prisoner {
public:
	Playback(ActionLedger* ledger);
	Action decide(const PrisonerKnowledge& p) const;
private:
	const ActionLedger * const _ledger;
};
