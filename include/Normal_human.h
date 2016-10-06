#ifndef NORMAL_HUMAN_H
#define NORMAL_HUMAN_H
#include "Human.h"

class Normal_human : public Human
{
    public:
        Normal_human();
        Normal_human(char* name,int power, int loyalty, Human** friends, int crrFr);
        Normal_human(const Normal_human& other);
        Normal_human& operator=(const Normal_human& other);
        virtual ~Normal_human();

         char* getSPecialAbility();
         int getGradeRevenge() ;
         void addFriend(Human* other) ;
         void removeFriend(char* name) ;

         Human* copy() ;
         char* getType() ;
    protected:
    private:
};

#endif // NORMAL_HUMAN_H
