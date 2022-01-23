/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: KING.CPP
	Classe figlia di Piece.h.
	Realizzazione della classe King.h, cio� della realizzazione delle funzioni la cui definizione � mancante.

*/

#include "King.h"
#include "Chessboard.h"

//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
King::King(const King& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
}

King& King::operator=(const King& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	return *this;
}
	
	//Costruttore e assegnamento di spostamento
King::King(King&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
}

King& King::operator=(King&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
	return *this;
}


//=---------------------------------------------=Funzioni di King=---------------------------------------------=
	//Overload di get_moves()
std::vector<std::vector<Position>> King::get_moves(Chessboard& board)
{
	//Creazione oggetti
	Chessboard cb = board;
	std::vector<std::vector<Position>> moves{ {}, {}};
	
	//Chiamata alle varie funzioni
	circle(cb, moves);
	return moves;
}

	//Overload di can_move()
bool King::can_move(Chessboard& board)
{
	std::vector<std::vector<Position>> moves = get_moves(board);
	if(moves[0].size() == 0 && moves[1].size() == 0)
		return false;
	return true;
}
	
	//Overload di check_piece()
void King::check_piece(Piece* target, Position& target_pos, std::vector<std::vector<Position>>& moves)
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

	//Overload di circle()
void King::circle(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Variabili
	Position target_pos{};
	Piece* target{};
	
	//Ricerca delle 3 posizione a nord
	for (int i = -1; i < 2; ++i)
	{
		//Controllo se la posizione sia valida
		target_pos.set_position(pos.get_letter() + i, pos.get_number() - 1);
		if (board.is_valid_position(target_pos))
		{
			target = board.get_piece(target_pos);
			check_piece(target, target_pos, moves);
		}
	}

	//Ricerca delle 3 posizione a sud
	for (int i = -1; i < 2; ++i)
	{
		//Controllo se la posizione sia valida
		target_pos.set_position(pos.get_letter() + i, pos.get_number() + 1);
		if (board.is_valid_position(target_pos))
		{
			target = board.get_piece(target_pos);
			check_piece(target, target_pos, moves);
		}
	}

	//Ricerca della posizione a ovest
	target_pos.set_position(pos.get_letter() - 1, pos.get_number());
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}

	//Ricerca della posizione a est
	target_pos.set_position(pos.get_letter() + 1, pos.get_number());
	if (board.is_valid_position(target_pos))
	{
		target = board.get_piece(target_pos);
		check_piece(target, target_pos, moves);
	}
}