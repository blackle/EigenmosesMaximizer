#include "Action.h"

Action operator~(const Action& action) {
	Action newAction(action);

	if (action == Action::Cooperate) {
		newAction = Action::Defect;
	} else if (action == Action::Defect) {
		newAction = Action::Cooperate;
	}

	return newAction;
}

std::ostream& operator<<(std::ostream& o, const Action& action) {
	switch (action) {
		default:
		case (Action::Undefined):
			break;
		case (Action::Cooperate):
			o << "c";
			break;
		case (Action::Defect):
			o << "d";
			break;
	}
	return o;
}
