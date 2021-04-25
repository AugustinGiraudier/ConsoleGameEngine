#include "Hint.h"


//class Hint
Hint::Hint(Hint_Types type)
	:Type(type)
{}
Hint_Types Hint::GetHintType() const{
	return Type;
}

//class Hint_Window_Size
Hint_Window_Size::Hint_Window_Size(unsigned int Size_x, unsigned int Size_y)
	: Hint(Hint_Types::Window_Size)
	, SizeX(Size_x)
	, SizeY(Size_y)
{}
Hint_Types Hint_Window_Size::GetHintType() const{
	return Hint::GetHintType();
}

//class Hint_Update_Period
Hint_Update_Period::Hint_Update_Period(unsigned int period)
	:Hint(Hint_Types::Update_Period)
	, Period(period)
{}
Hint_Types Hint_Update_Period::GetHintType() const {
	return Hint::GetHintType();
}

//class Hint_Default_Char
Hint_Default_Char::Hint_Default_Char(char dChar)
	:Hint(Hint_Types::Default_Char)
	, d_char(dChar)
{}
Hint_Types Hint_Default_Char::GetHintType() const {
	return Hint::GetHintType();
}
