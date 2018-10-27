#include "ActionLedger.h"
#include <iomanip>

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

std::tuple<uint, uint, uint> ActionLedger::dim() const {
	return std::tuple<uint, uint, uint>(_numRounds, _numBots, _numBots);
}

bool ActionLedger::set(Action val, uint t, uint b1, uint b2) {
	if (t >= _numRounds || b1 >= _numBots || b2 >= _numBots) {
		return false;
	}

	_actions[offsetFromIndexes(t, b1, b2)] = val;
	return true;
}

std::ostream& operator<<(std::ostream& os, const ReadableActionLedger& ledger) {
	auto dims = ledger.dim();
	for (uint t = 0; t < std::get<0>(dims); t++) {
		for (uint b1 = 0; b1 < std::get<1>(dims); b1++) {
			for (uint b2 = 0; b2 < std::get<2>(dims); b2++) {
				switch (ledger.get(t, b1, b2)) {
					case Action::Undefined:
						os << " "; break;
					case Action::Cooperate:
						os << "c"; break;
					case Action::Defect:
						os << "d"; break;
				}
			}
			os << std::endl;
		}
		os << "-----" << std::endl;
	}
	return os;
}
