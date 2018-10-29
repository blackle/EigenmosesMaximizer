#pragma once

#include <vector>
#include <memory>
#include <model/Ledger.h>

struct PrisonerKnowledge {
	PrisonerKnowledge(const Ledger* ledger, uint thisIndex, uint theirIndex, int time)
		: ledger(ledger)
		, thisIndex(thisIndex)
		, theirIndex(theirIndex)
		, time(time) {};

	const Ledger* ledger;
	uint thisIndex;
	uint theirIndex;
	int time;
};

class Prisoner {
public:
	virtual ~Prisoner() = default;
	virtual Action decide(const PrisonerKnowledge& p) const = 0;
};

typedef std::shared_ptr<Prisoner> PrisonerPointer;
typedef std::vector<PrisonerPointer> PrisonerList;
