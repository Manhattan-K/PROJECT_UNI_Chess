/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: SPACE.H
	Classe figlia di Piece.h.
	Realizza la casella vuota { int Type = 0 }.
    Non è una vera e propria pedina ma è utile per la realizzazione di Chessboard.
*/

#ifndef SPACE_H
#define SPACE_H

#include "Piece.h"

class Space : public Piece
{
	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		Space() : Piece{} {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		Space(Position& p) : Piece{ p, 0, false } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		Space(const Space& arg);
		Space& operator=(const Space& arg);
			//Costruttore e assegnamento di spostamento
		Space(Space&& arg);
		Space& operator=(Space&& arg);

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Space() {}

		//=---------------------------------------------=Funzioni di Space=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(const Chessboard& board);

	private:
			//Overload di check_piece()
		void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves) {}
};

#endif