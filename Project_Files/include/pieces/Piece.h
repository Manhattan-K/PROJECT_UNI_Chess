/*			ZLATKO KOVACHEV {MATRICOLA: 2003380}

__>CLASSE: PIECE.H
	Classe madre di tutte le pedine disponibili e giocabili nel gioco degli scacchi.
	Ragruppa tutte le caratteristiche di una pedina e le azioni comuni che potrebbero condividere

__>VARIABILI DI CLASSE
	- Position pos:		Variabile Position& che ricorda la posizione della pedina nella scacchiera
						Se la Pos == {8, 8} la pedina non � utilizzabile, � stata mangiata
	
	- bool alive:		Variabile che ci dice se la pedine � viva o morta	[true --> viva]
																			[false --> morta]
	
	- int type:			In base al numero (0,1,2,3,4,5,6) sappiamo il tipo di pedina
							- 0 == Spazio vuoto (Space)
							- 1 == Re (King)
							- 2 == Regina (Queen)
							- 3 == Pedone (Pawn)
							- 4 == Alfiere (Bishop)
							- 5 == Cavallo (Horse)
							- 6 == Torre (Rook)

	- bool team:		In base al vaore booleano sappiamo se la pedina � bianca o nera		[true --> bianca]
																							[false --> nera]

__>FUNZIONI
	
	- vector<vector<Position>> get_moves(const Chessboard& board)
		Funzione che restituisce un vettore di due vettori, contenenti con tutte le posizioni valide in cui la pedina si pu� muovere:
			- 1� Vettore -> vec[0]:	ci sono tutte le posizioni in cui la pedina si pu� liberamente muovere
			- 2� Vettore -> vec[1]:	ci sono tutte le posizioni in cui la pedina pu� effettuare un'azione di mangiare una pedina aversaria
		Necessita dell'oggetto Chessboard su cui avviene la partita e in cui ci sono tutte le posizioni delle pedine
	

	- Esempio di una pedina circondata da posti in cui si pu� muovere ([] <-- spazio di movimento) con acronimi per
	  definire meglio le posizioni attorno alla pedina.
			LEGGENDA:	N = Nord, W = Ovest, E = Est, S = Sud, P = Pedina

						[N-W][ N ][N-E]
						[ W ][ P ][ E ]
						[S-W][ S ][S-E]

		- up:				Controlla tutti gli spazi a NORD della pedina
		- right:			Controlla tutti gli spazi a EST della pedina
		- down:				Controlla tutti gli spazi a SUD della pedina
		- west:				Controlla tutti gli spazi a OVEST della pedina
		- up_left:			Controlla tutti gli spazi a NORD-OVEST della pedina
		- up_right:			Controlla tutti gli spazi a NORD-EST della pedina
		- down_left:		Controlla tutti gli spazi a SUD-OVEST della pedina
		- down_right:		Controlla tutti gli spazi a SUD-EST della pedina
		- circle:			Controlla tutti gli spazi a distanza di 1[] attorno alla pedina P


	- die:						Fa in modo di rendere la pedina ingiocabile, morta
	- get...:					Funzioni get che ritornano il valore della variabili di classe
	- set_piece_position:		Utile per cambiare la posizione della pedina
	
	- is_black:				Ritorna true se la pedina � una pedina nera
	- is_white:				Ritorna true se la pedina � una pedina bianca
	- is_same_team:			Ritorna true se le pedine sono dello stesso colore, false altrimenti

	- check_piece:		Questa funzione esegue il controllo della pedina puntata da Piece* target e in base ai
						vari casi decide se inserire la posizione nel vettore {Vettore di get_moves()} dato.
							[La funzione pu� variare da classe a classe]
*/

#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Position.h"

	/*Dichiarazione della classe Chessboard perch� le funzioni devono ricevere un riferimento a un oggetto di tipo
	Chessboard e dato che la classe non � ancora definita, dichairandola solamente prima non abbiamo problemi di 
	cicli di include*/
class Chessboard;

class Piece
{
	protected:
		//=---------------------------------------------=Variabili=---------------------------------------------=
			//Mantiene traccia della posizione della pedina nella scacchiera
		Position pos{};
			//Mantiene traccia dello stato della pedina (giocabile o non giocabile)
		bool alive{};
			//Mantiene traccia di che tipo � la pedina 
		int type{};
			//Ricorda il colore della pedina [true --> bianca] [false -- > nera]
		bool team{};

		//=---------------------------------------------=Costruttori=---------------------------------------------=
			//Default
		Piece() { pos.set_position(8, 8); }
			//Con parametri [Posizione iniziale, Tipo di pedina, Colore della pedina]
		Piece(Position& p, int t, bool b) : pos{ p }, alive{ true }, type{ t }, team{ b } {}

		//=---------------------------------------------=Funzioni di Piece:private=---------------------------------------------=
			//Funzione di controllo della Pedina
		virtual void check_piece(Piece* target, Position& pos, std::vector<std::vector<Position>>& moves) = 0;

			//Funzioni per il movimento {Descrizione funzioni all'allinizio del file} utilizzabili solo dalle classi figlie
		virtual void up(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void right(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void down(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void left(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void up_left(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void up_right(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void down_left(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void down_right(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;
		virtual void circle(Chessboard& board, std::vector<std::vector<Position>>& moves) = 0;

	public:
		//=---------------------------------------------=Disabilitazione copia=---------------------------------------------=
		Piece(const Piece&) = delete;
		Piece& operator=(const Piece&) = delete;

		//=---------------------------------------------=Funzioni di Piece:public=---------------------------------------------=
			//Funzioni per il movimento {Descrizione funzioni all'allinizio del file}
		virtual std::vector<std::vector<Position>> get_moves(Chessboard& board) = 0;

			//Funzione che rende la pedina ingiocabile
		void die() { pos.set_position(8, 8); alive = false; type = 0; }

			//Funzioni get, per le variabili di classe Piece
		Position get_position() const { return pos; }
		bool is_alive() { return alive; }
		int get_type() { return type; }
		bool get_team() { return team; }

			//Funzione che cambia la posizione della pedina
		void set_piece_position(Position& p) { pos = p; }

			//Funzioni di visualizzazione del colore delle pedine
		bool is_black() { if (!team) { return true; } return false; }
		bool is_white() { if (team) { return true; } return false; }
		bool is_same_team(Piece& p) { if (team == p.get_team()) { return true; } return false; }

		//=---------------------------------------------=Distruttore=---------------------------------------------=
		~Piece() {}
};

#endif