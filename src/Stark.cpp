#include "Stark.h"

Stark::Stark() : Human(){years=0;}

Stark::~Stark(){}

Stark::Stark(char* name,int power, int loyalty, Human** friends, int crrFr, int years) : Human(name,power,loyalty,friends,crrFr) , years(years){}

Stark::Stark(const Stark& other) : Human(other) , years(other.years){}

Stark& Stark::operator=(const Stark& other){
    if(this!=&other){
        Human::operator=(other);
        years=other.years;
    }
    return *this;
}

int Stark::getLoyalty(){
    return loyalty+crrFr;}

void Stark::setLoyalty(int loyalty){
    int temp = loyalty - crrFr;
    if(temp < 0)
        this->loyalty = 0;
    else
        this->loyalty = temp;
}

char* Stark::getSPecialAbility(){
    return "ice";}

int Stark::getGradeRevenge(){
    int sumP=0;
    for(int i=0;i<crrFr;i++){
        if( !strcmp( friends[i]->getType(), "Targaryen") ){
            sumP+= 2* friends[i]->getPower();}
        if( !strcmp( friends[i]->getType(), "Stark") ){
            sumP+= 3* friends[i]->getPower();}
        if( !strcmp( friends[i]->getType(), "Normal_human") ){
            sumP+= 2* friends[i]->getPower();}

    }
    return sumP;
}

Human* Stark::copy(){
    return new Stark(*this);}

char* Stark::getType() {return "Stark";}
