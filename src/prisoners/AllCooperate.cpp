#include "AllCooperate.h"

Action AllCooperate::decide(const PrisonerKnowledge&) const {
	return Action::Cooperate;
}
