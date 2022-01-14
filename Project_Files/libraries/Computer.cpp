/*  Lorenzo Leone 2000160 */
//*  Nota:Chiedere a Filippo se c'� una funzione per ottenere il vettore dell'intero team.


#include "Computer.h"
#include "Chessboard.h"
// | Costruttore di Default e Team |  
/*
Computer::Computer() 
{
	team = false;
	pieces = {};
}

Computer::Computer()
{
	side_acquisition(flag, cb);
	//creare un costruttore indipendente dalla Chessboard, come faccio a rendere computer consapevole dei cambiamenti in chessboard?
}
//creare costruttore indipendente dalla chessboard, come?


// | Costruttore e assegnamento di Copia |
Computer::Computer(const Computer& pc)
{
	team = pc.team;
	board = pc.board;
	int dim = pc.pieces.size();
	//std::copy(pc.pieces, dim, pieces); -> mi d� un problema con i parametri, devo guardarci sopra
}
Computer& Computer::operator=(const Computer& pc)
{
	team = pc.team;
	board = pc.board;
	int dim = pc.pieces.size();
	//std::copy (pc.pieces, dim, pieces);
	return *this;
}

// | Costruttore e assegnamento di Spostamento |
Computer::Computer(Computer&& pc)
{

}
Computer& Computer::operator=(Computer&& pc)
{

}


// | Distruttore |
Computer::~Computer()
{

}

// | Funzioni | 
Piece* Computer::rand_piece()
{
	std::srand(time(NULL));
	int rn = rand() % pieces.size();
	return &pieces[rn];
}

Position Computer::rand_move(Piece* piece, Chessboard& cb)
{
	board = cb;
	std::vector<std::vector<Position>> m = piece->get_moves(board);
	std::srand(time(NULL));
	std::vector<std::vector<Position>> m = piece->get_moves(cb);
	int rn = rand() % m.size();

	std::vector<Position> n = m[rn];
	rn = rand() % n.size();

	return n[rn];
}

void Computer::exe_move()
{
	Piece* r_piece = rand_piece();
	Position r_move = rand_move(r_piece, board);
	//trovare un modo per restituire i due valori
}


void Computer::side_acquisition(bool flag, Chessboard& cb)
{
	board = cb;
	team = flag;
	//Dipende da come sar� il get che mi fornir� Filippo
	//se mi d� un List Condizionato
	pieces = board.getList(flag);
	
	//se mi d� due List separate.

		
		if (flag == true)
		{
			pieces = board.getListWhite();
		}
		else
		{
			pieces = board.getListBlack();
		}

}
*/