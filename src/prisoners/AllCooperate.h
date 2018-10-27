#pragma once

#include "Prisoner.h"

class AllCooperate : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
