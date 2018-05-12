#pragma once

#include <random>
#include <chrono>
#include <iostream>



	std::mt19937 *randomNumberGenerator;

	void initrandomer() {

		unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();

		randomNumberGenerator = new std::mt19937(seed1);

	}

	
	int getRandomValueunder(int max) {

		int rand = (*randomNumberGenerator)();
		if (rand <= 0) {
			rand *= -1; 
		}

		//std::cout << rand << std::endl;;
		return (rand % max);

	}


	void destroyrandomer() {

		delete randomNumberGenerator;

	}

