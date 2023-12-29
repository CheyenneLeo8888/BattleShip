#include "battleshippvpdeclare.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void Greet::introduceGame(){
    cout << "Cheyenne Leo Games@ presents:----------" <<endl;
    cout << "----------------" << endl;
    cout << "BATTLESHIP!"<< endl;
    cout << "----------------" <<endl;
    cout << "Premi un qualunque pulsante:";
    getch();
    system("cls");
    }
void Greet::introduceGameRules(){
            cout << "Benvenuti! Seguiremo le regole della versione di 'Battaglia Navale' scritta da Milton Bradley nel 1990" << endl;
            cout << "Ogni giocatore ha 4 navi, di lunghezza variabile da 2 caselle a 5, una per tipo." << endl;
            cout << "Per vincere, affondate tutte le navi dell'avversario." << endl;
            cout << "Buona fortuna ammiragli!" << endl;
        }
void Greet::introducePositioningPhase(){
            cout << "In questa prima fase della battaglia, gli ammiragli si occupano di posizionare la loro flotta" << endl;
        }
void Greet::positioningIntermezzo(string cap1Name, string cap2Name){
    cout << "Flotta dell'ammiraglio " << cap1Name << " schierata con successo! Si procede ora con lo schieramento della " ;
    cout << "flotta dell'ammiraglio " << cap2Name << "." <<  endl;
    cout << "Ammiraglio  " << cap1Name << ", si allontani dallo schermo." << endl;
    cout << "Ammiraglio " << cap2Name << ", prema un pulsante qualsiasi per iniziare a schierare la sua flotta:" << endl;
    getch();
    system("cls");
}
void Greet::introduceMainGame(){
    cout << "Inizia la battaglia. Vince il primo che affonda tutta la flotta nemica." << endl;
    cout << "Caricate i cannoni!" << endl;
}
Punto::Punto(int gx, int gy ){
            x = gx;
            y = gy;
        }
void Punto::set_x(){
            int gx;
            string instruction;
            do{
                cout << "Scegliere una lettera(a,...,i) -----> x = " ;
                cin >> instruction ;
                cout << endl;
            } while(instruction != "a" && instruction != "b" && instruction != "c" && instruction != "d" && instruction != "e" && instruction != "f" && instruction != "g" && instruction != "h" && instruction != "i");
            if(instruction == "a"){gx = 0;}
            if(instruction == "b"){gx = 1;}
            if(instruction == "c"){gx = 2;}
            if(instruction == "d"){gx = 3;}
            if(instruction == "e"){gx = 4;}
            if(instruction == "f"){gx = 5;}
            if(instruction == "g"){gx = 6;}
            if(instruction == "h"){gx = 7;}
            if(instruction == "i"){gx = 8;}    
            x = gx;
        }
void Punto::set_y(){
            int gy;
            do{
                cout << "Scegliere un intero da 1 a 9 -----> y = " ;
                cin >> gy ;
                cout << endl;
            } while(gy > 9 || gy == 0);
            y = gy - 1;
        }
int Punto::get_x(){
            return x;
        }
int Punto::get_y(){
            return y;
        }
Player::Player(int n){
            string playerName;
            cout << " Giocatore " << n <<", inserisca il suo nome: ";
            getline(cin, playerName);
            cout << endl;
            cout << "Capitano " << playerName << " , benvenuto a bordo!" << endl;
            cout << "\n\n\n\n";
            name = playerName;
            playerTag = n;
        }
int Player::getPlayerTag(){
    return playerTag;
}
string Player::get_name(){
            return name;
        }
void Player::shipSunk(){
    remainingShips -= 1 ;
}
int Player::getRemainingShips(){
    return remainingShips;
}
bool Player::getStatus(){
    return isDefeated;
}
void Player::setStatus(){
    isDefeated = true;
}
void Player::checkStatus(){
    if(remainingShips == 0){
        setStatus();
    }
}
Grid::Grid(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9 ; j++){
            Board[j][i] = 0;
        }
    }
}
void Grid::drawBoard(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int i=0; i<9; i++){
        for(int j=0; j<9 ; j++){
            int value = Board[j][i];
            string strrr;
            switch(value){
                case 1:
                    SetConsoleTextAttribute(hConsole, 7);
                    strrr = "H";
                    break;
                case 2:
                    SetConsoleTextAttribute(hConsole, 8);
                    strrr = "O";
                    break;
                case 3:
                    SetConsoleTextAttribute(hConsole, 4);
                    strrr = "X";
                    break;
                default:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
                    strrr = "0";
                    break;
            }
            cout << strrr << " ";
        }
        cout << endl;
    }
    cout << "\n\n\n" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}
bool Tools::checkPositioning(int n, Punto gp, string direction, Grid gg){
    if(gp.get_x() + n > 9 && direction == "h"){return false;}
    if(gp.get_y() + n > 9 && direction == "v"){return false;}
    for(int i=0; i<n; i++){
        if(direction == "v" && gg.Board[gp.get_x()][gp.get_y() + i] == 1){return false;}
    }
    for(int j=0;j<n;j++){
        if(direction == "h" && gg.Board[gp.get_x() + j][gp.get_y()] == 1){return false;}
    }
    return true;
}
string Tools::setPositioning(){
    string direction;
    do{
        cout << "Scelga la direzione di posizionamento, verticale o orizzontale (v/h)" << endl;
        cin >> direction;
    } while(direction != "v" && direction != "h");
    return direction;
}
void Tools::printBSNotation(Punto gp){
    int gx = gp.get_x();
    int gy = gp.get_y() + 1;
    string gx_bsnotation;
    switch(gx){
        case 0:
            gx_bsnotation = "A";
            break;
        case 1:
            gx_bsnotation = "B";
            break;
        case 2:
            gx_bsnotation = "C";
            break;
        case 3:
            gx_bsnotation = "D";
            break;
        case 4:
            gx_bsnotation = "E";
            break;
        case 5:
            gx_bsnotation = "F";
            break;
        case 6:
            gx_bsnotation = "G";
            break;
        case 7:
            gx_bsnotation = "H";
            break;
        case 8:
            gx_bsnotation = "I";
            break;
    } 
    cout << "Ammiraglio, ha selezionato le coordinate: " << gx_bsnotation << gy  <<endl;
}
//Abstract Product
void Ship::setPosition(vector<Punto> gpositions){
    location = gpositions;
}
void Ship::getPosition(){
    for (Punto punti : location)
    {
        cout << "x: " << punti.get_x() << "," << "y: " << punti.get_y() << endl;
    }
    
}
int Ship::getHitbox(){
    return hitbox;
}
void Ship::setHitpoints(int ghitp){
            hitpoints = ghitp;
}
int Ship::getHitpoints(){
    return hitpoints;
}
void Ship::setHitbox(int n){
    hitbox = n;
}
void Ship::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
bool Ship::isThere(Punto gp){
    for(Punto position : location){
        if(position.get_x() == gp.get_x() && position.get_y() == gp.get_y()){ return true; }
    }
    return false;
}
bool Ship::getIsSunk(){
    return isSunk;
}
Position1::Position1(string gplayer){
    player = gplayer;
}
void Position1::setPosition(){
    Grid ggrid1;
    grid1 = ggrid1;
}
void Position1::deployFleet(Ship* gship){
    positionShip(gship);
}
void Position1::remindRules(int n){
    cout << "A partire dalle coordinate da lei assegnate, la nave si estende per " << n << " caselle nella direzione da lei scelta" <<endl;
}
void Position1::positionShip(Ship* gship){
    int n = gship->getHitbox();
    int x;
    int y;
    Punto p(0,0);
    string direction;
    cout << "Ammiraglio " << player << ", posizioni la sua nave " << gship->getShipName() << ":" << endl;
    remindRules(n);
    do{
        cout << "Scelga le coordinate per inizializzare la nave: " << endl;
        p.set_x();
        p.set_y();
        Tools::printBSNotation(p); 
        direction = Tools::setPositioning();
        if(!Tools::checkPositioning(n,p,direction,grid1)){cout << "Posizionamento richiesto non consentito; riprovare"<<endl;}
    } while(!Tools::checkPositioning(n, p, direction, grid1));
    vector<Punto> positions;
    if(direction == "v"){
        for(int i=0;i<n;i++){
            grid1.Board[p.get_x()][p.get_y() + i] = 1;
            Punto np(p.get_x(), p.get_y() + i);
            positions.push_back(np);
        }
    } else{
            for(int j=0;j<n;j++){
                grid1.Board[p.get_x() + j][p.get_y()] = 1;
                Punto np(p.get_x() + j, p.get_y());
                positions.push_back(np);
            }
    }
    gship->setPosition(positions);
}
Position2::Position2(string gplayer){
    player = gplayer;
}
void Position2::setPosition(){
    Grid ggrid2;
    grid2 = ggrid2;
}
void Position2::deployFleet(Ship* gship){
    positionShip(gship);
}
void Position2::remindRules(int n){
    cout << "A partire dalle coordinate da lei assegnate, la nave si estende per " << n << " caselle nella direzione da lei scelta" <<endl;
}
void Position2::positionShip(Ship* gship){
    int n = gship->getHitbox();
    int x;
    int y;
    Punto p(0,0);
    string direction;
    cout << "Ammiraglio " << player << ", posizioni la sua nave " << gship->getShipName() << ":" << endl;
    remindRules(n);
    do{
        cout << "Scelga le coordinate per inizializzare la nave: " << endl;
        p.set_x();
        p.set_y();
        Tools::printBSNotation(p); 
        direction = Tools::setPositioning();
        if(!Tools::checkPositioning(n,p,direction,grid2)){cout << "Posizionamento richiesto non consentito; riprovare"<<endl;}
    } while(!Tools::checkPositioning(n, p, direction, grid2));
    vector<Punto> positions;
    if(direction == "v"){
        for(int i=0;i<n;i++){
            grid2.Board[p.get_x()][p.get_y() + i] = 1;
            Punto np(p.get_x(), p.get_y() + i);
            positions.push_back(np);
        }
    } else{
        for(int j=0;j<n;j++){
            grid2.Board[p.get_x() + j][p.get_y()] = 1;
             Punto np(p.get_x() + j, p.get_y());
            positions.push_back(np);    
        }
    }
    gship->setPosition(positions);
}     
string Destroyer1::getShipName(){
    return shipName;
}
string Destroyer2::getShipName(){
    return shipName;
}
string Submarine1::getShipName(){
    return shipName;
}
string Submarine2::getShipName(){
    return shipName;
}
string Battleship1::getShipName(){
    return shipName;
}
string Battleship2::getShipName(){
    return shipName;
}
string Carrier1::getShipName(){
    return shipName;
}
string Carrier2::getShipName(){

    return shipName;
}
int Destroyer1::getHitbox(){
    return hitbox;
}
int Destroyer2::getHitbox(){
    return hitbox;
}
int Submarine1::getHitbox(){
    return hitbox;
}
int Submarine2::getHitbox(){
    return hitbox;
}
int Battleship1::getHitbox(){
    return hitbox;
}
int Battleship2::getHitbox(){
    return hitbox;
}
int Carrier1::getHitbox(){
    return hitbox;
}
int Carrier2::getHitbox(){
    return hitbox;
}
int Destroyer1::getHealth(){
    return hitbox - hitpoints;
}
int Submarine1::getHealth(){
    return hitbox - hitpoints;
}
int Battleship1::getHealth(){
    return hitbox - hitpoints;
}
int Carrier1::getHealth(){
    return hitbox - hitpoints;
}
int Destroyer2::getHealth(){
    return hitbox - hitpoints;
}
int Submarine2::getHealth(){
    return hitbox - hitpoints;
}
int Battleship2::getHealth(){
    return hitbox - hitpoints;
}
int Carrier2::getHealth(){

    return hitbox - hitpoints;
}
void Destroyer1::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Submarine1::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Battleship1::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Carrier1::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Destroyer2::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Submarine2::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Battleship2::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
}
void Carrier2::hit(Player* gp){
    hitpoints += 1;
    if(getHealth() ==0){
        isSunk = true;
        gp->shipSunk();
        cout << "Nave nemica affondata!" << endl;
    }
} 
void Game::setGame(){
    Grid grid;
    hitGrid1 = grid;
    Grid ggrid;
    hitGrid2 = ggrid;
}
void Game::gameStart(Player* gp1, Player* gp2, vector<Ship*> ships1, vector<Ship*> ships2, Grid grid1, Grid grid2){
    while(1){
        shoot(gp1, gp2, ships2, grid1, grid2);
        if(gp2->getStatus()){
            cout << "Ammiraglio " << gp1->get_name() << " ottimo lavoro, tutte le navi nemiche sono state affondate!" << endl;
            break;
        }
        shoot(gp2, gp1, ships1, grid1, grid2);
        if(gp1->getStatus()){
            cout << "Ammiraglio " << gp2->get_name() << " ottimo lavoro, tutte le navi nemiche sono state affondate!" << endl; 
            break;
        }    
    }
}
void Game::shoot(Player* tp, Player* ntp, vector<Ship*> ships, Grid grid1, Grid grid2){
    cout << "Ammiraglio " << tp->get_name() << " dichiari il punto da colpire: " << endl;
    Punto np(0,0);
    if(tp->getPlayerTag() == 1){
        do{
            hitGrid1.drawBoard();
            np.set_x();
            np.set_y();
            if(hitGrid1.Board[np.get_x()][np.get_y()] == 2 || hitGrid1.Board[np.get_x()][np.get_y()] == 3){cout << "Ammiraglio, non spari due volte nello stesso punto" << endl;}
        } while(hitGrid1.Board[np.get_x()][np.get_y()] == 2 || hitGrid1.Board[np.get_x()][np.get_y()] == 3);
        if(grid2.Board[np.get_x()][np.get_y()] == 1){
            hitGrid1.Board[np.get_x()][np.get_y()] = 3;
            cout << "Nave nemica colpita!" << endl;
            //Logica per capire cosa è stato colpito e fare l'update dello status navi:
            for(Ship* ship : ships){
                if(ship->isThere(np)){
                    ship->hit(ntp);    
                }
            }
            ntp->checkStatus();
            hitGrid1.drawBoard();
        } else {
            hitGrid1.Board[np.get_x()][np.get_y()] = 2;
            cout << "Nessun obiettivo colpito!" << endl;
            hitGrid1.drawBoard();
        }
    }
    if(tp->getPlayerTag() == 2){
        do{
            hitGrid2.drawBoard();
            np.set_x();
            np.set_y();
            if(hitGrid2.Board[np.get_x()][np.get_y()] == 2 || hitGrid2.Board[np.get_x()][np.get_y()] == 3){cout << "Ammiraglio, non spari due volte nello stesso punto" << endl;}
        } while(hitGrid2.Board[np.get_x()][np.get_y()] == 2 || hitGrid2.Board[np.get_x()][np.get_y()] == 3);
        if(grid1.Board[np.get_x()][np.get_y()] == 1){
            hitGrid2.Board[np.get_x()][np.get_y()] = 3;
            cout << "Nave nemica colpita!" << endl;
            //Logica per capire cosa è stato colpito e fare l'update dello status navi:
            for(Ship* ship : ships){
                if(ship->isThere(np)){
                    ship->hit(ntp);
                }
            }
            ntp->checkStatus();
            hitGrid2.drawBoard();     
        } else {
            hitGrid2.Board[np.get_x()][np.get_y()] = 2;
            cout << "Nessun obiettivo colpito!" << endl;
            hitGrid2.drawBoard();
        }
    }
}