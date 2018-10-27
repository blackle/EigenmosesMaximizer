#pragma once

#include "ActionLedger.h"

struct PrisonerKnowledge {
	ReadableActionLedger* ledger;
	uint time;
	uint thisIndex;
	uint theirIndex;
};

class Prisoner {
public:
	virtual Action decide(const PrisonerKnowledge& p) const = 0;
};
