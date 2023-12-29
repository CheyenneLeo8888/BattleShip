#include "battleshippvpdeclare.h"
#include <iostream>
#include <conio.h>
using namespace std;
//Milton Bradley's Version of Battleship (1990) 
/*Le navi sono rappresentate tramite 1, i miss sono rappresentati da 2, le navi colpite da 3*/
//Da implementare: Cambiare da 2,3 a O,X
//Da implementare: introdurre notazione da battaglia navale
int main(){
    system("cls");
    /*Introduco il gioco ai giocatori*/
    Greet::introduceGame();
    Greet::introduceGameRules();
    Player p1(1);
    Player p2(2);
    Player* ptr_p1 = &p1;
    Player* ptr_p2 = &p2;
    string cpt1Name = p1.get_name();
    string cpt2Name = p2.get_name();
    /*Fase di posizionamento navi*/
    Greet::introducePositioningPhase();
    //Istanzio le due classi di posizione
    Position1 pos1(cpt1Name);
    Position2 pos2(cpt2Name);
    pos1.setPosition();
    pos2.setPosition();
    //Istanzio tutte le navi e i loro puntatori
    Destroyer1 destroyer1;
    Submarine1 submarine1;
    Battleship1 battleship1;
    Carrier1 carrier1;
    Ship* ptr_destroyer1 = &destroyer1;
    Ship* ptr_submarine1 = &submarine1;
    Ship* ptr_battleship1 = &battleship1;
    Ship* ptr_carrier1 = &carrier1;
    Destroyer2 destroyer2;
    Submarine2 submarine2;
    Battleship2 battleship2;
    Carrier2 carrier2;
    Ship* ptr_destroyer2 = &destroyer2;
    Ship* ptr_submarine2 = &submarine2;
    Ship* ptr_battleship2 = &battleship2;
    Ship* ptr_carrier2 = &carrier2;
    //Giocatore 1 posiziona le navi
    pos1.deployFleet(ptr_destroyer1);
    pos1.grid1.drawBoard();
    pos1.deployFleet(ptr_submarine1);
    pos1.grid1.drawBoard();
    pos1.deployFleet(ptr_battleship1);
    pos1.grid1.drawBoard();
    pos1.deployFleet(ptr_carrier1);
    pos1.grid1.drawBoard();
    vector<Ship*> shipsP1;
    shipsP1.push_back(ptr_destroyer1);
    shipsP1.push_back(ptr_submarine1);
    shipsP1.push_back(ptr_battleship1);
    shipsP1.push_back(ptr_carrier1);
    cout << "Schieramento completato, premere qualunque tasto per continuare" << endl;
    getch();
    system("cls");
    Greet::positioningIntermezzo(cpt1Name, cpt2Name);
    //Giocatore 2 posiziona le navi
    pos2.deployFleet(ptr_destroyer2);
    pos2.grid2.drawBoard();
    pos2.deployFleet(ptr_submarine2);
    pos2.grid2.drawBoard();
    pos2.deployFleet(ptr_battleship2);
    pos2.grid2.drawBoard();
    pos2.deployFleet(ptr_carrier2);
    pos2.grid2.drawBoard();
    vector<Ship*> shipsP2;
    shipsP2.push_back(ptr_destroyer2);
    shipsP2.push_back(ptr_submarine2);
    shipsP2.push_back(ptr_battleship2);
    shipsP2.push_back(ptr_carrier2);
    /*Inizio gioco*/
    system("cls");
    Greet::introduceMainGame();
    Game game;
    game.setGame();
    game.gameStart(ptr_p1, ptr_p2, shipsP1, shipsP2, pos1.grid1, pos2.grid2);
    cout << "Game Over!" << endl;
    return 0;
}