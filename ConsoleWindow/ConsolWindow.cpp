#include "ConsolWindow.h"

ConsoleGame* ConsoleGame::_CW_Instance;

void ConsoleGame::Recreate_Map()
{
	delete _Map;
	_Map = new CSMap(_Window_Size_x, _Window_Size_y, _Default_Char);
}

ConsoleGame::~ConsoleGame()
{
	delete _Display_Thread;
}
ConsoleGame::ConsoleGame()
{
	Recreate_Map();
}

ConsoleGame* ConsoleGame::Get_Console_Game_Instance() {
	if (ConsoleGame::_CW_Instance == nullptr)
		ConsoleGame::_CW_Instance = new ConsoleGame;
	return ConsoleGame::_CW_Instance;
}

void ConsoleGame::Start_Display() {
	SetWindowPos(GetConsoleWindow(), HWND_TOP, 0, 0, (_Window_Size_x*7.2) +32, (_Window_Size_y*15.9) +58, SWP_SHOWWINDOW);
	SetConsoleOutputCP(65000);

	if (_Map == nullptr)
		Recreate_Map();

	_Stop_Display = false;
	_Display_Thread = new std::thread(&ConsoleGame::Display_Map_Repete, this);
}

void ConsoleGame::Display_Map_Repete() {
	for (;;) {
		if (this->_Stop_Display)
			return;
		std::cout << "\t\r" << std::flush << _Map->Get_Str();
		std::this_thread::sleep_for(std::chrono::milliseconds(this->_Update_Period));
	}
}

void ConsoleGame::Set_Hint(Hint* hint) {

	Hint_Types type = hint->GetHintType();

	if (type == Hint_Types::Window_Size) {
		Hint_Window_Size* hws = static_cast<Hint_Window_Size*>(hint);
		this->_Window_Size_x = hws->SizeX;
		this->_Window_Size_y = hws->SizeY;
		Recreate_Map();
		return;
	}
	else if ((type == Hint_Types::Update_Period)) {
		Hint_Update_Period* hup = static_cast<Hint_Update_Period*>(hint);
		_Update_Period = hup->Period;
		return;
	}
	else if ((type == Hint_Types::Default_Char)) {
		Hint_Default_Char* hdc = static_cast<Hint_Default_Char*>(hint);
		_Default_Char = hdc->d_char;
		Recreate_Map();
		return;
	}
}

void ConsoleGame::Close_Console_Game() {
	if (_CW_Instance != nullptr) {
		_CW_Instance->Stop_Display();
	}
	delete _Map;
	delete ConsoleGame::_CW_Instance;
}

void ConsoleGame::Stop_Display()
{
	this->_Stop_Display = true;
	if (_Display_Thread->joinable())
		_Display_Thread->join();
	//delete Display_Thread;
}

void ConsoleGame::Display_1_Frame()
{
	std::cout << "\t\r" << std::flush << _Map->Get_Str();
}

void ConsoleGame::Set_Char_At(char c, unsigned int x, unsigned int y)
{
	if (x >= _Map->Get_Dim_X() || y >= _Map->Get_Dim_Y()) {
		throw std::exception("ERREUR : Vous tentez d'�crire en dehors de l'�cran...");
	}
	(*_Map)[x][y] = c;
}

void ConsoleGame::Full_Fill(char c)
{
	_Map->Full_Fill(c);
}

void ConsoleGame::Set_Char_At_Row(char c, unsigned int Row_Id)
{
	_Map->Set_Char_At_Row(c, Row_Id);
}

void ConsoleGame::Set_Char_At_Col(char c, unsigned int Col_Id)
{
	_Map->Set_Char_At_Col(c, Col_Id);
}

void ConsoleGame::set_Str_At(const std::string& str, unsigned int x, unsigned int y)
{
	_Map->Set_Str_At(str, x, y);
}
