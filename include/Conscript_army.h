#ifndef CONSCRIPT_ARMY_H
#define CONSCRIPT_ARMY_H
#include<Army.h>

class Conscript_army : public Army
{
    public:
        Conscript_army();
        Conscript_army(Human** warriors , int numWarriors, Human* leader);
        Conscript_army(const Conscript_army& other);
        Conscript_army& operator=(const Conscript_army& other);
        virtual ~Conscript_army();

        void addLeader(Human* other);
        int ArmyGrade();
        bool operator>(Army* other);
    protected:
    private:
};

#endif // CONSCRIPT_ARMY_H
