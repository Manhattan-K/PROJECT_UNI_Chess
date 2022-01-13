/*  FILIPPO FRANCESCHETTO  */

#include "Position.h"

Position::Position(const Position& piece)
{
	letter = piece.letter;
	number = piece.number;
}
Position& Position::operator=(const Position& piece)
{
	letter = piece.letter;
	number = piece.number;
	return *this;
}
Position::Position(Position&& piece)
{
	letter = piece.letter;
	number = piece.number;
	piece.letter = 0;
	piece.number = 0;
}
Position& Position::operator=(Position&& piece)
{
	letter = piece.letter;
	number = piece.number;
	piece.letter = 0;
	piece.number = 0;
	return *this;
}

//get
int Position::get_letter() 
{	return letter;	}
int Position::get_number()
{	return number;	}

//set
void Position::set_position(int x, int y)
{
	letter = x;
	number = y;
}