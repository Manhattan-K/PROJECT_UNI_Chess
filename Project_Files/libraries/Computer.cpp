/*  Lorenzo Leone 2000160 */
//*  Nota:Chiedere a Filippo se c'è una funzione per ottenere il vettore dell'intero team.


#include "Computer.h"
#include "Chessboard.h"
// | Costruttore di Default e Team |  
/*
Computer::Computer()
{
	team = false;
	board = nullptr;
	Pieces = {};
}
Computer::Computer(bool flag, Chessboard& cb)
{
	board = cb;
	SideAcquisition(flag, cb);
}

// | Costruttore e assegnamento di Copia |
Computer::Computer(const Computer& pc)
{
	team = pc.team;
	board = pc.board;
	int dim = pc.Pieces.size();
	//std::copy(pc.Pieces, dim, Pieces); -> mi dà un problema con i parametri, devo guardarci sopra
}
Computer& Computer::operator=(const Computer& pc)
{
	team = pc.team;
	board = pc.board;
	int dim = pc.Pieces.size();
	//std::copy (pc.Pieces, dim, Pieces);
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
Piece* Computer::RandPiece()
{
	std::srand(time(NULL));
	int rn = rand() % Pieces.size();
	return &Pieces[rn];
}

std::vector<Position> Computer::RandMove(Piece* piece, Chessboard& cb)
{
	std::vector<std::vector<Position>> m = piece->get_moves(cb);
	std::srand(time(NULL));
	int rn = rand() % m.size();
	return m[rn];
}

void Computer::ExeMove(Piece* piece, Position move)
{

}

void Computer::SideAcquisition(bool flag, Chessboard& cb)
{

	//Dipende da come sarà il get che mi fornirà Filippo
	//se mi dà un List Condizionato

		team = flag;
		Pieces = board.getList(flag);
	
	//se mi dà due List separate.

		team = flag;
		if (flag == true)
		{
			Pieces = board.getListWhite();
		}
		else
		{
			Pieces = board.getListBlack();
		}

}
*/