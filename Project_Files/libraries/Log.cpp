/*  Lorenzo Leone 2000160  */

#include "Log.h"

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
void Log::write_xy(std::string s, Position a, Position b)
{   
    int letter_a = a.get_letter(); 
    int number_a = a.get_number();
    std::string pos_in = "" + letter_a + number_a;

    int letter_b = b.get_letter();
    int number_b = b.get_number();
    std::string pos_fin = "" + letter_b + number_a;

    std::string move = pos_in + "-" + pos_fin + "\n"; //ogni mossa inserita in s.txt avrà forma a-b (es. A1-B5)

    file.open(s, std::ios::out | std::ios::app);
    /*
        _> ios::out, indica che s.txt verrà aperto in modalità scrittura.
        _> ios::app, indica che ciò che viene scritto verrà aggiunto in seguito all'ultima modifica eseguita in s.txt.
        _> il simbolo | combina le modalità di apertura file.
    */ 

    file << move;
    file.close();
}
/*
std::vector<Position> Log::read_xy(std::string s)
{
    file.open(s, std::ios::in);
}
*/