#include "ActionLedger.h"

ActionLedger::ActionLedger(uint numRounds, uint numBots)
	: _numRounds(numRounds)
	, _numBots(numBots)
{
	size_t numCells = numBots * numBots * numRounds;
	_actions = new Action[numCells] {};
}

ActionLedger::~ActionLedger() {
	delete[] _actions;
}

size_t ActionLedger::offsetFromIndexes(uint t, uint b1, uint b2) const {
	return t * _numBots * _numBots + b1 * _numBots + b2;
}

Action ActionLedger::get(uint t, uint b1, uint b2) const {
	if (t >= _numRounds || b1 >= _numBots || b2 >= _numBots) {
		return Action::Undefined;
	}

	return _actions[offsetFromIndexes(t, b1, b2)];
}

bool ActionLedger::set(Action val, uint t, uint b1, uint b2) {
	if (t >= _numRounds || b1 >= _numBots || b2 >= _numBots) {
		return false;
	}

	_actions[offsetFromIndexes(t, b1, b2)] = val;
	return true;
}
