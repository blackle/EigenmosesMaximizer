#include <prisoners/Prisoner.h>
#include <prisoners/AllCooperate.h>
#include <prisoners/AllDefect.h>
#include <prisoners/Stochastic.h>
#include <prisoners/TitForTat.h>
#include <model/Jailhouse.h>

int main(int argc, char** argv) {
	PrisonerList prisoners({
		PrisonerPointer(new AllCooperate()),
		PrisonerPointer(new AllDefect()),
		PrisonerPointer(new Stochastic(0.50)),
		PrisonerPointer(new TitForTat()),
	});

	Jailhouse jail(&prisoners, 10);
	jail.run();

	auto ledger = jail.ledger();
	std::cout << *ledger;

	return 0;
}