#pragma once

#include <iostream>
#include <Types.h>
#include "Action.h"
#include "Readable.h"
#include "Writable.h"

typedef Readable<Action, uint, uint, uint> ReadableActionLedger;
typedef Writable<Action, uint, uint, uint> WritableActionLedger;

std::ostream& operator<<(std::ostream& os, const ReadableActionLedger& ledger);

class ActionLedger : public ReadableActionLedger, public WritableActionLedger {
public:
	ActionLedger(uint numRounds, uint numBots);
	virtual ~ActionLedger();

	Action get(uint t, uint b1, uint b2) const;
	std::tuple<uint, uint, uint> dim() const;
	bool set(Action val, uint t, uint b1, uint b2);

private:
	inline size_t offsetFromIndexes(uint t, uint b1, uint b2) const;

	const uint _numRounds;
	const uint _numBots;
	Action* _actions;
};