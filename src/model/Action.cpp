#include "Action.h"

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
