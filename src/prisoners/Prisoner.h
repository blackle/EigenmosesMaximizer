#pragma once

#include <vector>
#include <memory>
#include <model/ActionLedger.h>

struct PrisonerKnowledge {
	PrisonerKnowledge(ReadableActionLedger* ledger, uint time, uint thisIndex, uint theirIndex)
		: ledger(ledger)
		, time(time)
		, thisIndex(thisIndex)
		, theirIndex(theirIndex) {};

	const ReadableActionLedger* ledger;
	uint time;
	uint thisIndex;
	uint theirIndex;
};

class Prisoner {
public:
	virtual Action decide(const PrisonerKnowledge& p) const = 0;
};

typedef std::shared_ptr<Prisoner> PrisonerPointer;
typedef std::vector<PrisonerPointer> PrisonerList;
