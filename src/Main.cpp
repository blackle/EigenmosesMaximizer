#include <prisoners/Prisoner.h>
#include <prisoners/AllCooperate.h>
#include <prisoners/AllDefect.h>
#include <prisoners/Stochastic.h>
#include <prisoners/TitForTat.h>
#include <prisoners/GrimTrigger.h>
#include <model/Jailhouse.h>

int main(int argc, char** argv) {
	PrisonerList prisoners({
		PrisonerPointer(new AllCooperate()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new Stochastic(0.5)),
		PrisonerPointer(new TitForTat()),
		PrisonerPointer(new GrimTrigger()),
	});

	Jailhouse jail(&prisoners, 10);
	jail.run();

	auto ledger = jail.ledger();
	std::cout << *ledger;

	return 0;
}