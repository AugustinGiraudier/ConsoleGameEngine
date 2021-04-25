#ifndef HINT_H
#define HINT_H

/**
 * \brief Enum des diff�rentes indications pouvant �tres appliqu�es.
 */
enum class Hint_Types {
	Window_Size,	// Nouvelle taille de fenetre & buffer d'affichage
	Update_Period,	// Nouvelle dur�e entre mises � jour d'affichage
	Default_Char	// Nouveau caract�re par d�faut (pour le buffer d'affichage)
};

/** \brief Classe virtuelle pure servant de base aux classes d'indications */
class Hint{
private:
	Hint_Types Type;
public:
	/**
	 * \brief Permet de r�cup�rer le type d'indication.
	 */
	virtual Hint_Types GetHintType() const = 0;
	Hint(Hint_Types type);
};

class Hint_Window_Size : public Hint {
public :
	unsigned int SizeX;
	unsigned int SizeY;

	/**
	 * \brief cr�ation d'une indication de resize de la fen�tre et du buffer d'affichage.
	 * 
	 * \param Size_x : nouvelle taille en abscisses
	 * \param Size_y : nouvelle taille en ordonn�es
	 */
	Hint_Window_Size(unsigned int Size_x, unsigned int Size_y);

	/**
	* \brief Permet de r�cup�rer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};

class Hint_Update_Period : public Hint {
public:
	unsigned int Period;

	/**
	 * \brief cr�ation d'une indication de dur�e entre mises � jour d'affichage.
	 * 
	 * \param period : nouvelle dur�e en millisecondes
	 */
	Hint_Update_Period(unsigned int period);

	/**
	* \brief Permet de r�cup�rer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};

class Hint_Default_Char : public Hint {
public:
	char d_char;

	/**
	 * \brief cr�ation d'une indication de caract�re par d�faut.
	 * 
	 * \param dchar : caract�re par d�faut qui remplira le buffer d'affichage 
	 */
	Hint_Default_Char(char dChar);

	/**
	* \brief Permet de r�cup�rer le type d'indication.
	*/
	virtual Hint_Types GetHintType() const override;
};
#endif // !HINT_H