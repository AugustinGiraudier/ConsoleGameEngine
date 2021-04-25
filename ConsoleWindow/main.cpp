#include "ConsolWindow.h"
#include <string>

int main() {

	// Objet Game console principal :
	ConsoleGame* CW = ConsoleGame::Get_Console_Game_Instance();

	// Mes paramètres d'application :
	unsigned int My_Size_X = 60;
	unsigned int My_Size_Y = 30;
	unsigned int Time_Between_Update = 20;


	// indications de construction :
	{ 
		Hint_Window_Size hws(My_Size_X, My_Size_Y);		// fenetre de 130 par 30 caractères
		Hint_Update_Period hup(Time_Between_Update);	// 20 millisecondes entre chaque affichage
		Hint_Default_Char hdc(' ');						// caractère ' ' par défaut
		CW->Set_Hint(&hws);
		CW->Set_Hint(&hup);
		CW->Set_Hint(&hdc);
	}
	
	CW->Full_Fill('='); // on remplis le buffer de 'o'

	//création d'un contour d'image :
	CW->Set_Char_At_Col('|', 0);
	CW->Set_Char_At_Col('|', My_Size_X -1);
	CW->Set_Char_At_Row('-', 0);
	CW->Set_Char_At_Row('-', My_Size_Y -1);


	//lancement de la boucle d'affichage :
	CW->Start_Display();

	//on attend 2 secondes
	std::this_thread::sleep_for(std::chrono::seconds(2));

	//on parcours tout l'écran (sauf le contour) avec un '>' qui se déplace :
	for (int y = 1; y < CW->Get_Dim_Y()-1; ++y) {
		for (int x = 1; x < CW->Get_Dim_X()-1; ++x) {
			int Old_X_Pos = x - 1;
			if(Old_X_Pos != 0)
				CW->Set_Char_At(' ', Old_X_Pos, y);	// on efface l'ancien
			CW->Set_Char_At('>', x, y);				// on replace le nouveau
			std::this_thread::sleep_for(std::chrono::milliseconds(Time_Between_Update)); // on patiente
		}
		CW->Set_Char_At(' ', CW->Get_Dim_X() - 2, y); // on efface l'ancien (à la ligne précédente)
	}

	CW->Stop_Display(); // on arrete l'affichage

	CW->Full_Fill(' '); // puis l'on remplis le buffer de ' '

	CW->Display_1_Frame(); // on affiche 1 fois l'image dans le buffer

	std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // on attend 3 secondes

	//on prepare un message au centre :
	std::string Str_To_Write = "Tu as gagné !!";
	CW->set_Str_At(Str_To_Write, (CW->Get_Dim_X() - Str_To_Write.size()) / 2, CW->Get_Dim_Y() / 2);

	CW->Display_1_Frame(); // on affiche 1 fois l'image dans le buffer (avec le message)

	std::this_thread::sleep_for(std::chrono::milliseconds(3000)); // on attend 3 secondes

	CW->Close_Console_Game(); // on arrete proprement l'application

	return 0;
}
