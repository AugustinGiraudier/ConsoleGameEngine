#include "ConsolWindow.h"

ConsolWindow* ConsolWindow::CW_Instance;

void ConsolWindow::RecreateMap()
{
	delete map;
	map = new CSMap(Window_Size_x, Window_Size_y, default_char);
}

ConsolWindow::~ConsolWindow()
{
	delete Display_Thread;
}

ConsolWindow* ConsolWindow::GetConsolWindow() {
	if (ConsolWindow::CW_Instance == nullptr)
		ConsolWindow::CW_Instance = new ConsolWindow;
	return ConsolWindow::CW_Instance;
}

void ConsolWindow::Start_Display() {
	SetWindowPos(GetConsoleWindow(), HWND_TOP, 0, 0, (Window_Size_x*7.2) +32, (Window_Size_y*15.9) +58, SWP_SHOWWINDOW);

	if (map == nullptr)
		RecreateMap();

	StopDisplay = false;
	Display_Thread = new std::thread(&ConsolWindow::DisplayMapRepete, this);
}

void ConsolWindow::DisplayMapRepete() {
	for (;;) {
		if (this->StopDisplay)
			return;
		std::cout << "\t\r" << std::flush << map->GetStr();
		std::this_thread::sleep_for(std::chrono::milliseconds(this->m_fUpdatePeriod));
	}
}

void ConsolWindow::SetWindowHint(Hint* hint) {

	Hint_Types type = hint->GetHintType();

	if (type == Hint_Types::Window_Size) {
		Hint_Window_Size* hws = static_cast<Hint_Window_Size*>(hint);
		this->Window_Size_x = hws->SizeX;
		this->Window_Size_y = hws->SizeY;
		RecreateMap();
		return;
	}
	else if ((type == Hint_Types::Update_Period)) {
		Hint_Update_Period* hup = static_cast<Hint_Update_Period*>(hint);
		m_fUpdatePeriod = hup->Period;
		return;
	}
	else if ((type == Hint_Types::Default_Char)) {
		Hint_Default_Char* hdc = static_cast<Hint_Default_Char*>(hint);
		default_char = hdc->d_char;
		RecreateMap();
		return;
	}
}

void ConsolWindow::QuitConsol() {
	if (CW_Instance != nullptr) {
		CW_Instance->Stop_Display();
	}
	delete map;
	delete ConsolWindow::CW_Instance;
}

void ConsolWindow::Stop_Display()
{
	this->StopDisplay = true;
	if (Display_Thread->joinable())
		Display_Thread->join();
	//delete Display_Thread;
}

void ConsolWindow::Display_1_Frame()
{
	std::cout << "\t\r" << std::flush << map->GetStr();
}

void ConsolWindow::SetCharAt(char c, unsigned int x, unsigned int y)
{
	if (x >= map->GetDimX() || y >= map->GetDimY()) {
		throw std::exception("ERREUR : Vous tentez d'écrire en dehors de l'écran...");
	}
	(*map)[x][y] = c;
}

void ConsolWindow::Full_Fill(char c)
{
	map->Full_Fill(c);
}

void ConsolWindow::SetCharAtRow(char c, unsigned int Row_Id)
{
	map->SetCharAtRow(c, Row_Id);
}

void ConsolWindow::SetCharAtCol(char c, unsigned int Col_Id)
{
	map->SetCharAtCol(c, Col_Id);
}

void ConsolWindow::setStrAt(const std::string& str, unsigned int x, unsigned int y)
{
	map->setStrAt(str, x, y);
}
