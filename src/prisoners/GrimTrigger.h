#pragma once

#include "Prisoner.h"

class GrimTrigger : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
