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

	//distruttore
	~Chessboard();//finire

	void shift(Position start, Position end);
	void eatWhite(Piece& x);
	void eatBlack(Piece& x);
	Piece* get_piece(const Position& pos);
	std::vector<Piece*> get_liveWhite();
	std::vector<Piece*> get_liveBlack();
	int checkRules();//finire  

	//funzione che restituisce true se la posizione si trova all'interno della scacchiera, false altrimenti
	bool is_valid_position(Position& pos);
};

#endif