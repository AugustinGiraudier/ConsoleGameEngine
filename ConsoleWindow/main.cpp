#include "ConsolWindow.h"
#include <string>

int main() {

	//Objet Game console principal
	ConsolWindow* CW = ConsolWindow::GetConsolWindow();

	int sizex = 130;
	int sizey = 30;

	//{ //hints
	//	Hint_Window_Size hws(sizex, sizey);
		Hint_Update_Period hup(20);
	//	Hint_Default_Char hdc(' ');
	//	CW->SetWindowHint(&hws);
		CW->SetWindowHint(&hup);
	//	CW->SetWindowHint(&hdc);
	//}
	

	//contour de la map :
	//CW->SetCharAtCol('|', 0);
	//CW->SetCharAtCol('|', sizex-1);
	//CW->SetCharAtRow('-', 0);
	//CW->SetCharAtRow('-', sizey-1);



	//lancement de l'affichage :
	CW->Start_Display();

	std::this_thread::sleep_for(std::chrono::seconds(3));

	for (int y = 0; y < 30; ++y) {
		for (int x = 0; x < 130; ++x) {
			CW->SetCharAt(' ', abs(x - 1), y);
			CW->SetCharAt('0', x, y);
			std::this_thread::sleep_for(std::chrono::milliseconds(20));
		}
		CW->SetCharAt(' ', (unsigned char)(130 - 1), y);
	}
	CW->Full_Fill(' ');


	std::this_thread::sleep_for(std::chrono::milliseconds(2000));

	CW->Stop_Display();


	std::this_thread::sleep_for(std::chrono::seconds(3));

	//arret du process
	CW->QuitConsol();

	return 0;
}
