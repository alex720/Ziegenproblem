// ZiegenProblem.cpp: Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//

//#include <iostream>



#include "randomer.h"
#include <vector>
#include <iostream>
#include <cmath>

//namespace ziegenproblem {

	struct Door {
		int number;
		bool win;
		bool chosen;
		bool open;
		bool lastchose;
	};



	void ZiegenProblem(int rounds, bool shouldchange,bool output) {

		int richtig = 0;


		for (int i = 0; i < rounds; i++) {

			if (i % 100000 == 0) {
				printf("durchlauf bei %d  \n", i);
			}

			std::vector<Door> tueren = {
			Door() = {1,0,0,0,0},
			Door() = { 2,0,0,0,0 },
			Door() = { 3,0,0,0,0 }
			};

			int calcedWin = getRandomValueunder(3);

			switch (calcedWin) {
			case 0:
				tueren[0].win = true;
				output ? wprintf(L" Hinter Tuer 1 ist das Auto \n") : NULL;
				break;
			case 1:
				tueren[1].win = true;
				output ? wprintf(L" Hinter Tuer 2 ist das Auto \n") : NULL;
				break;
			case 2:
				tueren[2].win = true;
				output ? wprintf(L" Hinter Tuer 3 ist das Auto \n") : NULL;
				break;
			default:
				printf("Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error Error ");
				break;
			}

			int calcedChosen = getRandomValueunder(3);

			switch (calcedChosen) {
			case 0:
				tueren[0].chosen = true; 
				output ? wprintf(L" Tuer 1 wurde gewaehlt \n") : NULL;
				break;
			case 1:
				tueren[1].chosen = true;
				output ? wprintf(L" Tuer 2 wurde gewaehlt \n") : NULL;
				break;
			case 2:
				tueren[2].chosen = true;
				output ? wprintf(L" Tuer 3 wurde gewaehlt \n") : NULL;
				break;
			default:
				tueren[0].chosen = true;
				output ? wprintf(L" Tuer 1 wurde gewaehlt \n") : NULL;
				break;
			}


			bool openfound = false;

			while (!openfound) {

				int calcedopen = getRandomValueunder(3);

				switch (calcedopen) {
				case 0:
					if ((tueren[0].win == false) && (tueren[0].chosen == false)) {
						tueren[0].open = true;
						openfound = true;
						output ? wprintf(L" Tuer 1 wurde geoeffnet \n") : NULL;
					}
					break;
				case 1:
					if ((tueren[1].win == false) && (tueren[1].chosen == false)) {
						tueren[1].open = true;
						openfound = true;
						output ? wprintf(L" Tuer 2 wurde geoeffnet \n") : NULL;
					}
					break;
				case 2:
					if ((tueren[2].win == false) && (tueren[2].chosen == false)) {
						tueren[2].open = true;
						openfound = true;
						output ? (L" Tuer 3 wurde geoeffnet \n") : NULL;
					}
					break;
				default:

					break;
				}
			}


			if (shouldchange == true) {


				for (auto it = tueren.begin(); it != tueren.end(); it++) {
					if ((it->chosen == false) && (it->open == false)) {
						it->lastchose = true;
						
						output ? wprintf(L" Nach dem wechsel wird Tuer %d gewaehlt \n",it->number) : NULL;
					}
				}

				bool right = false;
				for (auto it = tueren.begin(); it != tueren.end(); it++) {
					if ((it->lastchose == true) && (it->win == true)) {
						right = true;
						break;
					}
					else {
						right = false;
						
					}
				}
				if (right)
				{
					output ? printf("er hat gewonnen \n") : NULL;
					richtig++;
				}
				else {
					output ? printf("er hat verloren \n") : NULL ;
				}
			}
			
			

			else {
				for (auto it = tueren.begin(); it != tueren.end(); it++) {
					if ((it->chosen == true) && (it->win == true)) {
						richtig++;
					}
				}
			}
			
			output ? printf("-----------------------------naechste runden startet-------------------------------- \n") : NULL;

		}


		float percent = ((float)richtig / (float)rounds) * (float)100;
		
		

		printf("Es sind %d von %d richtig \n", richtig, rounds);

		printf("so viel prozent sind richtig: %f", percent);


	}







	int main()
	{

		initrandomer();

		int rounds;
		bool output;
		bool shouldchange;


		std::cout << "wie viele runden sollen gespielt werden: "; std::cin >> rounds;
		std::cout << std::endl << "soll ein output angezeigt werden(1 = ja / 0 = nein): "; std::cin >> output;
		std::cout << std::endl << "soll der Spieler seine entscheidung aendern oder nicht (1 = ja / 0 = nein): "; std::cin >> shouldchange;

		ZiegenProblem(rounds, shouldchange, output);
		destroyrandomer();
		

		char k;
		std::cin >> k;

		return 0;
	}

//}