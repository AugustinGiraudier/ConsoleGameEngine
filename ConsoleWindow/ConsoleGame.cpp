#include "ConsoleGame.h" 

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
	SetWindowPos(GetConsoleWindow(), HWND_TOP, 0, 0, (_Window_Size_x * 7.2) + 32, (_Window_Size_y * 15.9) + 60, SWP_SHOWWINDOW);
	SetConsoleOutputCP(65000);
}

ConsoleGame* ConsoleGame::Get_Console_Game_Instance() {
	if (ConsoleGame::_CW_Instance == nullptr)
		ConsoleGame::_CW_Instance = new ConsoleGame;
	return ConsoleGame::_CW_Instance;
}

void ConsoleGame::Start_Display() {
	SetWindowPos(GetConsoleWindow(), HWND_TOP, 0, 0, (_Window_Size_x*7.2) +32, (_Window_Size_y*15.9) +60, SWP_SHOWWINDOW);
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
		if (this->_Func_To_Repeat)
			this->_Func_To_Repeat();
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
		SetWindowPos(GetConsoleWindow(), HWND_TOP, 0, 0, (_Window_Size_x * 7.2) + 32, (_Window_Size_y * 15.9) + 60, SWP_SHOWWINDOW);
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
	else if ((type == Hint_Types::Repeat_Function)) {
		Hint_Repeat_Function* hrf = static_cast<Hint_Repeat_Function*>(hint);
		this->_Func_To_Repeat = hrf->_Function_To_Repeat;
		return;
	}
}

void ConsoleGame::Close_Console_Game() {
	if (_CW_Instance != nullptr) {
		_CW_Instance->Stop_Display();
	}
	if(_Map != nullptr)
	delete _Map;
	delete ConsoleGame::_CW_Instance;
}

void ConsoleGame::Stop_Display()
{
	this->_Stop_Display = true;
	if (_Display_Thread != nullptr && _Display_Thread->joinable())
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
		throw std::exception("ERREUR : Vous tentez d'écrire en dehors de l'écran...");
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

void ConsoleGame::Set_CSMap_At(CSMap& map, unsigned int x, unsigned int y)
{
	int x_m = 0;
	int y_m = 0;
	for (int x_c = x; x_c < _Window_Size_x && x_m < map.Get_Dim_X(); ++x_c) {
		y_m = 0;
		for (int y_c = y; y_c < _Window_Size_y && y_m < map.Get_Dim_Y(); ++y_c) {
			Set_Char_At(map[x_m][y_m], x_c, y_c);
			++y_m;
		}
		++x_m;
	}
}

