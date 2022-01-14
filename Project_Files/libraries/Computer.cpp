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
	int rn = rand() % m.size();

	std::vector<Position> n = m[rn];
	rn = rand() % n.size();

	return n[rn];
}

void Computer::exe_move(Piece* piece, Position move)
{
	rand_piece();
	rand_move(piece, board);
}

void Computer::side_acquisition(bool flag, Chessboard& cb)
{

	//Dipende da come sar� il get che mi fornir� Filippo
	//se mi d� un List Condizionato

		team = flag;
		pieces = board.getList(flag);
	
	//se mi d� due List separate.

		team = flag;
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