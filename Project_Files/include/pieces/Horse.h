/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: HORSE.H
	Classe figlia di Piece.h.
	Realizza la figura del Cavallo { int Type = 5 } negli scacchi.
	Il cavallo è l'unica pedina che può "scavalcare" le altre pedine del gioco perché i suoi movimenti sono caratterizzati
	da "salti" a una distanza prefissata dalla posizione iniziale: il cavallo si sposta di 2 posizioni in una direzione e di una posizione nella 
	direzione perpendicolare dalla posizione raggiunta dai primi due movimenti, formando una L

		  1  2  3  4  5
		 [ ][x][ ][x][ ]			Esempio:	Il cavallo si trova nella posizione C e si può muovere 
		 [x][ ][ ][ ][x]						nelle direzioni contrassegnate da una x 
		 [ ][ ][C][ ][ ]
		 [x][ ][ ][ ][x]
		 [ ][x][ ][x][ ]

__>FUNZIONI
	- jump:			Controlla le posizioni in cui il cavallo potrebbe "saltare" e ci dice se sono posizioni libere e con pedine mangiabili o meno
*/

#ifndef HORSE_H
#define HORSE_H

#include "Piece.h"

class Horse : public Piece
{
	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		Horse() : Piece{} {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		Horse(Position& p, bool team) : Piece{ p, 5, team } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		Horse(const Horse& arg);
		Horse& operator=(const Horse& arg);
			//Costruttore e assegnamento di spostamento
		Horse(Horse&& arg);
		Horse& operator=(Horse&& arg);

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Horse() {}

		//=---------------------------------------------=Funzioni di Horse=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(const Chessboard& board);

	private:
			//Funzione per il movimento {Descrizione funzioni all'allinizio del file}
		void jump(Chessboard& board, std::vector<std::vector<Position>>& moves);
			//Overload di check_piece()
		void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves);
};

#endif