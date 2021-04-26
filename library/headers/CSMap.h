#ifndef CSMAP_H
#define CSMAP_H

#include <vector>
#include <string>
#include <sstream>
#include <exception>


/**
 * \brief classe de gestion du buffer d'affichage.
 */
class CSMap {
private:

	/**
	 * \brief Donn�e brutes (tableau de char 2 dim).
	 */
	std::vector<std::vector<char>> _map;

	/**
	 * \brief Dimension x du buffer.
	 */
	unsigned int _Dimx;

	/**
	 * \brief Dimension y du buffer.
	 */
	unsigned int _Dimy;

	CSMap(CSMap& other);

public:

	/*------------------------------------------------------------------------------*/
	/*	CONSTRUCTEURS																*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief construit un buffer d'affichage param�tr�.
	 * 
	 * \param DimX :		dimension du buffer en abscisses
	 * \param DimY :		dimension du buffer en ordonn�es
	 * \param DefaultChar : caract�re de remplissage
	 */
	CSMap(const unsigned int DimX, const unsigned int DimY, const char DefaultChar = ' ');

	/**
	 * \brief construit un buffer d'affichage vide.
	 * 
	 */
	CSMap();

	/*------------------------------------------------------------------------------*/
	/*	OUTILS																		*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief R�cup�ration de la dimension x du buffer.
	 * 
	 * \return la dimension x du buffer
	 */
	const unsigned int Get_Dim_X() const { return _Dimx; }

	/**
	 * \brief R�cup�ration de la dimension y du buffer.
	 * 
	 * \return la dimension y du buffer.
	 */
	const unsigned int Get_Dim_Y() const { return _Dimy; }

	/**
	 * \brief R�cup�ration du buffer sous forme de string.
	 * 
	 * \return le buffer d'affichage sous forme de string
	 */
	std::string Get_Str() const;
	
	/*------------------------------------------------------------------------------*/
	/*	DESSIN																		*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief Permet de placer un charact�re � des coordonn�es dans le buffer d'affichage.
	 *
	 * \param c : caract�re � ins�rer
	 * \param x	: position x
	 * \param y : position y
	 */
	void Set_Str_At(const std::string& str, unsigned int x, unsigned int y);

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

	/*------------------------------------------------------------------------------*/
	/*	OPERATEURS																	*/
	/*------------------------------------------------------------------------------*/

	/**
	 * \brief permet d'acc�der � une colonne du buffer.
	 * 
	 * \param a : index de la colonne dans le buffer
	 * \return la colonne � l'index a
	 */
	std::vector<char>& operator[](unsigned int a);
	void operator=(const CSMap& other);
};
#endif