/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: PAWN.H
	Classe figlia di Piece.h.
	Realizza la figura del Pedone { int Type = 3 } negli scacchi, esso si pu� muovere solo di 1 posizione in avanti (2 se non si � mai mosso durante la partita) e pu� "mangiare" le pedine che si trovano nelle posizioni
	N-E e N-W a distanza di 1 dalla pedina

__>VARIABILI DI CLASSE
	- bool moved:		Variabile che ci dice se il pedone si � mai mosso durante la partita o deve ancora farlo

__>FUNZIONI
	- ahead:			Controlla le posizioni che si trovano davanti a se
	- cross_left:		Controlla la posizione che si trova a N-W
	- cross_right:		Controlla la posizione che si trova a N-E
	- has_moved:		Ci dice se la pedina si � mai mossa [true --> mossa]
															[false --> mai mossa]

*/

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece
{
	private:
		//=---------------------------------------------=Variabili=---------------------------------------------=
		bool moved = false;

			//Funzioni per il movimento {Descrizione funzioni all'allinizio del file}
		void ahead(Chessboard& board, std::vector<std::vector<Position>>& moves);
		void cross_left(Chessboard& board, std::vector<std::vector<Position>>& moves);
		void cross_right(Chessboard& board, std::vector<std::vector<Position>>& moves);
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
		void circle(Chessboard& board, std::vector<std::vector<Position>>& moves) {}

	public:
		//=---------------------------------------------=Costruttore=---------------------------------------------=
			//Default
		Pawn() : Piece{}, moved { false } {}
			//Con parametri [Posizione iniziale, Colore della pedina {*vedi Piece.h}]
		Pawn(Position& p, bool team) : Piece{ p, 3, team }, moved{ false } {}

		//=---------------------------------------------=Copia e spostamento=---------------------------------------------=
			//Costruttore e assegnamento di copia
		Pawn(const Pawn& arg);
		Pawn& operator=(const Pawn& arg);
			//Costruttore e assegnamento di spostamento
		Pawn(Pawn&& arg);
		Pawn& operator=(Pawn&& arg);
			
		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Pawn() {}

		//=---------------------------------------------=Funzioni di Pawn=---------------------------------------------=
			//Overload di get_moves()
		std::vector<std::vector<Position>> get_moves(Chessboard& board);
		bool can_move(Chessboard& board);
			//Funzione get della variabile moved
		bool has_moved() { return moved; }		
};

#endif