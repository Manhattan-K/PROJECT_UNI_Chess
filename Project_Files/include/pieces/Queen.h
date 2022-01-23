/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: QUEEN.H
	Classe figlia di Piece.h.
	Realizza la figura della Regina { int Type = 2 } negli scacchi, esso � il pezzo pi� potente degli scacchi:
	la Regina si pu� muovere in tutte le direzioni in linea retta da essa.

*/

#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece
{
	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		Queen() : Piece{} {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		Queen(Position& p, bool team) : Piece{ p, 2, team } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		Queen(const Queen& arg);
		Queen& operator=(const Queen& arg);
			//Costruttore e assegnamento di spostamento
		Queen(Queen&& arg);
		Queen& operator=(Queen&& arg);

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Queen() {}

		//=---------------------------------------------=Funzioni di Queen=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(Chessboard& board);

	private:
			//Overload delle funzioni di movimento necessarie
		void up(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void right(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void down(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void left(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void up_left(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void up_right(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void down_left(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void down_right(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
			//Overload di check_piece()
		void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves);
			//Blocco delle funzioni a cui non facciamo l'override perché non necessario
		void circle(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
};

#endif