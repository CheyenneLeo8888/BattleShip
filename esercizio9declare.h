#ifndef ESERCIZIO9DECLARE_H
#define ESERCIZIO9DECLARE_H
#include <vector>
#include <string>
//Class ArmyFactory -- factory astratta
class ArmyFactory{
    public:
        ArmyFactory(int carri, int battaglioni);
        ~ArmyFactory();
        virtual unit *createUnit() const = 0; 
};
//Class GermanFactory -- factory concreta
class GermanFactory : public ArmyFactory{
    public:
        GermanFactory();
        ~GermanFactory();
        virtual unit *createUnit() const; 
        int sizeUnit() const;
        std::vector<unit*>::const_iterator beginUnit() const;
        std::vector<unit*>::const_iterator endUnit() const;
        std::vector<unit*> getArmy() const;
};
//Class RussianFactory -- factory concreta
class RussianFactory : public ArmyFactory{
    public:
        RussianFactory();
        ~RussianFactory();
        virtual unit *createUnit() const; 
        int sizeUnit() const;
        std::vector<unit*>::const_iterator beginUnit() const;
        std::vector<unit*>::const_iterator endUnit() const;
        std::vector<unit*> getArmy() const;
};
//Classe unit -- prodotto astratto 
class unit {
    public:
        virtual ~unit(){};
        virtual void move() = 0;
        virtual void fight() = 0;
        virtual std::string getName() = 0;
    protected:
        const std::string name;
};
//Classe Tank -- prodotto astratto figlio
class Tank : public unit{
    public:
        virtual ~Tank(){};
        virtual void move()  = 0;
        virtual void fight()  = 0;
        virtual std::string getName() = 0;
    protected:
        const std::string name;
};
//Classe Infantry -- prodotto astratto figlio
class Infantry : public unit{
    public:
        virtual ~Infantry(){};
        virtual void move() = 0;
        virtual void fight() = 0;
        virtual std::string getName() = 0;
    protected:
        const std::string name;
};
//Classe Tiger -- prodotto concreto
class Tiger : public Tank{
    public:
        Tiger();
        virtual void move();
        virtual void fight();
        virtual std::string getName();
    private:
        const std::string name = "Tiger";
};
//Classe T34 -- prodotto concreto
class T34 : public Tank{
    public:
        T34();
        virtual void move();
        virtual void fight();
        virtual std::string getName();
    private:
        const std::string name = "T34";
};
//Classe GermanInfanty -- prodotto astratto figlio
class GermanInfantry : public Infantry{
    public:
        GermanInfantry();
        virtual void move();
        virtual void fight();
        virtual std::string getName();
    private:
        std::string name = "German Infantry Battalion";
};
//Classe RussianInfanty -- prodotto astratto figlio
class RussianInfantry : public Infantry{
    public:
        RussianInfantry();
        virtual void move();
        virtual void fight();
        virtual std::string getName();
    private:
        std::string name = "Russian Infantry Battalion";
};
//Classe Cliente che si occupa di creare la battaglia
class Battle {

public:
 Battle(ArmyFactory*, ArmyFactory*);
 ~Battle();
 void playBattle();

private:
 ArmyFactory* fp;
 ArmyFactory* sp;
 std::vector<unit*> fpArmy ;
 std::vector<unit*> spArmy ;

};

#endif