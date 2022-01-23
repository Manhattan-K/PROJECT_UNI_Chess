/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: ROOK.H
	Classe figlia di Piece.h.
	Realizza la figura della Torre { int Type = 6 } negli scacchi.
	La torre si muove nelle direzioni "cardinali" alla sua posizione, cio� in linea retta a N, W, E e S {*vedi Piece.h per capire le lettere}

__>VARIABILI DI CLASSE
	- bool moved:		Variabile che ci dice se la torre si � mai mossa durante la partita o deve ancora 
						farlo, e quindi si trova ancora nell'angolo iniziale [Utile per arrocco]

__>FUNZIONI
	- has_moved:		Ci dice se la pedina si � mai mossa [true --> mossa]
															[false --> mai mossa]

*/

#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece
{
	private:
		//=---------------------------------------------=Variabili=---------------------------------------------=
		bool moved{};

			//Overload delle funzioni di movimento necessarie
		void up(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void right(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void down(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
		void left(Chessboard& board, std::vector<std::vector<Position>>& moves) override;
			//Overload di check_piece()
		void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves);
			//Blocco delle funzioni a cui non facciamo l'override perché non necessario
		void up_left(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void up_right(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void down_left(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void down_right(Chessboard& board, std::vector<std::vector<Position>>& moves) {}
		void circle(Chessboard& board, std::vector<std::vector<Position>>& moves) {}

	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		Rook() : Piece{}, moved{ false } {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		Rook(Position& p, bool team) : Piece{ p, 6, team }, moved{ false } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		Rook(const Rook& arg);
		Rook& operator=(const Rook& arg);
		//Costruttore e assegnamento di spostamento
		Rook(Rook&& arg);
		Rook& operator=(Rook&& arg);

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Rook() {}

		//=---------------------------------------------=Funzioni di Rook=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(Chessboard& board);
		bool can_move(Chessboard& board);
		
			//Funzione get della variabile moved
		bool has_moved() { return moved; }
};

#endif