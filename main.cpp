#include <iostream>

enum class Action {
	Undefined = 0,
	Cooperate = 1,
	Defect = 2,
};

template<typename Type, typename... Indexes>
class Readable {
public:
	virtual Type get(Indexes... indexes) const = 0;
};

template<typename Type, typename... Indexes>
class Writable {
public:
	virtual bool set(Type val, Indexes... indexes) = 0;
};

typedef Readable<Action, uint, uint, uint> ReadableActionLedger;
typedef Writable<Action, uint, uint, uint> WritableActionLedger;

class ActionLedger : public ReadableActionLedger, public WritableActionLedger {
public:
	ActionLedger(uint numRounds, uint numBots);
	~ActionLedger();

	virtual Action get(uint t, uint b1, uint b2) const;
	virtual bool set(Action val, uint t, uint b1, uint b2);

private:
	inline size_t offsetFromIndexes(uint t, uint b1, uint b2) const;

	const int _numRounds;
	const int _numBots;
	Action* _actions;
};

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

void readFromReadable(ReadableActionLedger* readable) {
	std::cout << static_cast<int>(readable->get(0, 0, 0)) << std::endl;
}

int main(int argc, char** argv) {
	auto ledger = new ActionLedger(5, 5);

	ledger->set(Action::Defect, 0, 0, 0);
	readFromReadable(ledger);

	delete ledger;
	return 0;
}