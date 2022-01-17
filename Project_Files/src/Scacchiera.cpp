/*  Filippo Franceschetto */

#include "Position.h"
#include "Chessboard.h"
#include "Computer.h"
#include "Log.h"
#include "Piece.h"
#include "Space.h"
#include <iostream>

int main()
{
    Chessboard c = Chessboard();
    char role;
    do
    {
        std::cout<<"Inserire il tipo di partita che si desidera svolgere;";
        std::cout<<"Se si sceglie Computer_VS_Computer inserire 'c' \n Se si sceglie Computer_VS_Persona inserire 'p'";
        std::cin>>role;
    } while (role != 'c' && role != 'p');
    if(role == 'p')
    {
        Computer black = Computer();
        std::vector<Position> b;
        do
        {
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
                if(c.get_piece(end) == new Space()) 
                    condition = false;  
            } while (condition);

            //esecuzione mossa utente bianco
            int letterS = white[0] - 97;
            int numberS = white[1] - 1;
            int letterE = white[3] - 97;
            int numberE = white[4] - 1;
            Position start = Position(letterS, numberS);
            Position end = Position(letterE, numberE);
            if(c.get_piece(end) == new Space())
                c.shift(start, end);
            else
            {
                c.eatBlack(*c.get_piece(end));
                c.shift(start, end);
            }
            
            //se la partita è in parità non continua
            if(c.checkRules() == 2)
            {
                //scelta mossa computer nero
                b = black.exe_move(c);
                Piece* pieceB = c.get_piece(b[0]);
                Position moveS = pieceB->get_position();
                Position moveB = b[1];
                Piece* pieceW = c.get_piece(moveB);

                //esecuzione mossa computer nero
                if(pieceB == new Space())
                    c.shift(moveS, moveB);
                else
                {
                    c.eatWhite(*pieceB);
                    c.shift(moveS, moveB);
                }
            }        
        }while(c.checkRules() == 2);

        if(c.checkRules() == -1)
            std::cout<<"Vincono i neri, il computer";
        else if(c.checkRules() == 1)
            std::cout<<"Vincono i bianchi";
        else    
            std::cout<<"Partita finita in parità";    
    }
    else
    {
        Computer white = Computer();
        Computer black = Computer();
        std::vector<Position> w;
        std::vector<Position> b;        
        for(int moves = 0; moves<40 && c.checkRules() == 2; moves++)
        {   //scelta mossa bianco
            w = white.exe_move(c);
            Piece* pieceW = c.get_piece(w[0]);
            Position moveS = pieceW->get_position();
            Position moveW = w[1];
            Piece* pieceB = c.get_piece(moveW);
            //esecuzione mossa bianco
            if(pieceB == new Space())
                c.shift(moveS, moveW);
            else
            {
                c.eatBlack(*pieceB);
                c.shift(moveS, moveW);
            }

            if(c.checkRules() != 0 && c.checkRules() !=1)
            {   //scelta mossa nero
                b = black.exe_move(c);
                Piece* pieceB = c.get_piece(b[0]);
                Position moveS = pieceB->get_position();
                Position moveB = b[1];
                Piece* pieceW = c.get_piece(moveB);
                //esecuzione mossa nero
                if(pieceW == new Space())
                    c.shift(moveS, moveB);
                else
                {
                    c.eatWhite(*pieceW);
                    c.shift(moveS, moveB);
                }
            }
            else if(c.checkRules() == -1)
                std::cout<<"Vincono i neri, il computer";
            else if(c.checkRules() == 1)
                std::cout<<"Vincono i bianchi";
            else
                std::cout<<"Partita finita in parità";
        }
    }
    
    std::cout << "\n\t-><- Il programma compila senza errori, uWu -><-\n";
    return 0;
}