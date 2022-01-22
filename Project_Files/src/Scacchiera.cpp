/*  Filippo Franceschetto */

#include "Position.h"
#include "Chessboard.h"
#include "Computer.h"
#include "Log.h"
#include "Piece.h"
#include "Space.h"

#include "King.h"
#include "Queen.h"
#include "Pawn.h"
#include "Horse.h"
#include "Bishop.h"
#include "Rook.h"

#include <iostream>

int main()
{
    srand(time(NULL));
    Chessboard gameBoard{};
    std::vector<Chessboard> moveSequences;
    Log file {};
    char role;
    do
    {
        std::cout<<"Inserire il tipo di partita che si desidera svolgere;";
        std::cout<<"Se si sceglie Computer_VS_Computer inserire 'c' \n Se si sceglie Computer_VS_Persona inserire 'p'";
        std::cin>>role;
    } while (role != 'c' && role != 'p');
    if(role == 'p')
    {
        int move = 0;
        Computer black = Computer();
        Computer white = Computer();
        std::vector<Position> b;
        std::vector<Position> w;
        int squad = rand()%2 // se 0 persona bianca altrimenti nera
        do
        {
            moveSequences.push_back(gameBoard);

           std::string white;
           bool condition = false;
           //scelta mossa utente bianco
           do
           {
               std::cout<<"Mossa bianco: ";
               std::cin>>white;   //es: "A3 B4"
               int letterS = white[0] - 97; // A
               int numberS = white[1] - 1;  // 3
               int letterE = white[3] - 97; // B
              int numberE = white[4] - 1;  // 4
              if((numberE < 0 || numberE > 7) || (numberS < 0 || numberS > 7))
                   condition = true;
               else if((letterE < 0 || letterE > 7) || (letterS < 0 || letterS > 7))
                    condition = true;    
               else
                   condition = false;
                Position end = Position(letterE, numberE);
                if(gameBoard.get_piece(end) == new Space()) 
                    condition = false;  
            } while (condition);

            //esecuzione mossa utente bianco
            int letterS = white[0] - 97;
            int numberS = white[1] - 1;
            int letterE = white[3] - 97;
            int numberE = white[4] - 1;
            Position start = Position(letterS, numberS);
            Position end = Position(letterE, numberE);
            if(gameBoard.get_piece(end) == new Space())
                gameBoard.shift(start, end);
            else
            {
                gameBoard.eatBlack(*gameBoard.get_piece(end));
                gameBoard.shift(start, end);
            }
            
            //se la partita è in parità non continua
            if(gameBoard.checkRules(gameBoard) == 2)
            {
                //scelta mossa computer nero
                b = black.exe_move(gameBoard);
                Piece* pieceB = gameBoard.get_piece(b[0]);
                Position moveS = pieceB->get_position();
                Position moveB = b[1];
                Piece* pieceW = gameBoard.get_piece(moveB);

                //esecuzione mossa computer nero
                if(pieceB == new Space())
                    gameBoard.shift(moveS, moveB);
                else
                {
                    gameBoard.eatWhite(*pieceB);
                    gameBoard.shift(moveS, moveB);
                }
            }    
            
            move++;    
        }while(gameBoard.checkRules(gameBoard) == 2);

        if(gameBoard.par(move,gameBoard) == 0 || gameBoard.alreadySeen(moveSequences, gameBoard) == 0)
            std::cout<<"Partita finita in parità";
        else if(gameBoard.checkRules(gameBoard) == -1)
            std::cout<<"Vincono i neri, il computer";
        else if(gameBoard.checkRules(gameBoard) == 1)
            std::cout<<"Vincono i bianchi";
        else    
            std::cout<<"Partita finita in parità";    
    }
    else
    {
        int move = 0;
        Computer white = Computer();
        Computer black = Computer();
        std::vector<Position> w;
        std::vector<Position> b;        
        for(int moves = 0; moves<40 && gameBoard.checkRules(gameBoard) == 2 && gameBoard.par(move, gameBoard) == 2 && gameBoard.alreadySeen(moveSequences, gameBoard) == 2; moves++)
        {   //scelta mossa bianco
            w = white.exe_move(gameBoard);
            Piece* pieceW = gameBoard.get_piece(w[0]);
            Position moveS = pieceW->get_position();
            Position moveW = w[1];
            Piece* pieceB = gameBoard.get_piece(moveW);
            //esecuzione mossa bianco
            if(pieceB == new Space())
                gameBoard.shift(moveS, moveW);
            else
            {
                gameBoard.eatBlack(*pieceB);
                gameBoard.shift(moveS, moveW);
            }

            if(gameBoard.checkRules(gameBoard) != 0 && gameBoard.checkRules(gameBoard) !=1 && gameBoard.alreadySeen(moveSequences, gameBoard) == 2 && gameBoard.par(move, gameBoard) == 2)
            {   //scelta mossa nero
                b = black.exe_move(gameBoard);
                Piece* pieceB = gameBoard.get_piece(b[0]);
                Position moveS = pieceB->get_position();
                Position moveB = b[1];
                Piece* pieceW = gameBoard.get_piece(moveB);
                //esecuzione mossa nero
                if(pieceW == new Space())
                    gameBoard.shift(moveS, moveB);
                else
                {
                    gameBoard.eatWhite(*pieceW);
                    gameBoard.shift(moveS, moveB);
                }
            }
            else if(gameBoard.checkRules(gameBoard) == -1)
                std::cout<<"Vincono i neri, il computer";
            else if(gameBoard.checkRules(gameBoard) == 1)
                std::cout<<"Vincono i bianchi";
            else
                std::cout<<"Partita finita in parità";

            if(gameBoard.par(move, gameBoard) == 0 || gameBoard.alreadySeen(moveSequences, gameBoard) == 0)
                std::cout<<"Partita finita in parità";
            else if(gameBoard.checkRules(gameBoard) == -1)
                std::cout<<"vincono i neri";
            else if(gameBoard.checkRules(gameBoard) == 1)
                std::cout<<"vincono i bianchi";
            else
                std::cout<<"Partita finita in parità";
        }
    }

    std::cout << "\n\t-><- Il programma compila senza errori, uWu -><-\n";
    return 0;
}


// ROBA DI ZLATKO PER VEDERE SE LE MIE FUNZIONI FUNZIONANO
//Bishop b{};
    //std::vector<std::vector<Position>> vec = b.get_moves(c);
    /*
    for(int i = 0; i < vec[0].size(); i++)
    {
        Position pos = vec[0][i];
        std::cout << '\n' << '(' << pos.get_letter() << ',' << pos.get_number() << ')';
    }
    for(int i = 0; i < vec[1].size(); i++)
    {
        Position pos = vec[1][i];
        std::cout << '\n' << '(' << pos.get_letter() << ',' << pos.get_number() << ')';
    }
    */