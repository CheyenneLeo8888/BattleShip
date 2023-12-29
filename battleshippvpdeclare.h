#ifndef BATTLESHIPPVPDECLARE_H
#define BATTLESHIPPVPDECLARE_H
#include <string>
#include <vector>
class Greet{
    public:
        static void introduceGame();
        static void introduceGameRules();
        static void introducePositioningPhase();
        static void positioningIntermezzo(std::string cap1Name, std::string cap2Name);
        static void introduceMainGame();
};
class Punto{
    public: 
        Punto(int gx, int gy );
        void set_x();
        void set_y();
        int get_x();
        int get_y();
    private:
        int x;
        int y;    
};
class Player{
    public:
        Player(int n);
        std::string get_name();
        int getPlayerTag();
        void shipSunk();
        bool getStatus();
        void checkStatus();
        int getRemainingShips();
    private:
        void setStatus();
        int playerTag;
        std::string name;
        int remainingShips= 4;
        bool isDefeated = false;

};
class Grid{
    public:
        Grid();
        void drawBoard();
        int Board[10][10];
    private:
        int player;
};
class Tools{
    public:
        static bool checkPositioning(int n, Punto gp, std::string direction, Grid gg);
        static std::string setPositioning();
        static void printBSNotation(Punto gp);
};
class Ship{
    public:
        virtual void setPosition(std::vector<Punto> gpositions);
        virtual void getPosition();
        virtual std::string getShipName() = 0;
        virtual int getHealth() = 0;
        virtual int getHitbox() = 0;
        virtual void setHitpoints(int ghitp);
        virtual int getHitpoints();
        virtual void setHitbox(int n);
        virtual void hit(Player* gp) = 0;
        virtual bool isThere(Punto gp);
        virtual bool getIsSunk();
    protected:
        std::vector<Punto> location;
        std::string shipName;
        bool isSunk=false;
        int hitbox; //Salute iniziale
        int hitpoints = 0; //Danni

};
class Position1{
    public:
        Position1(std::string gplayer);
        void setPosition();
        void deployFleet(Ship* gship);
        Grid grid1;
    private:
        std::string player;
        void remindRules(int n);
        void positionShip(Ship* gship);    
};
class Position2{
    public:
        Position2(std::string gplayer);
        void setPosition();
        void deployFleet(Ship* gship);
        Grid grid2;
    private:
        std::string player;
        void remindRules(int n);
        void positionShip(Ship* gship);    
};
class Destroyer1 : public Ship{
    public:
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private: 
        std::string shipName = "destroyer";
        int hitbox = 2;
        int player = 1;
        
};
class Submarine1 : public Ship{
    public: 
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private:
        std::string shipName = "submarine";
        int hitbox = 3;
        int player = 1;
};
class Battleship1 : public Ship{
    public: 
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private:
        std::string shipName = "battleship";
        int hitbox = 4;
        int player = 1;
};
class Carrier1 : public Ship{
    public: 
       std::string getShipName();
       int getHitbox();
       int getHealth();
       void hit(Player* gp);
    private:
        std::string shipName = "carrier";
        int hitbox = 5;
        int player = 1;
};
class Destroyer2 : public Ship{
    public:
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private: 
        std::string shipName = "destroyer";
        int hitbox = 2;
        int player = 2;
        
};
class Submarine2 : public Ship{
    public: 
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private:
        std::string shipName = "submarine";
        int hitbox = 3;
        int player = 2;
};
class Battleship2 : public Ship{
    public: 
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private:
        std::string shipName = "battleship";
        int hitbox = 4;
        int player = 2;
};
class Carrier2 : public Ship{
    public: 
        std::string getShipName();
        int getHitbox();
        int getHealth();
        void hit(Player* gp);
    private:
        std::string shipName = "carrier";
        int hitbox = 5;
        int player = 2;
};
class Game{
    public: 
        void setGame();
        void gameStart(Player* gp1, Player* gp2, std::vector<Ship*> ships1, std::vector<Ship*> ships2, Grid grid1, Grid grid2);
        void shoot(Player* tp, Player* ntp, std::vector<Ship*> ships, Grid grid1, Grid grid2);   
    private:
        Grid hitGrid1;
        Grid hitGrid2;
};
#endif