/* FILIPPO FRANCESCHETTO 

	letter -> x = colonna
	number -> y = riga

*/

#ifndef POSITION_H
#define POSITION_H

class Position
{
private:
	int letter {};
	int number {};
public:
	//costruttore
	Position() : letter{ 8 }, number{ 8 } {}
	Position(int x, int y) : letter{ x }, number{ y } {}

	//costruttore di copia
	Position(const Position& piece);
	
	//assegnamento di copia
	Position& operator=(const Position& piece);

	//costruttore di spostamento
	Position(Position&& piece);
	 
	//assegnamento di spostamento
	Position& operator=(Position&& piece);

	//get
	int get_letter();
	int get_number();

	//set
	void set_position(int x, int y);
};

#endif