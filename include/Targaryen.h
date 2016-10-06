#ifndef TARGARYEN_H
#define TARGARYEN_H
#include "Human.h"

class Targaryen : public Human
{
    public:
        Targaryen();
        Targaryen(char* name,int power, int loyalty, Human** friends, int crrFr, int years);
        Targaryen(const Targaryen& other);
        Targaryen& operator=(const Targaryen& other);
        virtual ~Targaryen();

        int getLoyalty();
        void setLoyalty(int loyalty);

        char* getSPecialAbility();
        int getGradeRevenge();

        Human* copy() ;
        char* getType() ;
    protected:
    private:
        int years;
};

#endif // TARGARYEN_H
