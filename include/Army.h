#ifndef ARMY_H
#define ARMY_H
#include<Human.h>
#include<Normal_human.h>

class Army
{
    public:
        Army();
        Army(Human** warriors , int numWarriors, Human* leader);
        Army(const Army& other);
        Army& operator=(const Army& other);
        virtual ~Army();

        void addWarrior(Human* other);
        void removeWarrior(char* name);

        virtual void addLeader(Human* other) =0;
        virtual int ArmyGrade() =0;

    protected:
        Human** warriors;
        int numWarriors;
        Human* leader;
};

#endif // ARMY_H
