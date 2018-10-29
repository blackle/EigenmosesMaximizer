#include "Cycler.h"

Cycler::Cycler(uint coopLen, uint defectLen, uint offset)
	: _coopLen(coopLen)
	, _defectLen(defectLen)
	, _offset(offset)
{}

Action Cycler::decide(const PrisonerKnowledge& p) const {
	auto cycleLen = _coopLen + _defectLen;
	auto idx = (p.time + _offset) % cycleLen;

	if (idx < _coopLen) {
		return Action::Cooperate;
	} else {
		return Action::Defect;
	}
}
