/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: BISHOP.H
	Classe figlia di Piece.h.
	Realizza la figura dell'Alfiere { int Type = 4 } negli scacchi.
	L'Alfiere si pu� muovere solo sulle diagonali del colore della casella su cui � posizionato.

*/

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece
{
	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		Bishop() : Piece{} {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		Bishop(Position& p, bool team) : Piece{ p, 4, team } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		Bishop(const Bishop& arg);
		Bishop& operator=(const Bishop& arg);
			//Costruttore e assegnamento di spostamento
		Bishop(Bishop&& arg);
		Bishop& operator=(Bishop&& arg);

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Bishop() {}

		//=---------------------------------------------=Funzioni di Bishop=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(Chessboard& board);
		bool can_move(Chessboard& board);
			
	private:
			//Overload delle funzioni di movimento necessarie
		void up_left(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void up_right(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void down_left(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void down_right(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
			//Overload di check_piece()
		void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves);
			//Blocco delle funzioni a cui non facciamo l'override perché non necessario
		void up(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void right(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void down(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void left(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void circle(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
};

#endif