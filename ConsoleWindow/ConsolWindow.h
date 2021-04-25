#ifndef CONSOLE_WINDOW_H
#define CONSOLE_WINDOW_H

#include <windows.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <exception>
#include "Hint.h"
#include "CSMap.h"


class ConsolWindow
{
private:
	static ConsolWindow* CW_Instance;

	CSMap* map;

	//window size
	unsigned int Window_Size_x = 130;
	unsigned int Window_Size_y = 30;

	//update period
	unsigned int m_fUpdatePeriod = 100;

	//default char
	char default_char = ' ';

	//thread d'affichage
	std::thread* Display_Thread = nullptr;
	bool StopDisplay = false;

	//fct
	ConsolWindow() {}
	~ConsolWindow();
	void RecreateMap();
	void DisplayMapRepete();

public:

	//OPERATEURS
	ConsolWindow(ConsolWindow& other) = delete;
	void operator=(const ConsolWindow& other) = delete;

	//PROCESSUS
	static ConsolWindow* GetConsolWindow();
	void SetWindowHint(Hint* hint);
	void QuitConsol();
	
	//	AFFICHAGE
	void Start_Display();
	void Stop_Display();
	void Display_1_Frame();

	//	DESSIN
	void SetCharAt(char c, unsigned int x, unsigned int y);
	void Full_Fill(char c);
	void SetCharAtRow(char c, unsigned int Row_Id);
	void SetCharAtCol(char c, unsigned int Col_Id);
	void setStrAt(const std::string& str, unsigned int x, unsigned int y);
};
#endif
