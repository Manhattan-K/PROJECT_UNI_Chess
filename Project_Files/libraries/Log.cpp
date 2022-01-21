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

//Funzione che da Schacchiera, salva le mosse su un file.txt
//(Filippo, dovrai creare un oggetto Log, e scrivere questa funzione dopo ogni shift :D)
void Log::write_file(Log mt, Chessboard& cb, Position a, Position b)
{   
    Chessboard board = cb;
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


//Partendo dal file.txt, estrae ogni mossa in forma di un vettore di int, che da solo non fa nulla, necessita di get_xy() e spec_type_move()
std::vector<int> Log::read_file(std::string t)
{
    title = t;
    int letter;
    int number;
    int type;
    Position temp;
    std::string pos_str;
    std::vector<int> move;
    std::vector<int> hollow; //vettore vuoto restituito in caso di "errori"

    file.open(title, std::ios::in); //read
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

std::vector<Position> Log::get_xy(std::vector<int> move)
{
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
    if(cb.checkRules(cb) == -1)
    {
        type = 0; //vincono i neri
    }
    else if(cb.checkRules(cb) == 0)
    {
        type = 1; //patta
    }
    else if(cb.checkRules(cb) == 1)
    {
        type = 2; //vincono i bianchi
    }
    else if(cb.checkRules(cb) == 2 && board.get_piece(pos_fin) == new Space())
    {
        type = 3; //spostamento senza "mangiata"
    }
    else if(cb.checkRules(cb) == 2)
    {
        type = 4; //spostamento con "mangiata"
    }
    return type;

}

void Log::spec_type_move(Chessboard& cb, std::vector<int> move)
{     
    int type = move[4]; //ottengo il tipo di mossa
    //posizioni per uotput testuale
    std::string pos_in = "" + move[0] + move[1];
    std::string pos_fin = "" + move[2] + move[3];

    //Info logistiche della pedina in posizione pos_in
    std::vector<Position> v_move = get_xy(move);
    Position v_pos_in = v_move[0];
    Piece* p1 = cb.get_piece(v_pos_in);
    int type_piece1 = p1->get_type();   //ottengo il tipo di pedina in pos_fin
    bool team_piece1 = p1->get_team();  //ottengo la fazione d'appartenenza della pedina in pos_fin
    std::string type_p1;
    std::string team_p1;

    //assegnamento testuale del tipo di pedina in pos_in
    if(type_piece1 == 1) //Re
    {
        type_p1 = "King";
    }
    if(type_piece1 == 2) //Regina
    {
        type_p1 = "Queen";
    }
    if(type_piece1 == 3) //Pedone
    {
        type_p1 = "Pawn";
    }
    if(type_piece1 == 4) //Alfiere
    {
        type_p1 = "Bishop";
    }
    if(type_piece1 == 5) //Cavallo
    {
        type_p1 = "Horse";
    }
    if(type_piece1 == 6) //Torre
    {
        type_p1 = "Rook";
    }

    //assegnamento testuale delle fazione d'appartenenza della pedina in pos_in
    if(team_piece1 == true)
    {
        team_p1 = "White";
    }
    else
    {
        team_p1 = "Black";
    }



    //Info logistiche della pedina in posizione pos_fin
    Position v_pos_fin = v_move[1]; 
    Piece* p2 = cb.get_piece(v_pos_fin);
    int type_piece2 = p2->get_type();   //ottengo il tipo di pedina in pos_fin
    bool team_piece2 = p2->get_team();  //ottengo la fazione d'appartenenza della pedina in pos_fin
    std::string type_p2;
    std::string team_p2;

    //assegnamento testuale del tipo di pedina in pos_fin
    if(type_piece2 == 1) //Re
    {
        type_p2 = "King";
    }
    if(type_piece2 == 2) //Regina
    {
        type_p2 = "Queen";
    }
    if(type_piece2 == 3) //Pedone
    {
        type_p2 = "Pawn";
    }
    if(type_piece1 == 4) //Alfiere
    {
        type_p2 = "Bishop";
    }
    if(type_piece1 == 5) //Cavallo
    {
        type_p2 = "Horse";
    }
    if(type_piece1 == 6) //Torre
    {
        type_p2 = "Rook";
    }

    //assegnamento testuale delle fazione d'appartenenza della pedina in pos_fin
    if(team_piece2 == true)
    {
        team_p2 = "White";
    }
    else
    {
        team_p2 = "Black";
    }



    //Commenti delle diverse mosse
    if(type == 0) //vincono i neri
    {
        std::cout << "\nLa pedina " + type_p1 + " ( " + team_p1 + " ) in posizione " + pos_in + " si muove alla posizione " + pos_fin +".\nVince la fazione NERA";
    }
    else if(type == 1) //patta
    {
        std::cout << "\nLa pedina " + type_p1 + " ( " + team_p1 + " ) in posizione " + pos_in + " si muove alla posizione " + pos_fin +".\nSi termina con una situazione di PATTA";
    }
    else if(type == 2) //vincono i bianchi
    {
        std::cout << "\nLa pedina " + type_p1 + " ( " + team_p1 + " ) in posizione " + pos_in + " si muove alla posizione " + pos_fin +".\nVince la fazione BIANCA";
    } 
    else if(type == 3) //spostamento senza "mangiata"
    {
        std::cout << "\nLa pedina " + type_p1 + " ( " + team_p1 + " ) in posizione " + pos_in + " si muove alla posizione " + pos_fin +".\n";
    }
    else if(type == 4) //spostamento con "mangiata"
    {
        std::cout << "\nLa pedina " + type_p1 + " ( " + team_p1 + " ) in posizione " + pos_in + " si muove alla posizione " + pos_fin +".\n";
        std::cout << "La pedina " + type_p2 + " ( " + team_p2 + " ) in posizione " + pos_fin + " viene mangiata da " + type_p1 + " ( " + team_p1 + " )\n";
    }
}
