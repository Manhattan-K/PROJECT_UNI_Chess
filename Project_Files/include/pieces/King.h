/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: KING.H
	Classe figlia di Piece.h.
	Realizza la figura del Re { int Type = 1 } negli scacchi, esso � il pezzo pi� debole ma pi� importante degli scacchi, perch� morto il re, finita la partita.
	Il Re si pu� muovere solamente di una casell aintorno a se e la cattura ha lo stesso principio.

*/

#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece
{
	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		King() : Piece{} {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		King(Position& p, bool team) : Piece{ p, 1, team } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		King(const King& arg);
		King& operator=(const King& arg);
			//Costruttore e assegnamento di spostamento
		King(King&& arg);
		King& operator=(King&& arg);

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~King() {}

		//=---------------------------------------------=Funzioni di King=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(Chessboard& board);
		bool can_move(Chessboard& board);

	private:
			//Overload di circle()
		void circle(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
			//Overload di check_piece()
		void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves);
			//Blocco delle funzioni a cui non facciamo l'override perché non necessario
		void up(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void right(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void down(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void left(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void up_left(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void up_right(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void down_left(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void down_right(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
};

#endif