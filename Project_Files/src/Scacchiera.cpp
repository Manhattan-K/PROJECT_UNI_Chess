/*  Filippo Franceschetto */

#include "Position.h"
#include "Chessboard.h"
#include "Computer.h"
#include "Log.h"

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
        std::string white;
        std::string black;
        bool condition;
        do
        {
            std::cout<<"Mossa bianco: ";
            std::cin>>white;   //es: "A3 B4"
            int letterF = white[0] - 97; // A
            int numberF = white[1] - 1;  // 3
            int letterS = white[3] - 97; // B
            int numberS = white[4] - 1;  // 4
            if((numberF < 0 || numberF > 7) || (numberS < 0 || numberS > 7))
                condition = true;
            else if((letterF < 0 || letterF > 7) || (letterS < 0 || letterS > 7))
                condition = true;    
            else
                condition = false;
        } while (condition);
        
        //esecuzione mossa bianca

        do
        {
            std::cout<<"Mossa nero: ";
            std::cin>>black;
            int letterF = black[0] - 97;
            int numberF = black[1] - 1;
            int letterS = black[3] - 97;
            int numberS = black[4] - 1;
            if((numberF < 0 || numberF > 8) || (numberS < 0 || numberS > 8))
                condition = true;
            else if((letterF < 0 || letterF > 7) || (letterS < 0 || letterS > 7))
                condition = true;
            else 
                condition = false;
        } while (condition);  

        /*
        do
        {
            
        } while (c.checkRules() == 2);
        */

        //esecuzione mossa nero 
    }
    if(role == 'c')
    {
        /*

                -> LEONE HA CAMBIATO I NOMI DEI FILE, CHIEDI A LUI COSA FANNO I VARI METODI PERCHE' ALCUNI SONO NOVI OPPURE NON FANNO LE STESSE <-

        Computer white = Computer();
        Computer black = Computer();
        
        for(int i = 0; i<40 || c.checkRules() == 2; i++)
        {
            Piece* pieceW = white.RandPiece();
            Position moveW = white.RandMove(pieceW, c);
            white.ExeMove(pieceW, moveW);
            if(c.checkRules() != 0 && c.checkRules() !=1)
            {
                Piece* pieceB = black.RandPiece();
                Position moveB = black.RandMove(pieceB, c);
                black.ExeMove(pieceB, moveB);
            }
        }

        */
    }
    
    std::cout << "\n\t-><- Il programma compila senza errori, uWu -><-\n";
    return 0;
}