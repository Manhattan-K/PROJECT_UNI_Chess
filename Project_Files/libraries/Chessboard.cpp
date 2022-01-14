/*  FILIPPO FRANCESCHETTO  */

#include "Chessboard.h"
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Horse.h"
#include "Bishop.h"
#include "Rook.h"
#include "Space.h"

//costruttore
Chessboard::Chessboard()
{
	/*
	//setto gli spazi con Space() 
	for (int r = 2; r < 5; r++)
		for (int c = 0; c < 8; c++)
		{
			Position box = Position(c, r);
			matrix[c][r] = new Space(box);
		}
	//per ogni posizione nella matrice assegno un tipo di pedina
	for (int c = 0; c < 8; c++)
	{
		Position b = Position(c, 1);
		matrix[c][1] = new Pawn(b, false);
		Position w = Position(c, 6);
		matrix[c][6] = new Pawn(w, true);
		b.set_position(c, 0);
		w.set_position(c, 7);
		if (c == 0 || c == 7)
		{
			matrix[c][0] = new Rook(b, false);
			matrix[c][7] = new Rook(w, true);
		}
		if (c == 1 || c == 6)
		{
			matrix[c][0] = new Horse(b, false);
			matrix[c][7] = new Horse(w, true);
		}
		if (c == 2 || c == 5)
		{
			matrix[c][0] = new Bishop(b, false);
			matrix[c][7] = new Bishop(w, true);
		}
		if (c == 3)
		{
			matrix[c][0] = new Queen(b, false);
			matrix[c][7] = new Queen(w, true);
		}
		if (c == 4)
		{
			matrix[c][0] = new King(b, false);
			matrix[c][7] = new King(w, true);
		}
	}
	for (int c = 0; c < 8; c++)
	{
		liveBlack.push_back(matrix[c][0]);
		liveBlack.push_back(matrix[c][1]);
		liveWhite.push_back(matrix[c][6]);
		liveWhite.push_back(matrix[c][7]);
	}
	*/
}

//distruttore
Chessboard::~Chessboard() {}//finire

//spostamento di una pedina
void Chessboard::shift(Position start, Position end)
{
	int x = start.get_letter();
	int y = start.get_number();
	Piece* box = matrix[x][y];
	matrix[x][y] = 0;
	x = end.get_letter();
	y = end.get_number();
	matrix[x][y] = box;

}

//elimina una pedina dalla lista delle pedine vive sia per bianche che per nere
void Chessboard::eatWhite(Piece& x)
{
	int length = liveWhite.size();
	for (int i = 0; i < length; i++)
	{
		Position t = liveWhite[i]->get_position();
		if(matrix[t.get_letter()][t.get_number()] == &x)
		{
			std::vector<Piece*> temp;
			for (int k = length; k < i; k++)
			{
				Piece* m = liveWhite[i];
				liveWhite.pop_back();
				temp.push_back(m);
			}
			for (int k = i; k < length - 1; k++)
			{
				Piece* m = temp[k];
				temp.pop_back();
				liveWhite.push_back(m);
			}
		}
	}
}
void Chessboard::eatBlack(Piece& x)
{
	int length = liveBlack.size();
	for (int i = 0; i < length; i++)
	{
		Position t =liveBlack[i]->get_position();
		if (matrix[t.get_letter()][t.get_number()] == &x)
		{
			std::vector<Piece*> temp;
			for (int k = i; k < length; k++)
			{
				Piece* m = liveBlack[k];
				liveBlack.pop_back();
				temp.push_back(m);
			}
			for (int k = i; k < length - 1; k++)
			{
				Piece* m = temp[k];
				temp.pop_back();
				liveBlack.push_back(m);
			}
		}
	}
}
//metodi che restituiscono la lista di pedine

std::vector<Piece*> Chessboard::get_liveWhite()
{ return liveWhite; }

std:: vector<Piece*>Chessboard::get_liveBlack()
{ return liveBlack; }

/*
Controlla se la partita è finita
Restituisce: -1 se vincono i neri
			  0 se è patta
			  1 se vincono i bianchi
			  2 se la partita non è finita
*/
int Chessboard::checkRules()
{
	// il re non puo piu fare mosse, stallo (PATTA = 0)
	Chessboard t = Chessboard();
	for(int c = 0; c < 8; c++)
		for(int r = 0; r < 8; r++)
		{
			Position temp = Position(c, r);
			Piece* k =get_piece(temp)
			if(k == new King)
			{
				if(k->is_back())
				{
					std::vector<std::vector<Position>> m = k->get_moves(t);
				}
				else
				{
					std::vector<std::vector<Positon>> m = k->get_moves(t);
				}	
				
			}
		}



	// rimangono poche pedine
	if (liveBlack.size() <= 2 && liveWhite.size() <= 2)
	{
		std::cout << "Partita patta";
		return false;
	}

	// Posizione gia vista

	//50 mosse
	int mosse = 0;
	if (mosse < 50)
		return true;
	else
		return false;
}
//restituisce la pedina nella posizione richiesta
Piece* Chessboard::get_piece(const Position& pos)
{
	Position box = pos;
	int x = box.get_letter();
	int y = box.get_number();
	return matrix[x][y];
}

//funzione che restituisce true se la posizione si trova all'interno della scacchiera, false altrimenti
bool Chessboard::is_valid_position(Position& pos)
{
	if (pos.get_letter() < 0 || pos.get_letter() > 7) return false;
	if (pos.get_number() < 0 || pos.get_number() > 7) return false;
	return true;
}