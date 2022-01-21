/*  Lorenzo Leone 2000160  */

#include "Log.h"
#include "Space.h"
#include <string>
//--------------------------------------------------------| Costruttori e distruttore |--------------------------------------------------------
Log::Log()
{
    title = "log.txt";
    file.open(title);
}
Log::Log(std::string s)
{
    title = s;
    file.open(title);
}

//--------------------------------------------------------| Funzioni |--------------------------------------------------------
/*
    ( Commento per lo sviluppatore che sarà tolto in futuro C: )
    Ricorda che le coordinate sono del tipo "A1", dove le lettere (es. A), vengono convertite in numeri (int)
    e a tal numero sottraggo 97, seguendo la codifica ASCII (string xy = "A1"; int lettera = xy[0] - 97; int numero = xy[1]; ).

    Ricorda che get_letter(), restituisce la lettera in codifica ASCII, descritto sopra.
*/


void Log::write_file(std::string t, Chessboard& cb, Position a, Position b)
{   
    Chessboard board = cb;    
    Log mt(t);
    int letter_a = a.get_letter() + 97;
    int number_a = a.get_number() + 1;
    std::string pos_in = "" + letter_a + number_a;

    int letter_b = b.get_letter() + 97;
    int number_b = b.get_number() + 1;
    std::string pos_fin = "" + letter_b + number_a;

    int type = mt.w_move_type(board, a, b);

    file.open(mt.title, std::ios::out | std::ios::app); //write in modalità append
    /*
        _> ios::out, indica che s.txt verrà aperto in modalità scrittura.
        _> ios::app, indica che ciò che viene scritto verrà aggiunto in seguito all'ultima modifica eseguita in s.txt.
        _> il simbolo | combina le modalità di apertura file.
    */ 
    if(file.is_open())
    {
        /*
            nel file le coodinate saranno salvate:
            pos_in pos_fin type\n
            pos_in pos_fin type\n
            ...

            di fianco alla pos_fin sarà salvato il tipo di mossa effettuato
        */
        file << pos_in << pos_fin << type + "\n";
        
    }
    file.close();
}


//da finire con il tipo di mossa
std::vector<int> Log::read_file(std::string t)
{
    Log mt(title);
    int letter;
    int number;
    int type;
    Position temp;
    std::string pos_str;
    std::vector<int> move;
    std::vector<int> hollow; //vettore vuoto restituito in caso di "errori"

    file.open(mt.title, std::ios::in); //read
    if (!file.eof() && file.is_open())  //file.eof() restituisce true, se nel file sono finiti i dati da leggere.
    {
        /*
            uso un for che si ripete due volte perchè
            nel file le coodinate sono salvate:
            pos_in pos_fin type\n   (prima mossa)
            pos_in pos_fin type\n   (seconda mossa)
            ...
        */
        
        getline(file, pos_str);
        letter = pos_str[0] - 97;
        number = pos_str[1] - 1;
        move.push_back(letter);
        move.push_back(number);

        letter = pos_str[2] - 97;
        number = pos_str[3] - 1;
        move.push_back(letter);
        move.push_back(number);

        type = pos_str[4];
        
        return  move;
        /*
            move contiene ora una serie di numeri : 
            move[0]: il numero corrispondente alla x della pos_in
            move[1]: il numero corrispondente alla y della pos_in
            move[2]: il numero corrispondente alla x della pos_fin
            move[3]: il numero corrispondente alla y della pos_fin
            move[4]: il numero corrispondente al move_type
        */
    }
    file.close();
}


std::vector<Position> Log::get_xy(std::string t)
{
    std::vector<int> move = read_file(t);
    std::vector<Position> v_move;

    Position a;
    int letter_a = move[0];
    int number_a = move[1];
    a.set_position(letter_a, number_a);
    v_move.push_back(a);
    
    Position b;
    int letter_b = move[2];
    int number_b = move[3];
    b.set_position(letter_a, number_b);
    v_move.push_back(b);

    return v_move;
}


bool Log::file_eof(std::string t)
{
    Log mt(t);
    file.open(mt.title);
    return file.eof();
}


int Log::w_move_type(Chessboard& cb, Position a, Position b)
{
    Chessboard board = cb;
    Position pos_in = a;
    Position pos_fin = b;
    int type;
    if(board.get_piece(pos_fin) == new Space())
    {
        type = 0; //Spostamento 
    }
    else
    {
        type = 1; //Mangiato
    }
    return type;

}


