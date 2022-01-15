/*  Lorenzo Leone 2000160 */

#include "Computer.h"
#include "Chessboard.h"

//------------------------------------------------| Costruttori e Distruttore |------------------------------------------------
// | Costruttore di Default|
Computer::Computer() 
{
	team = false;
	pieces = {};
}

// | Costruttore |
Computer::Computer(bool flag, const Chessboard& cb)
{
	side_acquisition(flag, cb);
}


// | Costruttore e assegnamento di Copia |
Computer::Computer(const Computer& pc)
{
	team = pc.team;
	int dim = pc.pieces.size();
	std::copy(pc.pieces.begin(), pc.pieces.end(), pieces.begin());
}
Computer& Computer::operator=(const Computer& pc)
{
	team = pc.team;
	int dim = pc.pieces.size();
	std::copy(pc.pieces.begin(), pc.pieces.end(), pieces.begin());
	return *this;
}

// | Costruttore e assegnamento di Spostamento |
Computer::Computer(Computer&& pc)
{
	team = pc.team;
	std::copy(pc.pieces.begin(), pc.pieces.end(), pieces.begin());
	pc.pieces = {};
}
Computer& Computer::operator=(Computer&& pc)
{
	team = pc.team;
	std::copy(pc.pieces.begin(), pc.pieces.end(), pieces.begin());
	pc.pieces = {};
	return *this;
}


// | Distruttore |
Computer::~Computer()
{
	//da finire.
}

//--------------------------------------------------------| Funzioni |--------------------------------------------------------
/*
	rand_piece:
		sfruttando la variabile privata pieces, genero un numero casuale
		che andrà ad indicare la pedina che il computer muoverà restituendola.
*/
Piece* Computer::rand_piece()
{
	//std::srand(time(NULL));
	int rn = rand() % pieces.size();
	return pieces[rn];
}

/*
	rand_move:
		la funzione ha come parametri la pedina da muovere e la Chessboard su cui
		la partita viene giocata.

		presi questi due valori, ricavo dalla pedina scelta le mosse possibili, per poi 
		scegliere casualmente una tra queste e restituirla.
*/
Position Computer::rand_move(Piece* piece, const Chessboard& cb)
{
	//std::srand(time(NULL));
	Chessboard board = cb;

	std::vector<std::vector<Position>> m = piece->get_moves(board);
	int rn = rand() % m.size();

	std::vector<Position> n = m[rn];
	rn = rand() % n.size();

	return n[rn];
}

/*
	exe_move:
		è la funzione che permette l'accesso a rand_piece e rand_move (entrambe 
		funzioni private della classe).
		da rand_piece recupera la pedina scelta casualmente estraendone la posizione 
		attuale (init_pos), mentre da rand_move recupera la mossa che la pedina deve eseguire
		(fin_pos).

		restitusce un vector<Position> in cui son contenute init_pos e fin_pos.
*/
std::vector<Position> Computer::exe_move(const Chessboard& cb)
{
	Chessboard board = cb;
	Piece* r_piece = rand_piece();

	Position init_pos = r_piece->get_position();
	Position fin_pos = rand_move(r_piece, board);
	std::vector<Position> move = {init_pos, fin_pos};

	return move;
}

/*
	side_aquisition:
		funzione creata per l'assegnamento di un lato (side) della scacchiera
		ed il corrispettivo set di pedine al nostro player computer.

		in questo blocco sfrutto le funzioni get_liveWhite() e get_liveBlack()
		appartenenti alla classe Chessboard per ottenere rispettivamente 
		le pedina bianche e nere ancora utilizzabili e copiarle nel 
		vector<Pieces*> pieces (variabile privata della classe Computer).
*/
void Computer::side_acquisition(bool flag, const Chessboard& cb)
{
	Chessboard board = cb;
	team = flag;

	std::vector<Piece*> whites = board.get_liveWhite();
	std::vector<Piece*> blacks = board.get_liveBlack();
	if (team == true)
	{
		std::copy(whites.begin(), whites.end(), pieces.begin());
	}
	else
	{
		std::copy(blacks.begin(), blacks.end(), blacks.begin());
	}
}
