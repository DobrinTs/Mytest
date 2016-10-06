#ifndef PAID_ARMY_H
#define PAID_ARMY_H
#include<Army.h>

class Paid_army : public Army
{
    public:
        Paid_army();
        Paid_army(Human** warriors , int numWarriors, Human* leader, int budget);
        Paid_army(const Paid_army& other);
        Paid_army& operator=(const Paid_army& other);
        virtual ~Paid_army();

        void addLeader(Human* other);
        int ArmyGrade();
        bool operator>(Army* other);
    protected:
    private:
        int budget;
        int warr_salary;
};

#endif // PAID_ARMY_H
