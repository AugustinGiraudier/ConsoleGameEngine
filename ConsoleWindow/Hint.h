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
 * \file Entête de la classe Hint.
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

#ifndef HINT_H
#define HINT_H
#include<functional>

/**
 * \brief Enum des différentes indications pouvant êtres appliquées.
 */
enum class Hint_Types {
	Window_Size,	// Nouvelle taille de fenetre & buffer d'affichage
	Update_Period,	// Nouvelle durée entre mises à jour d'affichage
	Default_Char,	// Nouveau caractère par défaut (pour le buffer d'affichage)
	Repeat_Function	// Mise en place d'une fonction auto appelante
};

/** \brief Classe virtuelle pure servant de base aux classes d'indications */
class Hint{
private:
	Hint_Types Type;
public:
	/**
	 * \brief Permet de récupérer le type d'indication.
	 */
	virtual Hint_Types GetHintType() const = 0;
	Hint(Hint_Types type);
};

class Hint_Window_Size : public Hint {
public :
	unsigned int SizeX;
	unsigned int SizeY;

	/**
	 * \brief création d'une indication de resize de la fenêtre et du buffer d'affichage.
	 * 
	 * \param Size_x : nouvelle taille en abscisses
	 * \param Size_y : nouvelle taille en ordonnées
	 */
	Hint_Window_Size(unsigned int Size_x, unsigned int Size_y);

	/**
	* \brief Permet de récupérer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};

class Hint_Update_Period : public Hint {
public:
	unsigned int Period;

	/**
	 * \brief création d'une indication de durée entre mises à jour d'affichage.
	 * 
	 * \param period : nouvelle durée en millisecondes
	 */
	Hint_Update_Period(unsigned int period);

	/**
	* \brief Permet de récupérer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};

class Hint_Default_Char : public Hint {
public:
	char d_char;

	/**
	 * \brief création d'une indication de caractère par défaut.
	 * 
	 * \param dchar : caractère par défaut qui remplira le buffer d'affichage 
	 */
	Hint_Default_Char(char dChar);

	/**
	* \brief Permet de récupérer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};

class Hint_Repeat_Function : public Hint {
public:
	
	std::function<void()> _Function_To_Repeat;

	/**
	 * \brief création d'une indication de fonction à répéter.
	 *
	 * \param Function_To_Repeat : fonction de type void() qui sera éxécutée à chaque tour de boucle du moteur
	 */
	Hint_Repeat_Function(std::function<void()> Function_To_Repeat);

	/**
	* \brief Permet de récupérer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};
#endif // !HINT_H