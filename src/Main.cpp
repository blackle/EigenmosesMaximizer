#include <model/ActionLedger.h>

int main(int argc, char** argv) {
	auto ledger = new ActionLedger(5, 5);

	ledger->set(Action::Defect, 0, 0, 0);

	delete ledger;
	return 0;
}