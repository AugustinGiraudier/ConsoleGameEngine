#ifndef CONSOLE_WINDOW_H
#define CONSOLE_WINDOW_H

#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <exception>
#include "Hint.h"
#include "CSMap.h"

/**
 * \brief Class encapsulant toute la gestion d'un moteur de jeu pour console Windows.
 * 
 * \author Augustin Giraudier
 */
class ConsoleGame
{
private:
	/**
	 * \brief Instance unique de la classe.
	 */
	static ConsoleGame* _CW_Instance;

	/**
	 * \brief Objet conservant la map de charact�res � afficher.
	 */
	CSMap* _Map;

	/**
	 * @biref Taille x de la fen�tre & de la map d'affichage en caract�re.
	 */
	unsigned int _Window_Size_x = 130;
	/**
	* \brief Taille y de la fen�tre & de la map d'affichage en caract�re.
	*/
	unsigned int _Window_Size_y = 30;

	/**
	 * \brief Temps en millisecondes entre chaque affichege d'image.
	 */
	unsigned int _Update_Period = 100;

	/** \brief Caract�re par d�faut de la map d'affichage */
	char _Default_Char = ' ';

	/**
	 * \brief Pointeur vers le thread d'affichage.
	 */
	std::thread* _Display_Thread = nullptr;
	/**
	 * \brief Permet d'arreter le thread d'affiche.
	 */
	bool _Stop_Display = false;

	ConsoleGame();
	~ConsoleGame();

	/**
	 * \brief Cr�e une nouvelle map d'affichage avec les param�tres actuels.
	 */
	void Recreate_Map();
	/**
	 * \brief Affiche la map � intervalle de temps r�gulier.
	 * Note : vous pouvez param�trer ce temps avec l'indice Window_Size et la fonction Set_Hint.
	 */
	void Display_Map_Repete();

public:

	/*------------------------------------------------------------------------------*/
	/*	PROCESSUS																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief R�cup�re l'instance unique de gestion de jeu.
	 * 
	 * \return l'instance unique de gestion de jeu
	 */
	static ConsoleGame* Get_Console_Game_Instance();

	/**
	 * \brief Permet d'appliquer une indication de construction du jeu.
	 * 
	 * \param hint Objet r�f�rencant l'indication � appliquer
	 *  -- Exemples : Hint_Window_Size - Hint_Update_Period - Hint_Default_Char
	 */
	void Set_Hint(Hint* hint);

	/**
	 * \brief Permet d'arr�ter correctement le processus.
	 * 
	 */
	void Close_Console_Game();
	
	/*------------------------------------------------------------------------------*/
	/*	OUTILS																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief R�cup�ration de la dimension x de la fen�tre et de la map d'affichage (en nombre de caract�re).
	 * 
	 * \return la dimension x (en nombre de caract�re)
	 */
	const unsigned int Get_Dim_X() const { return _Window_Size_x; }

	/**
	 * \brief R�cup�ration de la dimension y de la fen�tre et de la map d'affichage (en nombre de caract�re).
	 *
	 * \return la dimension y (en nombre de caract�re)
	 */
	const unsigned int Get_Dim_Y() const { return _Window_Size_y; }

	/**
	 * \brief R�cup�ration de la dur�e d'intervalle entre chaque affichage.
	 * 
	 * \return la dur�e d'intervalle entre chaque affichage
	 */
	const unsigned int Get_Update_Period() const { return _Update_Period; }

	/*------------------------------------------------------------------------------*/
	/*	AFFICHAGE																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief Lance la boucle infinie d'affichage.
	 * 
	 */
	void Start_Display();

	/**
	 * \brief Stop la boucle d'affichage en cours.
	 * 
	 */
	void Stop_Display();

	/**
	 * \brief Affiche l'image du buffer actuel.
	 * 
	 */
	void Display_1_Frame();

	/*------------------------------------------------------------------------------*/
	/*	DESSIN																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief Permet de placer un charact�re � des coordonn�es dans le buffer d'affichage.
	 * 
	 * \param c : caract�re � ins�rer
	 * \param x	: position x
	 * \param y : position y
	 */
	void Set_Char_At(char c, unsigned int x, unsigned int y);

	/**
	 * \brief Permet de remplir le buffer d'affichage avec un caract�re.
	 * 
	 * \param c : caract�re � ins�rer
	 */
	void Full_Fill(char c);

	/**
	 * \brief Permet de remplir une ligne du buffer d'affichage avec un caract�re.
	 * 
	 * \param c :		caract�re � ins�rer
	 * \param Row_Id :	index de la ligne � remplir
	 */
	void Set_Char_At_Row(char c, unsigned int Row_Id);

	/**
	 * \brief Permet de remplir une colonne du buffer d'affichage avec un caract�re.
	 *
	 * \param c :		caract�re � ins�rer
	 * \param Col_Id :	index de la colonne � remplir
	 */
	void Set_Char_At_Col(char c, unsigned int Col_Id);

	/**
	 * \brief Permet d'ins�rer une chaine de caract�re dans le buffer d'affiche � partir d'une coordonn�e donn�e.
	 * 
	 * \param str : chaine � afficher
	 * \param x :	coordonn�e x du premier caract�re
	 * \param y :	coordonn�e y du premier caract�re
	 */
	void set_Str_At(const std::string& str, unsigned int x, unsigned int y);

	/**
	 * \brief Permet d'in�rer une map CSMap (map de caract�res) � des coordonn�es dans le buffer d'affichage
	 * le point de coordonn�es correspond au coin supp�rieur gauche de la CSMap.
	 * 
	 * \param map : map � dessiner
	 * \param x :	coordonn�e x du coin supp�rieur gauche dans la map principale
	 * \param y :	coordonn�e y du coin supp�rieur gauche dans la map principale
	 */
	void Set_CSMap_At(CSMap& map, unsigned int x, unsigned int y);

	/*------------------------------------------------------------------------------*/
	/*	OPERATEURS SUPPRIMES														*/
	/*------------------------------------------------------------------------------*/

	ConsoleGame(ConsoleGame& other) = delete;
	void operator=(const ConsoleGame& other) = delete;
};
#endif
