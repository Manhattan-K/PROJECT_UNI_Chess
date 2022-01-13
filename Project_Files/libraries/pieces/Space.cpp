/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: SPACE.H
	Classe figlia di Piece.h.
	Realizza la casella vuota { int Type = 0 }.
    Non è una vera e propria pedina ma è utile per la realizzazione di Chessboard.
*/

#include "Space.h"
#include "Chessboard.h"

//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
Space::Space(const Space& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
}

Space& Space::operator=(const Space& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	return *this;
}
	
	//Costruttore e assegnamento di spostamento
Space::Space(Space&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
}

Space& Space::operator=(Space&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
	return *this;
}


//= -------------------------------------------- -= Funzioni di Space = -------------------------------------------- -=
	//Overload di get_moves()
std::vector<std::vector<Position>> Space::get_moves(const Chessboard & board)
{
	return std::vector<std::vector<Position>> {};
}