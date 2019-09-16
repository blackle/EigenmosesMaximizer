#include <random>
#include <cstdlib>
#include <prisoners/Prisoner.h>
#include <prisoners/AllCooperate.h>
#include <prisoners/AllDefect.h>
#include <prisoners/Stochastic.h>
#include <prisoners/TitForTat.h>
#include <prisoners/TitForTwoTats.h>
#include <prisoners/TwoTitsForTat.h>
#include <prisoners/SuspiciousTitForTat.h>
#include <prisoners/GrimTrigger.h>
#include <prisoners/Cycler.h>
#include <prisoners/Playback.h>
#include <prisoners/Tsundere.h>
#include <prisoners/Yandere.h>
#include <model/Jailhouse.h>
#include <calc/CooperationMatrixCalc.h>
#include <calc/EigenMosesCalc.h>
#include <calc/ExpMosesCalc.h>
#include <annealing/SimulatedAnnealer.h>
#include <annealing/TemperatureSchedule.h>
#include <annealing/NeighbourGenerator.h>
#include <annealing/EnergyFunction.h>
#include <assert.h>

int main(int, char**) {
	constexpr int iterations = 25;
	constexpr int numBots = 12;

	class EigenMosesEnergy : public EnergyFunction<arma::field<Action>> {
	public:
		float energy(const arma::field<Action>& state) const {
			PrisonerList prisoners({
				PrisonerPointer(new Playback(state)),
				PrisonerPointer(new AllDefect()),
				PrisonerPointer(new AllCooperate()),
				PrisonerPointer(new Tsundere()),
				PrisonerPointer(new Yandere(0)),
				PrisonerPointer(new Yandere(4)),
				PrisonerPointer(new Yandere(5)),
				// PrisonerPointer(new Cycler(9, 1)),
				// PrisonerPointer(new Cycler(1, 9)),
				// PrisonerPointer(new Cycler(1, 1)),
				// PrisonerPointer(new Stochastic(0.25)),
				// PrisonerPointer(new Stochastic(0.50)),
				// PrisonerPointer(new Stochastic(0.75)),
				PrisonerPointer(new TitForTat()),
				PrisonerPointer(new TitForTwoTats()),
				PrisonerPointer(new TwoTitsForTat()),
				PrisonerPointer(new SuspiciousTitForTat()),
				PrisonerPointer(new GrimTrigger()),
			});
			assert(prisoners.size() == numBots);

			Jailhouse jail(&prisoners, iterations);
			jail.run();

			auto ledger = jail.ledger();

			auto coop = CooperationMatrixCalc::calc(ledger);
			auto scores = EigenMosesCalc::calc(coop);

			return -scores(0);
		};
	};

	class MyTemperatureSchedule : public TemperatureSchedule {
	public:
		float temperature(float time) const {
			return std::pow(1.0 - time, 4.0)*0.05 + 0.00005;
		};
	};

	class ActionNeighbourGenerator : public NeighbourGenerator<arma::field<Action>> {
	public:
		const arma::field<Action> generate(const arma::field<Action>& state) const {
			arma::field<Action> newState(state);
			std::random_device device;
			std::mt19937 generator(device());
			std::uniform_int_distribution<int> rowDist(0, state.n_rows-1);
			std::uniform_int_distribution<int> colDist(0, state.n_cols-1);
			// std::bernoulli_distribution rowInvertDist(0.1);
			std::bernoulli_distribution colInvertDist(0.1);
			std::bernoulli_distribution swapDist(0.1);

			int randRow = rowDist(generator);
			int randCol = colDist(generator);

			// bool rowInvert = rowInvertDist(generator);
			bool colInvert = false;// colInvertDist(generator);
			bool swap = swapDist(generator);

			if (colInvert) {
				for (uint i = 0; i < state.n_rows; i++) {
					newState(i, randCol) = ~newState(i, randCol);
				}
			} else if (swap && randRow < (int)state.n_rows - 1) {
				std::swap(newState(randRow, randCol), newState(randRow + 1, randCol));
			} else {
				newState(randRow, randCol) = ~newState(randRow, randCol);
			}

			return newState;
		};
	};

	arma::field<Action> initState(iterations, numBots);
	initState.fill(Action::Cooperate);
	SimulatedAnnealer<arma::field<Action>> annealer(500000, initState, new ActionNeighbourGenerator(), new EigenMosesEnergy(), new MyTemperatureSchedule());
	annealer.anneal();

	auto finalState = annealer.currentState();
	for (uint row = 0; row < finalState.n_rows; row++) {
		for (uint col = 0; col < finalState.n_cols; col++) {
			std::cout << finalState(row, col) << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}

// TODO:
//  * consider giving the bots state for speed, but keep them const, and pass lambdas that create them into Jailhouse so if we want to reset their state later we can just realloc them
//  * figure out the deal with passing uint vs int into the various places
//  * add all the bots that are in tyler's paper
