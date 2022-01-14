/*  Lorenzo Leone 2000160  */


/*
	_ Classe: Computer
		Classe incaricata nella gestione del "player" Computer.
		In sostanza, Computer � un "player" le cui decisioni sono random e generalmente poco intelligenti.


	_ Variabili di Classe:
		- bool Team :					Variabile di classe che indica a quale "colore" (Bianco[->True] o Nero[->False])
										il computer appartiene;

		- Chessboard board:				Riferimento alla scacchiera di gioco;

		- vector<Piece> Pieces			Lista dei pedoni controllati dal computer;


	_ Funzioni:
		- Piece* rand_piece():			Funzione che sceglie una pedina random dalla lista dei pedoni controllati;

		- Position rand_move():			Funzione che dal risultato di __Piece* rand_piece()__ decide una delle mosse
										possibili in maniera random;

		- void exe_move():				Funzione che esegue ci� che � stato determinato in precedenza (Pedone e mossa da eseguire);

		- void side_acquisition			Funzione che assegna al mio robot il lato (Black, White) di gioco e le corrispettive pedine;
*/

#ifndef COMPUTER_H
#define COMPUTER_H

#include <vector>
#include "Chessboard.h"

class Computer 
{
	public:

		// | Costruttore di Default e Team |
		Computer();
		//Computer(bool flag, Chessboard& board);

		// | Costruttore e assegnamento di Copia |
		Computer(const Computer& pc);
		Computer& operator=(const Computer& pc);

		// | Costruttore e assegnamento di Spostamento |
		Computer(Computer&& pc);
		Computer& operator=(Computer&& pc);
		
		// | Distruttore |
		~Computer();

		// | Funzioni | 
		void exe_move(Piece* piece, Position move);
		void side_acquisition(bool flag, Chessboard& cb);

	private:
		Piece* rand_piece();
		Position rand_move(Piece* piece, Chessboard& cb);

		bool team;
		Chessboard board;
		std::vector<Piece> pieces;
};

#endif