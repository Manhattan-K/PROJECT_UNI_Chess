/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: HORSE.CPP
	Classe figlia di Piece.h.
	Realizzazione della classe Horse.h, cio� della realizzazione delle funzioni la cui definizione � mancante.

*/

#include "Horse.h"
#include "Chessboard.h"

//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
	//Costruttore e assegnamento di copia
Horse::Horse(const Horse& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
}

Horse& Horse::operator=(const Horse& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	return *this;
}

	//Costruttore e assegnamento di spostamento
Horse::Horse(Horse&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
}

Horse& Horse::operator=(Horse&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
	return *this;
}


//=---------------------------------------------=Funzioni di Horse=---------------------------------------------=
	//Overload di get_moves()
std::vector<std::vector<Position>> Horse::get_moves(Chessboard& board)
{
	//Creazione oggetti
	Chessboard cb = board;
	std::vector<std::vector<Position>> moves{ {}, {}};

	//Chiamata alle varie funzioni
	jump(cb, moves);
	return moves;
}

//Overload di check_piece()
void Horse::check_piece(Piece* target, Position& target_pos, std::vector<std::vector<Position>>& moves)
{
	//Se la pedina � spazio vuoto inserisci la posizione nel primo vettore
	if (target->get_type() == 0)
	{
		moves[0].push_back(target_pos);
		return;
	}

	//Se nella posizione c'� una pedina del team nemico, inserisci la posizione nel secondo vettore
	else
		if (target->get_team() != team)
			moves[1].push_back(target_pos);
}

	//Funzione per il movimento
void Horse::jump(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//{Numero delle colonne all'allinizio del file Horse.h}
	Position target_pos{};
	Piece* target{};

	//Controllo posizioni colonna 1
	int x{ -2 };
	target_pos.set_position(pos.get_letter() + x, pos.get_number() + 1);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
	target_pos.set_position(pos.get_letter() + x, pos.get_number() - 1);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}

	//Controllo posizioni colonna 2
	x = -1;
	target_pos.set_position(pos.get_letter() + x, pos.get_number() + 2);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
	target_pos.set_position(pos.get_letter() + x, pos.get_number() - 2);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}

	//Controllo posizioni colonna 4
	x = 1;
	target_pos.set_position(pos.get_letter() + x, pos.get_number() + 2);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
	target_pos.set_position(pos.get_letter() + x, pos.get_number() - 2);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}

	//Controllo posizioni colonna 5
	x = 2;
	target_pos.set_position(pos.get_letter() + x, pos.get_number() + 1);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
	target_pos.set_position(pos.get_letter() + x, pos.get_number() - 1);
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
}