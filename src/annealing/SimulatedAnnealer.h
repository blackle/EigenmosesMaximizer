#pragma once

template<typename T>
class NeighbourGenerator;

template<typename T>
class EnergyFunction;

class TemperatureSchedule;

template<typename T>
class SimulatedAnnealer {
public:
	SimulatedAnnealer(int numIters, const T& initialState, const NeighbourGenerator<T>* generator, const EnergyFunction<T>* energy, const TemperatureSchedule* schedule);
	~SimulatedAnnealer();

	void anneal();

	const T& currentState() const;
	float currentEnergy() const;

private:
	int _numIters;
	T _currentState;
	const NeighbourGenerator<T>* _generator;
	const EnergyFunction<T>* _energy;
	const TemperatureSchedule* _schedule;
};

template<typename T>
SimulatedAnnealer<T>::SimulatedAnnealer(int numIters, const T& initialState, const NeighbourGenerator<T>* generator, const EnergyFunction<T>* energy, const TemperatureSchedule* schedule)
	: _numIters(numIters)
	, _currentState(initialState)
	, _generator(generator)
	, _energy(energy)
	, _schedule(schedule)
{
}

template<typename T>
SimulatedAnnealer<T>::~SimulatedAnnealer() {
	delete _generator;
	delete _energy;
	delete _schedule;
}

template<typename T>
void SimulatedAnnealer<T>::anneal() {
	for (int i = 0; i < _numIters; i++) {
		// float time = (float)(i) / (float)(_numIters - 1);
		// float temp = _schedule->temperature(time);

		auto candidate = _generator->generate(_currentState);

		float candidateEnergy = _energy->energy(candidate);
		float currEnergy = _energy->energy(_currentState);

		std::cout << "currEnergy: " << currEnergy << std::endl;

		if (candidateEnergy < currEnergy) {
			_currentState = candidate;
		}
	}
}

template<typename T>
const T& SimulatedAnnealer<T>::currentState() const {
	return _currentState;
}

template<typename T>
float SimulatedAnnealer<T>::currentEnergy() const {
	return _energy->energy(_currentState);
}
