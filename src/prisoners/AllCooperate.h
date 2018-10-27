#pragma once

#include "Prisoner.h"

class AllCooperate : public Prisoner {
	Action decide(const PrisonerKnowledge& p) const;
};
