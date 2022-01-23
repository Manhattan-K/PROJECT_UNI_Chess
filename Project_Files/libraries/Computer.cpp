/*  Lorenzo Leone 2000160  */

#include "Computer.h"
#include "Chessboard.h"
#include <time.h>

//--------------------------------------------------------| Costruttori e distruttore |--------------------------------------------------------
// | Costruttore di Default|
Computer::Computer() 
{
	team = false;
	std::srand(time(NULL));
}

// | Costruttore |
Computer::Computer(bool flag)
{
	team = flag;
	std::srand(time(NULL));
}


// | Costruttore e assegnamento di Copia |
Computer::Computer(const Computer& pc)
{
	team = pc.team;
}
Computer& Computer::operator=(const Computer& pc)
{
	team = pc.team;
	return *this;
}

// | Costruttore e assegnamento di Spostamento |
Computer::Computer(Computer&& pc)
{
	team = pc.team;
}
Computer& Computer::operator=(Computer&& pc)
{
	team = pc.team;
	return *this;
}

// | Distruttore |
Computer::~Computer(){}


//--------------------------------------------------------| Funzioni |--------------------------------------------------------
/*
	exe_move:
		è la funzione che permette l'accesso a rand_piece e rand_move (entrambe 
		funzioni private della classe).
		da rand_piece recupera la pedina scelta casualmente estraendone la posizione 
		attuale (init_pos), mentre da rand_move recupera la mossa che la pedina deve eseguire
		(fin_pos).

		restitusce un vector<Position> in cui son contenute init_pos e fin_pos.
*/
std::vector<Position> Computer::exe_move(Chessboard& cb)
{
	Chessboard board = cb;
	Position init_pos = {};
	Position fin_pos = {};
	int moves0_size = 0;
	int moves1_size = 0;
	Piece* r_piece {};
	std::vector<std::vector<Position>> m_piece {};
	
	std::vector<Piece*> pieces {};
	if(team)
	{
		pieces = board.get_liveWhite();
	}
	else
	{
		pieces = board.get_liveBlack();
	}

	while(moves0_size == 0 && moves1_size == 0)
	{
		r_piece = rand_piece(pieces);
		std::cout << "TIPO: " << r_piece->get_type() << '\n';
		m_piece = r_piece->get_moves(board);
		moves0_size = m_piece[0].size();
		moves1_size = m_piece[1].size();
		std::cout << moves0_size << moves1_size << '\n';
	}
	std::cout << moves0_size << moves1_size << '\n';

	init_pos = r_piece->get_position();
	fin_pos = rand_move(m_piece, board);
	std::cout << "\n\t-><- fuori -><-\n";

	std::vector<Position> move = {init_pos, fin_pos};
	
	while(true){}
	
	return move;
}

/*
	rand_piece:
		sfruttando la variabile privata pieces, genero un numero casuale
		che andrà ad indicare la pedina che il computer muoverà restituendola.
*/
Piece* Computer::rand_piece(std::vector<Piece*>& pieces)
{
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
Position Computer::rand_move(std::vector<std::vector<Position>>& moves, Chessboard& cb)
{
	Chessboard board = cb;
	int rn = 0;

	rn = rand() % 2;
	std::vector<Position> n {};
	if(moves[rn].size() != 0)
	{
		n = moves[rn];
	}
	else
	{
		int i = 1;
		if(rn == 1) i = 0;
		n = moves[i];
	}
	std::cout << "\tqua " <<n.size();
	while(true){}

	rn = rand() % n.size();
	
	return n[rn];
}