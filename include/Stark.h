#ifndef STARK_H
#define STARK_H
#include "Human.h"

class Stark : public Human
{
    public:
        Stark();
        Stark(char* name,int power, int loyalty, Human** friends, int crrFr, int years);
        Stark(const Stark& other);
        Stark& operator=(const Stark& other);
        virtual ~Stark();

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

#endif // STARK_H
