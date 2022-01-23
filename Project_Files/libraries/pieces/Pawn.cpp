/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: PAWN.CPP
	Classe figlia di Piece.h.
	Realizzazione della classe Pawn.h, cio� della realizzazione delle funzioni la cui definizione � mancante.

*/

#include "Pawn.h"
#include "Chessboard.h"

//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
	//Costruttore e assegnamento di copia
Pawn::Pawn(const Pawn& arg)
	: moved{arg.moved}
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
}
Pawn& Pawn::operator=(const Pawn& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	moved = arg.moved;
	return *this;
}

	//Costruttore e assegnamento di spostamento
Pawn::Pawn(Pawn&& arg)
	: moved{ arg.moved }
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;

	arg.die();
	arg.moved = false;
}

Pawn& Pawn::operator=(Pawn&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	moved = arg.moved;

	arg.die();
	arg.moved = false;
	return *this;
}


//=---------------------------------------------=Funzioni di Pawn=---------------------------------------------=
	//Overload di get_moves()
std::vector<std::vector<Position>> Pawn::get_moves(Chessboard& board)
{
	//Creazione oggetti
	Chessboard cb = board;
	std::vector<std::vector<Position>> moves{ {}, {}};

	//Chiamata alle varie funzioni
	ahead(cb, moves);
	cross_left(cb, moves);
	cross_right(cb, moves);
	return moves;
}

	//Overload di check_piece()
void Pawn::check_piece(Piece* target, Position& target_pos, std::vector<std::vector<Position>>& moves)
{
	//Se nella posizione c'� una pedina del team nemico, inserisci la posizione nel secondo vettore
	if(target->get_team() != team && target->get_type() != 0)
		moves[1].push_back(target_pos);
}

	//Funzioni per il movimento
void Pawn::ahead(Chessboard& board, std::vector<std::vector<Position>>& moves)
{	
	//In base al colore della pedina, il pedone si muove verso sud (Nera) o verso nord (Bianca)
		//Default Nera
	int two{ 2 };
	int one{ 1 };
		//Bianca
	if (team) { one = -1; two = -2; }

	//Se il pedone non si � mai mosso (Controgliamo se c'� una pedina nemica nella posizione di destinazione)
	Position target_pos(pos.get_letter(), pos.get_number() + two);
	if (!moved && board.get_piece(target_pos)->get_type() == 0)
		moves[0].push_back(target_pos);

	//Se il pedone si � gi� mosso
	target_pos.set_position(pos.get_letter(), pos.get_number() + one);
	if (board.is_valid_position(target_pos))
		if (board.get_piece(target_pos)->get_type() == 0)
			moves[0].push_back(target_pos);
}

void Pawn::cross_left(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//In base al colore della pedina, il pedone si muove verso sud-ovest (Nera) o verso nord-ovest (Bianca)
		//Default Nera
	int y { 1 };
	//Bianca
	if (team) y = -1;
	
	//Controllo se la posizione sia valida
	Position target_pos(pos.get_letter() - 1, pos.get_number() + y);
	if (board.is_valid_position(target_pos))
	{
		Piece* target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
}

void Pawn::cross_right(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//In base al colore della pedina, il pedone si muove verso sud-ovest (Nera) o verso nord-ovest (Bianca)
		//Default Nera
	int y{ 1 };
	//Bianca
	if (team) y = -1;
	
	//Controllo se la posizione sia valida
	Position target_pos(pos.get_letter() + 1, pos.get_number() + y);
	if (board.is_valid_position(target_pos))
	{
		Piece* target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
}