/*  Lorenzo Leone 2000160  */

#include "Position.h"
#include "Chessboard.h"
#include "Log.h"

int main()
{
    Chessboard board = {};
    std::vector<Position> move;
    Log file_log;
    char choice;
    do
    {
        std::cout << "Scegliere modulo esecuzione di Replay:\n"; 
        std::cout << "Inserire il caratte ( v ) per visualizzare il replay desiderato.\n" << "Inserire il carattere ( f ) per trascrivere il replay su un file (.txt).\n";
        std::cin >> choice;

    } while (choice != 'v' && choice != 'f');
    
    if(choice == 'v')
    {
        std::string file_title;
        bool eof;

        std::cout << "Inserire il nome del file(.txt) replay da visualizzare.\n";
        std::cin >> file_title;
        do
        {
            move = file_log.get_xy(file_title); //get_xy() restituisce una coppia di coordinate (di una mossa) a chiamata
            Position pos_in = move[0];
            Position pos_fin = move[1];
            board.shift(pos_in, pos_fin);  //esegue la mossa descritta dalle coordinate ricevute a parametro

            eof = file_log.file_eof(file_title); //file_eof() restituisce true quando non ci son più valori da acquisire dal file
        } while(!eof);
    }

    if(choice == 'f')
    {
        std::string file_from;
        std::string file_to;
        bool eof;

        std::cout << "Inserire il nome del file(.txt) replay da cui trascrivere.\n";
        std::cin >>  file_from;
    }
    return 0;
}