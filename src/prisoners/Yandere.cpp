#include "Yandere.h"

Yandere::Yandere(uint target) : _target(target) {}

Action Yandere::decide(const PrisonerKnowledge& p) const {
	if (p.theirIndex == _target) {
		return Action::Cooperate;
	}
	auto lastAction = (*p.ledger)(_target, p.theirIndex, p.time - 1);
	if (lastAction == Action::Cooperate) {
		return Action::Defect;
	} else {
		return Action::Cooperate;
	}
}
