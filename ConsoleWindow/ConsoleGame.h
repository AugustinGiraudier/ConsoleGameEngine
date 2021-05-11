/**
 *	 ██████╗ ██████╗       ███████╗███╗   ██╗ ██████╗ ██╗███╗   ██╗███████╗
 *	██╔════╝██╔════╝       ██╔════╝████╗  ██║██╔════╝ ██║████╗  ██║██╔════╝
 *	██║     ██║  ███╗█████╗█████╗  ██╔██╗ ██║██║  ███╗██║██╔██╗ ██║█████╗
 *	██║     ██║   ██║╚════╝██╔══╝  ██║╚██╗██║██║   ██║██║██║╚██╗██║██╔══╝
 *	╚██████╗╚██████╔╝      ███████╗██║ ╚████║╚██████╔╝██║██║ ╚████║███████╗
 *	 ╚═════╝ ╚═════╝       ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝╚═╝  ╚═══╝╚══════╝
 *
 * -------------------------------------------------------------------------
 * 
 * \file Entête de la classe principale de Console_Game_Engine.
 * 
 * -------------------------------------------------------------------------
 * 
 * \author Augustin Giraudier
 *	---> https://github.com/AugustinGiraudier
 * 
 * -------------------------------------------------------------------------
 * 
 * \version 1.0
 * \date Apr 28 2021
 * 
 * -------------------------------------------------------------------------*/

#ifndef CONSOLE_GAME_H
#define CONSOLE_GAME_H
#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <exception>
#include <functional>
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
	 * \brief Objet conservant la map de charactères à afficher.
	 */
	CSMap* _Map;

	/**
	 * @biref Taille x de la fenêtre & de la map d'affichage en caractère.
	 */
	unsigned int _Window_Size_x = 130;
	/**
	* \brief Taille y de la fenêtre & de la map d'affichage en caractère.
	*/
	unsigned int _Window_Size_y = 30;

	/**
	 * \brief Temps en millisecondes entre chaque affichege d'image.
	 */
	unsigned int _Update_Period = 100;

	/** \brief Caractère par défaut de la map d'affichage */
	char _Default_Char = ' ';

	/**
	 * \brief Pointeur vers le thread d'affichage.
	 */
	std::thread* _Display_Thread = nullptr;
	/**
	 * \brief Permet d'arreter le thread d'affiche.
	 */
	bool _Stop_Display = false;

	/**
	 * \brief fonction qui sera appelée à chaque tour de boucle du moteur.
	 */
	std::function<void()> _Func_To_Repeat;

	ConsoleGame();
	~ConsoleGame();

	/**
	 * \brief Crée une nouvelle map d'affichage avec les paramètres actuels.
	 */
	void Recreate_Map();
	/**
	 * \brief Affiche la map à intervalle de temps régulier.
	 * Note : vous pouvez paramétrer ce temps avec l'indice Window_Size et la fonction Set_Hint.
	 */
	void Display_Map_Repete();

public:

	/*------------------------------------------------------------------------------*/
	/*	PROCESSUS																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief Récupère l'instance unique de gestion de jeu.
	 * 
	 * \return l'instance unique de gestion de jeu
	 */
	static ConsoleGame* Get_Console_Game_Instance();

	/**
	 * \brief Permet d'appliquer une indication de construction du jeu.
	 * 
	 * \param hint Objet référencant l'indication à appliquer
	 *  -- Exemples : Hint_Window_Size - Hint_Update_Period - Hint_Default_Char
	 */
	void Set_Hint(Hint* hint);

	/**
	 * \brief Permet d'arrêter correctement le processus.
	 * 
	 */
	void Close_Console_Game();
	
	/*------------------------------------------------------------------------------*/
	/*	OUTILS																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief Récupération de la dimension x de la fenêtre et de la map d'affichage (en nombre de caractère).
	 * 
	 * \return la dimension x (en nombre de caractère)
	 */
	const unsigned int Get_Dim_X() const { return _Window_Size_x; }

	/**
	 * \brief Récupération de la dimension y de la fenêtre et de la map d'affichage (en nombre de caractère).
	 *
	 * \return la dimension y (en nombre de caractère)
	 */
	const unsigned int Get_Dim_Y() const { return _Window_Size_y; }

	/**
	 * \brief Récupération de la durée d'intervalle entre chaque affichage.
	 * 
	 * \return la durée d'intervalle entre chaque affichage
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
	 * \brief Permet de placer un charactère à des coordonnées dans le buffer d'affichage.
	 * 
	 * \param c : caractère à insérer
	 * \param x	: position x
	 * \param y : position y
	 */
	void Set_Char_At(char c, unsigned int x, unsigned int y);

	/**
	 * \brief Permet de remplir le buffer d'affichage avec un caractère.
	 * 
	 * \param c : caractère à insérer
	 */
	void Full_Fill(char c);

	/**
	 * \brief Permet de remplir une ligne du buffer d'affichage avec un caractère.
	 * 
	 * \param c :		caractère à insérer
	 * \param Row_Id :	index de la ligne à remplir
	 */
	void Set_Char_At_Row(char c, unsigned int Row_Id);

	/**
	 * \brief Permet de remplir une colonne du buffer d'affichage avec un caractère.
	 *
	 * \param c :		caractère à insérer
	 * \param Col_Id :	index de la colonne à remplir
	 */
	void Set_Char_At_Col(char c, unsigned int Col_Id);

	/**
	 * \brief Permet d'insérer une chaine de caractère dans le buffer d'affiche à partir d'une coordonnée donnée.
	 * 
	 * \param str : chaine à afficher
	 * \param x :	coordonnée x du premier caractère
	 * \param y :	coordonnée y du premier caractère
	 */
	void set_Str_At(const std::string& str, unsigned int x, unsigned int y);

	/**
	 * \brief Permet d'inérer une map CSMap (map de caractères) à des coordonnées dans le buffer d'affichage
	 * le point de coordonnées correspond au coin suppérieur gauche de la CSMap.
	 * 
	 * \param map : map à dessiner
	 * \param x :	coordonnée x du coin suppérieur gauche dans la map principale
	 * \param y :	coordonnée y du coin suppérieur gauche dans la map principale
	 */
	void Set_CSMap_At(CSMap& map, unsigned int x, unsigned int y);

	/*------------------------------------------------------------------------------*/
	/*	OPERATEURS SUPPRIMES														*/
	/*------------------------------------------------------------------------------*/

	ConsoleGame(ConsoleGame& other) = delete;
	void operator=(const ConsoleGame& other) = delete;
};
#endif
