#ifndef HINT_H
#define HINT_H

enum class Hint_Types {
	Window_Size = 0,
	Update_Period,
	Default_Char,

	NBR_HINT_TYPES
};

class Hint{
private:
	Hint_Types Type;

public:
	virtual Hint_Types GetHintType() const = 0;
	Hint(Hint_Types type);
};

class Hint_Window_Size : public Hint {
public :
	unsigned int SizeX;
	unsigned int SizeY;

	Hint_Window_Size(unsigned int Size_x, unsigned int Size_y);
	virtual Hint_Types GetHintType() const override;
};

class Hint_Update_Period : public Hint {
public:
	unsigned int Period;

	Hint_Update_Period(unsigned int period);
	virtual Hint_Types GetHintType() const override;
};

class Hint_Default_Char : public Hint {
public:
	char d_char;

	Hint_Default_Char(char dChar);
	virtual Hint_Types GetHintType() const override;
};
#endif // !HINT_H