// Абстракция, капсулация, наследяване, полиморфизъм
#ifndef HUMAN_H
#define HUMAN_H
#include<iostream>
#include<string.h>
using namespace std;

class Human
{
    public:
        Human();
        Human(char* name,int power, int loyalty, Human** friends, int crrFr);
        Human(const Human& other);
        Human& operator=(const Human& other);
        virtual ~Human();

        virtual void setName(char* name);
        virtual void setPower(int power);
        virtual void setLoyalty(int loyalty);

        virtual char* getName(){return name;}
        virtual int getPower(){return power;}
        virtual int getLoyalty(){return loyalty;}

        void reducePower();

        virtual char* getSPecialAbility()=0;
        virtual int getGradeRevenge() =0;
        virtual void addFriend(Human* other) ;
        virtual void removeFriend(char* name) ;

        virtual Human* copy() =0;
        virtual char* getType() =0;
    protected:
        int crrFr;
        char* name;
        int power;
        int loyalty;
        Human** friends;

};

#endif // HUMAN_H
