/*  Lorenzo Leone 2000160  */

#include "Log.h"
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
void Log::write_xy(std::string s, Position a, Position b)
{   
    int letter_a = a.get_letter() + 97;
    int number_a = a.get_number() + 1;
    std::string pos_in = "" + letter_a + number_a;

    int letter_b = b.get_letter() + 97;
    int number_b = b.get_number() + 1;
    std::string pos_fin = "" + letter_b + number_a;

    file.open(s, std::ios::out | std::ios::app); //write in modalità append
    /*
        _> ios::out, indica che s.txt verrà aperto in modalità scrittura.
        _> ios::app, indica che ciò che viene scritto verrà aggiunto in seguito all'ultima modifica eseguita in s.txt.
        _> il simbolo | combina le modalità di apertura file.
    */ 
    if(file.is_open())
    {
        /*
            nel file le coodinate saranno salvate:
            pos_in\n
            pos_fin\n
            pos_in\n
            pos_fin\n
            ...
        */
        file << pos_in + "\n";
        file << pos_fin + "\n";
    }
    file.close();
}

std::vector<Position> Log::read_xy(std::string s)
{
    
    int letter;
    int number;
    Position temp;
    std::string pos_str;
    std::vector<Position> move;

    file.open(s, std::ios::in); //read
    if (!file.eof() && file.is_open())  //file.eof() restituisce true, se nel file sono finiti i dati da leggere.
    {
        /*
            uso un for che si ripete due volte perchè
            nel file le coodinate sono salvate:
            pos_in\n
            pos_fin\n   (prima mossa)
            pos_in\n
            pos_fin\n   (seconda mossa)
            ...
        */
        for(int i = 0; i < 2; i++) 
        {
            getline(file, pos_str);
            letter = pos_str[0] - 97;
            number = pos_str[1] - 1;
            temp.set_position(letter, number);
            move.push_back(temp);
            //al primo ciclo, salva pos_in, al secondo, salva pos_fin
        }
        file.close();
        return  move; //move contiene un coppia di posizioni, move[0] = pos_in, move[1] = pos_fin.
    }
    else if(!file.is_open())
    {
        std::cout<<"ERRORE: file non aperto per l'acquisizione dati (controlla read_xy in log.cpp)\n";
    }  
    else
    {
        std::cout<<"Dati acquisibili dal file " << s << " terminati!";
        file.close();     
    }
    /*
    NON SO SE E' GIUSTO MA TI SERVE UN RETURN DI UN VETTORE, MAGARI RITORNA UN VETTORE VUOTO SE PROPRIO NON DOVRESTI RITORNARE NULLA
    */
    return move;
    }
