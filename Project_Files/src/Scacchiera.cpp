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
void print(Chessboard gameBoard, Position start, std::string input)
{
    int type = gameBoard.get_piece(start)->get_type();
    if(type == 1) std::cout<<"Re mosso da "<<input[0]<<input[1]<<" a "<<input[3]<<input[4];
    if(type == 2) std::cout<<"Regina mossa da "<<input[0]<<input[1]<<" a "<<input[3]<<input[4];
    if(type == 3) std::cout<<"Pedone mosso da "<<input[0]<<input[1]<<" a "<<input[3]<<input[4];
    if(type == 4) std::cout<<"Alfiere mosso da "<<input[0]<<input[1]<<" a "<<input[3]<<input[4];
    if(type == 5) std::cout<<"Cavallo mosso da "<<input[0]<<input[1]<<" a "<<input[3]<<input[4];
    if(type == 6) std::cout<<"Torre mosso da "<<input[0]<<input[1]<<" a "<<input[3]<<input[4];
}
int main()
{
    srand(time(NULL));
    Chessboard gameBoard{};
    std::vector<Chessboard> moveSequences;
    Computer black {};
    Computer white {};
    std::vector<Position> b;
    std::vector<Position> w;
    std::string blackInput;
    std::string whiteInput;
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
        int squad = rand()%2; // se 0 persona bianca altrimenti nera
        do
        {
           if(squad == 0)
           {
               bool condition = true;
               //scelta mossa utente bianco
               while(condition)
               {
                   std::cout<<"Mossa bianco: ";
                   std::cin>>whiteInput;   //es: "A3 B4"
                   int letterS = whiteInput[0] - 97; // A
                   int numberS = whiteInput[1] - 1;  // 3
                   int letterE = whiteInput[3] - 97; // B
                   int numberE = whiteInput[4] - 1;  // 4
                   if((numberE < 0 || numberE > 7) || (numberS < 0 || numberS > 7))
                        condition = true;
                  else if((letterE < 0 || letterE > 7) || (letterS < 0 || letterS > 7))
                        condition = true;    
                  else
                        condition = false;
                  Position start = Position(letterS, numberS);
                  if(gameBoard.get_piece(start)->get_type() == 0) 
                        condition = true;
                  std::vector<std::vector<Position>> moves = gameBoard.get_piece(start)->get_moves(gameBoard);
                  if(moves[0].size() == 0 && moves[1].size() == 1)
                        condition = true;  
                  if(whiteInput[0] == 'X' && whiteInput[1] == 'X' && whiteInput[2] == ' ' && whiteInput[3] == 'X' && whiteInput[4] == 'X')  
                  {
                        std::cout<<gameBoard.to_string();
                  }  
                  if(condition == true)
                        std::cout<<"Errore nell'inserimento della posizione";
                }
                
                //esecuzione mossa utente bianco
                int letterS = whiteInput[0] - 97;
                int numberS = whiteInput[1] - 1;
                int letterE = whiteInput[3] - 97;
                int numberE = whiteInput[4] - 1;
                Position start = Position(letterS, numberS);
                Position end = Position(letterE, numberE);
                if(gameBoard.get_piece(end) == new Space())
                    gameBoard.shift(start, end);
                else
                {
                    gameBoard.eatBlack(*gameBoard.get_piece(end));
                    gameBoard.shift(start, end);
                }
                moveSequences.push_back(gameBoard);
                file.write_file(gameBoard, start, end);

                print(gameBoard, start, whiteInput);

                //se la partita è in parità non continua
                if(gameBoard.checkRules(gameBoard) == 2 && gameBoard.par(move, gameBoard) == 2 && gameBoard.alreadySeen(moveSequences, gameBoard) == 2)
                {
                    //scelta mossa computer nero
                    b = black.exe_move(gameBoard);
                    Piece* pieceB = gameBoard.get_piece(black.exe_move(gameBoard)[0]);
                    Position moveS = pieceB->get_position();
                    Position moveB = b[1];
                    Piece* pieceW = gameBoard.get_piece(moveB);

                    //esecuzione mossa computer nero
                    if(pieceW->get_type() == 0)
                        gameBoard.shift(moveS, moveB);
                    else
                    {
                        gameBoard.eatWhite(*pieceW);
                        gameBoard.shift(moveS, moveB);
                    }
                    moveSequences.push_back(gameBoard);
                    file.write_file(gameBoard, moveS, moveB);
                    blackInput += (char)(moveS.get_letter()+97) + (int)(moveS.get_number()+1) + " " + (char)(moveB.get_letter()+97) + (int)(moveB.get_number()+1);
                    print(gameBoard, moveS, blackInput);
                }    
            }
            else
            {
                //scelta mossa computer bianco
                w = white.exe_move(gameBoard);
                Piece* pieceW = gameBoard.get_piece(b[0]);
                Position moveS = pieceW->get_position();
                Position moveW = b[1];
                Piece* pieceB = gameBoard.get_piece(moveW);

                //esecuzione mossa computer bianco
                if(pieceW->get_type() == 0)
                    gameBoard.shift(moveS, moveW);
                else
                {
                    gameBoard.eatWhite(*pieceB);
                    gameBoard.shift(moveS, moveW);
                }        
                moveSequences.push_back(gameBoard);
                file.write_file(gameBoard, moveS, moveW);
                whiteInput += (char)(moveS.get_letter()+97) + (int)(moveS.get_number()+1) + " " + (char)(moveW.get_letter()+97) + (int)(moveW.get_number()+1);
                print(gameBoard, moveS, whiteInput);

                if(gameBoard.checkRules(gameBoard) == 2 && gameBoard.par(move, gameBoard) == 2 && gameBoard.alreadySeen(moveSequences, gameBoard) == 2)
                {
                    bool condition = true;
                    //scelta mossa utente nero
                    while(condition)
                    {
                       std::cout<<"Mossa nero: ";
                       std::cin>>blackInput;   //es: "A3 B4"
                       int letterS = blackInput[0] - 97; // A
                       int numberS = blackInput[1] - 1;  // 3
                       int letterE = blackInput[3] - 97; // B
                       int numberE = blackInput[4] - 1;  // 4
                       if((numberE < 0 || numberE > 7) || (numberS < 0 || numberS > 7))
                            condition = false;
                       else if((letterE < 0 || letterE > 7) || (letterS < 0 || letterS > 7))
                            condition = false;    
                       else
                            condition = true;
                       Position start = Position(letterS, numberS);
                       if(gameBoard.get_piece(start) == new Space()) 
                            condition = true;
                       if(whiteInput[0] == 'X' && whiteInput[1] == 'X' && whiteInput[2] == ' ' && whiteInput[3] == 'X' && whiteInput[4] == 'X')  
                        {
                            std::cout<<gameBoard.to_string();
                        }  
                        if(condition == true)
                            std::cout<<"Errore nell'inserimento della posizione";
                    }

                    //esecuzione mossa utente nero
                    int letterS = blackInput[0] - 97;
                    int numberS = blackInput[1] - 1;
                    int letterE = blackInput[3] - 97;
                    int numberE = blackInput[4] - 1;
                    Position start = Position(letterS, numberS);
                    Position end = Position(letterE, numberE);
                    if(gameBoard.get_piece(end) == new Space())
                        gameBoard.shift(start, end);
                    else
                    {
                        gameBoard.eatBlack(*gameBoard.get_piece(end));
                        gameBoard.shift(start, end);
                    }
                    moveSequences.push_back(gameBoard);
                    file.write_file(gameBoard, start, end);

                    print(gameBoard, start, blackInput);
                } 

            }
            move++;    
        }while(gameBoard.checkRules(gameBoard) == 2 && gameBoard.par(move, gameBoard) == 2 && gameBoard.alreadySeen(moveSequences, gameBoard) == 2);

        if(gameBoard.par(move,gameBoard) == 0 || gameBoard.alreadySeen(moveSequences, gameBoard) == 0)
        {
            std::cout<<"Partita finita in parità";
            return 0;
        }
        else if(gameBoard.checkRules(gameBoard) == -1)
        {
            std::cout<<"Vincono i neri, il computer";
            return 0;
        }
        else if(gameBoard.checkRules(gameBoard) == 1)
        {
            std::cout<<"Vincono i bianchi";
            return 0;
        }
        else  
        {  
            std::cout<<"Partita finita in parità";  
            return 0;
        }  
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
            whiteInput += (char)(moveS.get_letter()+97) + (int)(moveS.get_number()+1) + " " + (char)(moveW.get_letter()+97) + (int)(moveW.get_number()+1);
            print(gameBoard, moveS, whiteInput);

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
                blackInput += (char)(moveS.get_letter()+97) + (int)(moveS.get_number()+1) + " " + (char)(moveB.get_letter()+97) + (int)(moveB.get_number()+1);
                print(gameBoard, moveS, blackInput);
            }
            else if(gameBoard.checkRules(gameBoard) == -1)
            {
                std::cout<<"Vincono i neri, il computer";
                return 0;
            }
            else if(gameBoard.checkRules(gameBoard) == 1)
            {
                std::cout<<"Vincono i bianchi";
                return 0;
            }
            else
            {
                std::cout<<"Partita finita in parità";
                return 0;
            }

            if(gameBoard.par(move, gameBoard) == 0 || gameBoard.alreadySeen(moveSequences, gameBoard) == 0)
            {
                std::cout<<"Partita finita in parità";
                return 0;
            }
            else if(gameBoard.checkRules(gameBoard) == -1)
            {
                std::cout<<"vincono i neri";
                return 0;
            }
            else if(gameBoard.checkRules(gameBoard) == 1)
            {
                std::cout<<"vincono i bianchi";
                return 0;
            }
            else
            {
                std::cout<<"Partita finita in parità";
                return 0;
            }
        }
        return 0;
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