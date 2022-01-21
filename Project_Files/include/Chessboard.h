/*  FILIPPO FRANCESCHETTO  */

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include <vector>

#include "Position.h"
#include "pieces/Piece.h"

class Chessboard
{
private:
	Piece* matrix[8][8] {0};
	std::vector<Piece*> liveWhite = {};
	std::vector<Piece*> liveBlack = {};

public:
	//costruttore
	Chessboard();

	//operandi di stampa
	std::ostream& operator<<(std::ostream& os);
	bool operator==(Chessboard & first);

	//costruttore e assegnamento di spostamnto
	Chessboard(const Chessboard& gameBoard);
	Chessboard& operator=(const Chessboard& gameBoard);

	//distruttore
	~Chessboard();//finire

	void shift(Position start, Position end);
	void eatWhite(Piece& x);
	void eatBlack(Piece& x);
	Piece* get_piece(const Position& pos);
	std::vector<Piece*> get_liveWhite();
	std::vector<Piece*> get_liveBlack();
	bool canMove(bool colour, Chessboard gameBoard);
	int checkRules(Chessboard gameBoard);
	int alreadySeen(std::vector<Chessboard> moveSequences, Chessboard gameBoard);
	int par(int move, Chessboard gameBoard); 

	//funzione che restituisce true se la posizione si trova all'interno della scacchiera, false altrimenti
	bool is_valid_position(Position& pos);
};

#endif