/*  FILIPPO FRANCESCHETTO  */
/*
Chessboard definisce la scacchiera e tiene traccia di tutte le posizione delle varie pedine.
Inoltre implementa le regole per la fine della partita

		 shift(Position start, Position end);		EFFETTUA IL MOVIMENTO DELLA PEDINA
		  
		 eatWhite(Piece& x);		EFFETTUA LA MANGIATA DA PARTE DI UNA PEDINA NERA

		 eatBlack(Piece& x);		EFFETTUA LA MANGIATA DA PARTE DI UNA PEDINA BIANCA

		 get_piece(const Position& pos);	RESTITUISCE LA PEDINA CHE SI TROVA IN UNA DETERMINATA POSIZIONE

		 get_liveWhite();	RESTITUISCE UN VETTORE DI POSIZIONI DOVE SI TROVANO LE PEDINE BIANCHE

		 get_liveBlack();	RESTITUISCE UN VETTORE DI POSIZIONI DOVE SI TROVANO LE PEDINE NERE

		 canMove(bool colour);	RESTITUISCE SE UNA SQUADRA PUO' MUOVERE UNA PEDINA
	
	FUNZIONI CHE DETERMINANO LA FINE DELLA PARTITA
		 checkRules(Chessboard gameBoard);   	

		 alreadySeen(std::vector<Chessboard> moveSequences, Chessboard gameBoard); CONTROLLA SE LA POSIZIONE CORRENTE 
		 																		   E' GIA STATA VISTA 2 VOLTE
		 par(int move, Chessboard gameBoard);		CONTROLLA SE UNO DEI 2 SFIDANTI NON HA MOSSO NESSUN 
		 											PEDONE E NON PUO FARE ALTRE MOSSE
*/

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
	
	//setto gli spazi con Space() 
	for (int r = 2; r < 5; r++)
		for (int c = 0; c < 8; c++)
		{
			Position box = Position(c, r);
			matrix[r][c] = new Space(box);
		}
	//per ogni posizione nella matrice assegno un tipo di pedina
	for (int c = 0; c < 8; c++)
	{
		Position b = Position(c, 1);
		matrix[1][c] = new Pawn(b, false);
		Position w = Position(c, 6);
		matrix[6][c] = new Pawn(w, true);
		b.set_position(c, 0);
		w.set_position(c, 7);
		if (c == 0 || c == 7)
		{
			matrix[0][c] = new Rook(b, false);
			matrix[7][c] = new Rook(w, true);
		}
		if (c == 1 || c == 6)
		{
			matrix[0][c] = new Horse(b, false);
			matrix[7][c] = new Horse(w, true);
		}
		if (c == 2 || c == 5)
		{
			matrix[c][0] = new Bishop(b, false);
			matrix[c][7] = new Bishop(w, true);
		}
		if (c == 3)
		{
			matrix[0][c] = new Queen(b, false);
			matrix[7][c] = new Queen(w, true);
		}
		if (c == 4)
		{
			matrix[0][c] = new King(b, false);
			matrix[7][c] = new King(w, true);
		}
	}
	for (int c = 0; c < 8; c++)
	{
		liveBlack.push_back(matrix[0][c]);
		liveBlack.push_back(matrix[1][c]);
		liveWhite.push_back(matrix[6][c]);
		liveWhite.push_back(matrix[7][c]);
	}
}


std::string Chessboard::to_string()
{
	std::string line {};
	char row_c {};

	for(int r = 0; r < 8; r++)
	{
		row_c = 8 - r;
		line += row_c + ' ';
		for(int c = 0; c < 8; c++)
		{
				//Spazio vuoto
			if(matrix[r][c]->get_type() == 0)
				line += ' ';
				//Re
			else if(matrix[r][c]->get_type() == 1)
			{
				if(matrix[r][c]->get_team())
					line += 'r';
				else line += 'R';
			}
				//Regina
			else if(matrix[r][c]->get_type() == 2)
			{
				if(matrix[r][c]->get_team())
					line += 'd';
				else line += 'D';
			}
				//Pedone
			else if(matrix[r][c]->get_type() == 3)
			{
				if(matrix[r][c]->get_team())
					line += 'p';
				else line += 'P';
			}
				//Alfiere
			else if(matrix[r][c]->get_type() == 4)
			{
				if(matrix[r][c]->get_team())
					line += 'a';
				else line += 'A';
			}
				//Cavallo
			else if(matrix[r][c]->get_type() == 5)
			{
				if(matrix[r][c]->get_team())
					line += 'c';
				else line += 'C';
			}
				//Torre
			else if(matrix[r][c]->get_type() == 6)
			{
				if(matrix[r][c]->get_team())
					line += 't';
				else line += 'T';
			}	
		}
		line += '\n';
	}
	line += "\n  ABCDEFGH";
	
	return line;
}

bool Chessboard::operator==(Chessboard& first)
{
	for(int r = 0; r < 8; r++)
		for(int c = 0; c < 8; c++)
			if(first.matrix[r][c] != matrix[r][c])
				return false;
	return true;
}

Chessboard::Chessboard(const Chessboard& gameBoard)
{
	liveWhite = gameBoard.liveWhite;
	liveBlack = gameBoard.liveBlack;
	Piece* matrix[8][8];
	for(int r = 0; r < 8; r++)
		for(int c = 0; c < 8; c++)
			matrix[r][c] = gameBoard.matrix[r][c];
}

Chessboard& Chessboard::operator=(const Chessboard& gameBoard)
{
	liveWhite = gameBoard.liveWhite;
	liveBlack = gameBoard.liveBlack;
	Piece* matrix[8][8];
	for(int r = 0; r < 8; r++)
		for(int c = 0; c < 8; c++)
			matrix[r][c] = gameBoard.matrix[r][c];
	return *this;
}

//distruttore
Chessboard::~Chessboard() {}

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

bool Chessboard::canMove(bool colour, Chessboard gameBoard)
{
	for(int r = 0; r < 8; r++)
		for(int c = 0; c < 8; r++)
			if(matrix[r][c]->get_type() != 0)
				if(matrix[r][c]->get_team() == colour)
				{
					std::vector<std::vector<Position>> move = matrix[r][c]->get_moves(gameBoard);
					if(move[0].size() != 0 || move[1].size() != 1)
						return true;
				}
	return false;
}

/*
Controlla se la partita è finita
Restituisce: -1 se vincono i neri
			  0 se è patta
			  1 se vincono i bianchi
			  2 se la partita non è finita
*/
int Chessboard::checkRules(Chessboard gameBoard)
{
	//rimangono poche pedine (PATTA)
	if(liveBlack.size() <= 2 && liveWhite.size() <= 2)
		return 0;
	
	//no mosse legali, re non in scacco(PATTA)
	//per il bianco
	if(!canMove(true, gameBoard))
	{
		for(int r = 0; r < 8; r++)
			for(int c = 0; c < 8; c++)
			{
				Position temp = Position(c, r);
				Piece* k = get_piece(temp);
				if(k == new King() && k->get_type() == true)
				{
					std::vector<std::vector<Position>> move = k->get_moves(gameBoard);
					if(move[0].size() == 0 & move[1].size() == 0)
						return 0;
				}
			}
	}
	//per il nero
	if(!canMove(false, gameBoard))
	{
		for(int r = 0; r < 8; r++)
			for(int c = 0; c < 8; c++)
			{
				Position temp = Position(c, r);
				Piece* k = get_piece(temp);
				if(k == new King() && k->get_type() == false)
				{
					std::vector<std::vector<Position>> move = k->get_moves(gameBoard);
					if(move[0].size() == 0 && move[1].size() == 0)
						return 0;
				}
			}
	}
	//vince nero
	std::vector<std::vector<Position>> tempB;
	std::vector<Position> eatB;
	for(int c = 0; c < 8; c++)
	{	for(int r = 0; r < 8; r++)
		{
			Position k = Position(c, r);
			if(matrix[r][c]->get_type() == 1)
				if(matrix[r][c]->get_team() == true)
				{
					tempB = matrix[r][c]->get_moves(gameBoard);
					if(tempB[0].size() == 0 && tempB[1].size() == 0)
					{
						for(int c = 0; c < 8; c++)
							for(int r = 0; r < 8; r++)
							{
								if(matrix[r][c]->get_team() == false)
								{
									tempB = matrix[r][c]->get_moves(gameBoard);
									std::vector<Position> tB = tempB[0];
									if(tempB[0].size() != 0)
										for(int i = 0; i < tB.size(); i++)
											eatB.push_back(tB[i]);
								}
								if(eatB.size() != 0)
									return -1;
							}
					}
				}
		} 
	}	

	//vince bianco
	std::vector<std::vector<Position>> tempW;
	std::vector<Position> eatW;
	for(int c = 0; c < 8; c++)
	{	for(int r = 0; r < 8; r++)
		{
			Position k = Position(c, r);
			if(matrix[r][c]->get_type() == 1)
				if(matrix[r][c]->get_team() == false)
				{
					tempW = matrix[r][c]->get_moves(gameBoard);
					if(tempW[0].size() == 0 && tempW[1].size() == 0)
					{
						for(int c = 0; c < 8; c++)
							for(int r = 0; r < 8; r++)
							{
								if(matrix[r][c]->get_team() == true)
								{
									tempW = matrix[r][c]->get_moves(gameBoard);
									std::vector<Position> tW = tempW[0];
									if(tW.size() != 0)
										for(int i = 0; i < tW.size(); i++)
											eatW.push_back(tW[i]);
								}
								if(eatW.size() != 0)
									return 1;
							}
					}
				}
		} 
	}

	return 2;
}

//Posizione già vista 2 volte
int Chessboard::alreadySeen(std::vector<Chessboard> moveSequences, Chessboard gameBoard)
{
	int seen = 0;
	int dim = moveSequences.size();
	for(int i = 0; i < dim; i++)
		if(moveSequences[i] == gameBoard)
			seen++;
	if(seen == 2)
		return 0;
	else
		return 2;
}

// 50 mosse gia fatte senza mangiare e muovere pedoni
int Chessboard::par(int move, Chessboard gameBoard)
{
	if(move == 50)
	{
		//per il bianco
		int count = 0;
		for(int c = 0; c < 8; c++)
		{
			Position w = Position(c, 1);
			if(matrix[1][c] != new Pawn(w, false))
				count++;
		}
		std::vector<Piece*> liveW = get_liveWhite();
		if(liveW.size() == 16 && count == 0)
			return 0;

		//per il nero
		count = 0;
		for(int c = 0; c < 8; c++)
		{
			Position b = Position(c, 6);
			if(matrix[6][c] != new Pawn(b, true))
				count++;
		}
		std::vector<Piece*> liveB = get_liveBlack();
		if(liveB.size() == 16 && count == 0)
			return 0;
	}
	return 2;
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