#include "CSMap.h"

void CSMap::operator=(const CSMap& other) {
	_map = other._map;
	_Dimx = other._Dimx;
	_Dimy = other._Dimy;
	return;
}

CSMap::CSMap() {
	_Dimx = 0;
	_Dimy = 0;
}

CSMap::CSMap(const unsigned int DimX, const unsigned int DimY, const char DefaultChar) {
	_Dimx = DimX;
	_Dimy = DimY;
	_map = std::vector<std::vector<char>>(DimX, std::vector<char>(DimY, DefaultChar));
}

std::string CSMap::GetStr() const {
	std::stringstream ss;
	for (int y = 0; y < _Dimy; ++y) {
		for (int x = 0; x < _Dimx; ++x) {
			ss << _map[x][y];
		}
		ss << '\n';
	}

	return ss.str();
}

std::vector<char>& CSMap::operator[](unsigned int a) {
	return _map[a];
}

void CSMap::Full_Fill(char c) {
	for (int x = 0; x < _Dimx; ++x)
		for (int y = 0; y < _Dimy; ++y) {
			_map[x][y] = c;
		}
}

void CSMap::SetCharAtRow(char c, unsigned int Row_Id) {
	for (int x = 0; x < _Dimx; ++x) {
		_map[x][Row_Id] = c;
	}
}
void CSMap::SetCharAtCol(char c, unsigned int Col_Id) {
	for (int y = 0; y < _Dimy; ++y) {
		_map[Col_Id][y] = c;
	}
}

void CSMap::setStrAt(const std::string& str, unsigned int x, unsigned int y)
{
	int i_str = 0;
	for (int i_tab_x = x; i_tab_x < _Dimx && i_str < str.size(); ++i_tab_x) {
		_map[i_tab_x][y] = str[i_str];
		++i_str;
	}
}
