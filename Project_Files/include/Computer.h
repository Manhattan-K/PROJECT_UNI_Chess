/*  Lorenzo Leone 2000160  */


/*
	_ Classe: Computer
		Classe incaricata nella gestione del "player" Computer.
		In sostanza, Computer è un "player" le cui decisioni sono random e generalmente poco intelligenti.


	_ Variabili di Classe:
		- bool Team :					Variabile di classe che indica a quale "colore" (Bianco[->True] o Nero[->False])
										il computer appartiene;

		- Chessboard board:				Riferimento alla scacchiera di gioco;

		- vector<Piece> Pieces			Lista dei pedoni controllati dal computer;


	_ Funzioni:
		- Piece* rand_piece():			Funzione che sceglie una pedina random dalla lista dei pedoni controllati;

		- Position rand_move():			Funzione che dal risultato di __Piece* rand_piece()__ decide una delle mosse
										possibili in maniera random;

		- void exe_move():				Funzione che esegue ciç che è stato determinato in precedenza (Pedone e mossa da eseguire);

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
		//Computer(bool flag);
		Computer(bool flag);

		// | Costruttore e assegnamento di Copia |
		Computer(const Computer& pc);
		Computer& operator=(const Computer& pc);

		// | Costruttore e assegnamento di Spostamento |
		Computer(Computer&& pc);
		Computer& operator=(Computer&& pc);
		
		// | Distruttore |
		~Computer();

		// | Funzioni | 
		std::vector<Position> exe_move(Chessboard& cb);

	private:
		Piece* rand_piece(std::vector<Piece*>& pieces);
		Position rand_move(std::vector<std::vector<Position>>& moves);

		bool team;
};

#endif