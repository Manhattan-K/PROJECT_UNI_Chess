/*  Lorenzo Leone 2000160  */

#include "Log.h"
#include "Space.h"
#include <string>
//--------------------------------------------------------| Costruttori e distruttore |--------------------------------------------------------
Log::Log()
{
    title = "log.txt";
    file.open(title);
    file.close();
}
Log::Log(std::string s)
{
    title = s;
    file.open(title);
    file.close();
}

//--------------------------------------------------------| Funzioni |--------------------------------------------------------
/*
    ( Commento per lo sviluppatore che sarà tolto in futuro C: )
    Ricorda che le coordinate sono del tipo "A1", dove le lettere (es. A), vengono convertite in numeri (int)
    e a tal numero sottraggo 97, seguendo la codifica ASCII (string xy = "A1"; int lettera = xy[0] - 97; int numero = xy[1]; ).

    Ricorda che get_letter(), restituisce la lettera in codifica ASCII, descritto sopra.
*/
void Log::write_xy(std::string t, Chessboard& cb, Position a, Position b)
{   
    Chessboard board = cb;
    Log mt;
    

    int letter_a = a.get_letter() + 97;
    int number_a = a.get_number() + 1;
    std::string pos_in = "" + letter_a + number_a;

    int letter_b = b.get_letter() + 97;
    int number_b = b.get_number() + 1;
    std::string pos_fin = "" + letter_b + number_a;

    int type = mt.move_type(board, a, b);

    file.open(t, std::ios::out | std::ios::app); //write in modalità append
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
std::vector<Position> Log::read_xy(std::string t)
{
    
    int letter;
    int number;
    int type;
    Position temp;
    std::string pos_str;
    std::vector<Position> move;
    std::vector<Position> hollow; //vettore vuoto restituito in caso di "errori"

    file.open(t, std::ios::in); //read
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
        temp.set_position(letter, number);
        move.push_back(temp);
        letter = pos_str[2] - 97;
        number = pos_str[3] - 1;
        temp.set_position(letter, number);
        move.push_back(temp);
        type = pos_str[4];
        
        return  move; //move contiene un coppia di posizioni, move[0] = pos_in, move[1] = pos_fin.
    }
    file.close();
}

bool Log::file_eof(std::string t)
{
    file.open(t);
    return file.eof();
}

int Log::move_type(Chessboard& cb, Position a, Position b)
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