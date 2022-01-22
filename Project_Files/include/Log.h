/*  Lorenzo Leone 2000160  */


/*
--------| VARIABILI |--------------------------------------------------
    std::fstream file :
            corrisponde al file txt su cui verranno scritte le mosse eseguite durante la partita

    std::string title :
            titolo del file txt (scrivere la directory del file.txt)

--------| COSTRUTTORI |------------------------------------------------
    Log() :
            costruttore di default della classe Log, ha come titolo "Log.txt"

    Log(std::string title) :
            costruttore che crea un file txt con titolo custom (inserito a parametro)

--------| FUNZIONI |---------------------------------------------------
    write_file(Log mt, Chessboard& cb, Position a, Position b) :
            funzione che ha come parametri
                1) Log mt : oggetto log, in cui è specificato il titolo del file.txt
                2) Chessboard& cb: oggetto chessboard, necessario per l'uso di certe funzioni interne (come w_move_type)
                2) Position a : posizione iniziale della pedina da muovere
                3) Position b : posizione che la pedina occuperà alla fine del turno
            
            con questi valori, creo un stringa sul file "s.txt" del tipo "A1B50"), dove i primi due
            caratteri solo la posizione iniziale, il terzo e quarto la posizione finale, e il quinto è
            il tipo di mossa effettuata, assegnata da w_move_type (write_move_type per esteso).

    read_file(std::string s) :
            Partendo dal file.txt, estrae ogni mossa in forma di un vettore di int, che da solo non fa nulla, necessita di get_xy() e spec_type_move()

    file_eof(std::string t) :
            funzione che restituisce true quando sono finiti gli elementi da acquisire del file

    get_xy(std::vector<int> move) :
            parte dal vettore restituito da read_file() e restituisce a sua volta un vettore di posizione che contiene 
            due posizioni, quella iniziale e finale della mossa effettuata

    w_move_type(Chessboard& cb, Position a, Position b) :
            funzione usata all'interno di write_file(), con il compito di filtrare e assegnare che tipo di mossa
            è stata effettuata attraverso una serie di if.
            Restituisce un numero int:
            - 0 : la mossa porta alla vittoria dei pezzi neri;
            - 1 : la mossa porta alla situazione di patta;
            - 2 : la mossa porta alla vittoria dei pezzi bianchi;
            - 3 : la mossa è un semplice spostamento;
            - 4 : la mossa porta una pedina a "mangiare" una avversaria.
    
    spec_type_move(Chessboard& cb, std::vector<int> move) :
            funzione simile a w_move_type, usata però per i commenti dopo una mossa,
            in base allo schema soprastante, scrive su terminale cosa è successo dopo ogni mossa.
            Esegue anche un "Assegnamento testuale" alle diverse informazioni di una pedina.


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
        Log(std::string t);
        bool file_eof(std::string t);
        std::vector<int> read_file(std::string t); 
        std::vector<Position> get_xy(std::vector<int> move);
        int w_move_type(Chessboard& cb, Position a, Position b);
        void write_file(Chessboard& cb, Position a, Position b); 
        std::string spec_type_move(Chessboard& cb, std::vector<int> move);

        ~Log() {   file.close();   }
       
    private:
        std::fstream file;
        std::string title;
};

#endif