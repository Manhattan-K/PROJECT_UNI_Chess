/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: BISHOP.CPP
	Classe figlia di Piece.h.
	Realizzazione della classe Bishop.h, cio� della realizzazione delle funzioni la cui definizione � mancante.

*/

#include "Bishop.h"
#include "Chessboard.h"

//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
	//Costruttore e assegnamento di copia
Bishop::Bishop(const Bishop& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
}

Bishop& Bishop::operator=(const Bishop& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	return *this;
}

	//Costruttore e assegnamento di spostamento
Bishop::Bishop(Bishop&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
}

Bishop& Bishop::operator=(Bishop&& arg)
{
	pos = arg.pos;
	alive = arg.alive;
	type = arg.type;
	team = arg.team;
	arg.die();
	return *this;
}



//=---------------------------------------------=Funzioni di Bishop=---------------------------------------------=
	//Overload di get_moves()
std::vector<std::vector<Position>> Bishop::get_moves(Chessboard& board)
{
	//Creazione oggetti
	Chessboard cb = board;
	std::vector<std::vector<Position>> moves{ {}, {}};

	//Chiamata alle varie funzioni
	up_left(cb, moves);
	up_right(cb, moves);
	down_left(cb, moves);
	down_right(cb, moves);
	return moves;
}

	//Overload di can_move()
bool Bishop::can_move(Chessboard& board)
{
	std::vector<std::vector<Position>> moves = get_moves(board);
	if(moves[0].size() == 0 && moves[1].size() == 0)
		return false;
	return true;
}

	//Overload di check_piece()
void Bishop::check_piece(Piece* target, Position& target_pos, std::vector<std::vector<Position>>& moves)
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
void Bishop::up_left(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int x{ 1 };
	int y{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter() - x, pos.get_number() - y);
		
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
			y++;
		}
		else
			done = true;
	} while (!done);	
}

void Bishop::up_right(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int x{ 1 };
	int y{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter() + x, pos.get_number() - y);

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
			y++;
		}
		else done = true;
	} while (!done);
}

void Bishop::down_left(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int x{ 1 };
	int y{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter() - x, pos.get_number() + y);

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
			y++;
		}
		else done = true;
	} while (!done);
}

void Bishop::down_right(Chessboard& board, std::vector<std::vector<Position>>& moves)
{
	//Facciamo un ciclo per controllare tutte le posizioni a nord fino a incontrare un muro o una pedina
	bool done{ false };
	Position target_pos{};
	Piece* target{};
	int x{ 1 };
	int y{ 1 };

	do
	{
		//Controgliamo ad ogni ciclo una posizione pi� a nord del ciclo precedente
		target_pos.set_position(pos.get_letter() + x, pos.get_number() + y);

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
			y++;
		}
		else done = true;
	} while (!done);
}