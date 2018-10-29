#pragma once

#include "Prisoner.h"

class Cycler : public Prisoner {
public:
	Cycler(uint coopLen, uint defectLen, uint offset = 0);
	Action decide(const PrisonerKnowledge& p) const;
private:
	uint _coopLen;
	uint _defectLen;
	uint _offset;
};
