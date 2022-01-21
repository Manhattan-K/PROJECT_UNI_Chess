/*  Lorenzo Leone 2000160  */

#include "Position.h"
#include "Chessboard.h"
#include "Log.h"
#include <String>

int main()
{
    Chessboard board;    
    Log file_log;
    char choice;
    do
    {
        std::cout << "Scegliere modulo esecuzione di Replay:\n"; 
        std::cout << "Inserire il caratte ( v ) per visualizzare il replay desiderato.\n" << "Inserire il carattere ( f ) per trascrivere il replay su un file (.txt).\n";
        std::cin >> choice;

    } while (choice != 'v' && choice != 'f');
    

    //Visualizza in replay 
    if(choice == 'v')
    {
        std::vector<int> move;
        std::vector<Position> v_move;
        std::string file_title;
        bool eof;

        std::cout << "Inserire il nome del file(.txt) replay da visualizzare.\n";
        std::cin >> file_title;
        //std::cout << board; //visualizzo la schacchiara prima del loop, così da avere una visualizzazione iniziale della scacchiera
        do
        {
            move = file_log.read_file(file_title);
            v_move = file_log.get_xy(move); //get_xy() restituisce una coppia di coordinate (di una mossa) a chiamata
            Position pos_in = v_move[0];
            Position pos_fin = v_move[1];
            board.shift(pos_in, pos_fin);  

            //visualizzazione su terminale.
            //std::cout << board;            
            file_log.spec_type_move(board, move); // commenta ciascuna mossa

            eof = file_log.file_eof(file_title); //file_eof() restituisce true quando non ci son più valori da acquisire dal file
        } while(!eof);
    }


    //Trascrive le mosse del replay in un altro file.txt
    if(choice == 'f')
    {
        std::ifstream file_from;
        std::string title_from;

        std::ofstream file_to;
        std::string title_to;
        std::string str;

        std::cout << "Inserire il nome del file(.txt) replay da cui trascrivere.\n";
        std::cin >>  title_from;
        std::cout << "Inserire il nome del file(.txt) replay su cui trascrivere.\n";
        std::cin >>  title_to;

        file_from.open(title_from, std::ios::in); file_to.open(title_to, std::ios::out | std::ios::app);
        do 
        {   
            getline(file_from, str);
            file_to << str;
        }
        while(!file_from.eof());
        file_from.close(); file_to.close();
    }
    return 0;
}