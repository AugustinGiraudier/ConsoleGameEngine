#ifndef CSMAP_H
#define CSMAP_H

#include <vector>
#include <string>
#include <sstream>
#include <exception>

class CSMap {
private:
	std::vector<std::vector<char>> _map;
	unsigned int _Dimx;
	unsigned int _Dimy;
	CSMap(CSMap& other);


public:

	const unsigned int GetDimX() const { return _Dimx; }
	const unsigned int GetDimY() const { return _Dimy; }

	
	void operator=(const CSMap& other);

	CSMap();

	CSMap(const unsigned int DimX, const unsigned int DimY, const char DefaultChar = ' ');

	std::string GetStr() const;
	
	std::vector<char>& operator[](unsigned int a);

	void Full_Fill(char c);

	void SetCharAtRow(char c, unsigned int Row_Id);
	void SetCharAtCol(char c, unsigned int Col_Id);

	void setStrAt(const std::string& str, unsigned int x, unsigned int y);
};
#endif