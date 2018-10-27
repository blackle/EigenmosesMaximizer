#pragma once

#include "Prisoner.h"

class AllDefect : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
