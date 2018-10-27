#pragma once

#include "Prisoner.h"

class AllDefect : public Prisoner {
	Action decide(const PrisonerKnowledge& p) const;
};
