/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: ROOK.CPP
	Classe figlia di Piece.h.
	Realizzazione della classe Rook.h, cio� della realizzazione delle funzioni la cui definizione � mancante.

*/

#include "Rook.h"
#include "Chessboard.h"

//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
	//Costruttore e assegnamento di copia
Rook::Rook(const Rook& arg)
	: moved{ arg.moved }
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
}

Rook& Rook::operator=(const Rook& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	moved = arg.moved;
	return *this;
}

	//Costruttore e assegnamento di spostamento
Rook::Rook(Rook&& arg)
	: moved{ arg.moved }
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;

	arg.die();
	arg.moved = false;
}

Rook& Rook::operator=(Rook&& arg)
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


//=---------------------------------------------=Funzioni di Rook=---------------------------------------------=
	//Overload di get_moves()
std::vector<std::vector<Position>> Rook::get_moves(Chessboard& board)
{
	//Creazione oggetti
	Chessboard cb = board;
	std::vector<std::vector<Position>> moves{ {}, {}};

	//Chiamata alle varie funzioni
	up(cb, moves);
	right(cb, moves);
	down(cb, moves);
	left(cb, moves);
	return moves;
}

//Overload di check_piece()
void Rook::check_piece(Piece* target, Position& target_pos, std::vector<std::vector<Position>>& moves)
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

	//Overload delle funzioni di movimento necessarie
void Rook::up(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int y{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter(), pos.get_number() - y);

		//Primo controllo se la posizione � valida
		if (board.is_valid_position(target_pos))
		{
			//Secondo controllo sul tipo di pedina presente nella posizione
			target = board.get_piece(target_pos);
			if (target->get_type() == 0 || target->get_team() != team)
			{
				Piece* target = board.get_piece(target_pos);
				check_piece(target, target_pos, moves);
				if(target->get_team() != team && target->get_type() != 0)
					done = true;
			}
			else done = true;
			y++;
		}
		else done = true;
	} while (!done);
}

void Rook::right(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int x{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter() + x, pos.get_number());

		//Primo controllo se la posizione � valida
		if (board.is_valid_position(target_pos))
		{
			//Secondo controllo sul tipo di pedina presente nella posizione
			target = board.get_piece(target_pos);
			if (target->get_type() == 0 || target->get_team() != team)
			{
				Piece* target = board.get_piece(target_pos);
				check_piece(target, target_pos, moves);
				if(target->get_team() != team && target->get_type() != 0)
					done = true;
			}
			else done = true;
			x++;
		}
		else done = true;
	} while (!done);
}

void Rook::down(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int y{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter(), pos.get_number() + y);

		//Primo controllo se la posizione � valida
		if (board.is_valid_position(target_pos))
		{
			//Secondo controllo sul tipo di pedina presente nella posizione
			target = board.get_piece(target_pos);
			if (target->get_type() == 0 || target->get_team() != team)
			{
				Piece* target = board.get_piece(target_pos);
				check_piece(target, target_pos, moves);
				if(target->get_team() != team && target->get_type() != 0)
					done = true;
			}
			else done = true;
			y++;
		}
		else done = true;
	} while (!done);
}

void Rook::left(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int x{ 1 };
	
	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter() - x, pos.get_number());

		//Primo controllo se la posizione � valida
		if (board.is_valid_position(target_pos))
		{
			//Secondo controllo sul tipo di pedina presente nella posizione
			target = board.get_piece(target_pos);
			if (target->get_type() == 0 || target->get_team() != team)
			{
				Piece* target = board.get_piece(target_pos);
				check_piece(target, target_pos, moves);
				if(target->get_team() != team && target->get_type() != 0)
					done = true;
			}
			else done = true;
			x++;
		}
		else done = true;
	} while (!done);
}