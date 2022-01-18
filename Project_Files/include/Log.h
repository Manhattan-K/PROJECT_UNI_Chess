/*  Lorenzo Leone 2000160  */


/*
    std::fstream file :
            corrisponde al file txt su cui verranno scritte le mosse eseguite durante la partita

    std::string title :
            titolo del file txt

    Log() :
            costruttore di default della classe Log, ha come titolo "Log.txt"

    Log(std::string title) :
            costruttore che crea un file txt con titolo custom (inserito a parametro)

    write_xy(std::string s, Position a, Position b) :
            funzione che ha come parametri
                1) std::string s : il titolo del txt su cui salvare le mosse
                2) Position a : posizione iniziale della pedina da muovere
                3) Position b : posizione che la pedina occuperà alla fine del turno
            
            con questi valori, creo un stringa sul file "s.txt" del tipo "a-b" (es. "A1-B5"), dove le lettere
            sono espresse in codifica ASCII.

    read_xy(std::string s) :
            funzione che restituisce una mossa a chiamata in ordine cronologico d'inserimento.


*/
#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <fstream>
#include "Chessboard.h"

class Log 
{
    public:
        Log();
        Log(std::string title);
        void write_xy(std::string s, Position a, Position b);
        std::vector<Position> read_xy(std::string s); //per ora è void, alla fine sarà un vettore di posizioni
    
    private:
        std::fstream file;
        std::string title;
};

#endif