#include "Targaryen.h"

Targaryen::Targaryen() : Human(){years=0;}

Targaryen::~Targaryen(){}

Targaryen::Targaryen(char* name,int power, int loyalty, Human** friends, int crrFr, int years) : Human(name,power,loyalty,friends,crrFr) , years(years){}

Targaryen::Targaryen(const Targaryen& other) : Human(other) , years(other.years){}

Targaryen& Targaryen::operator=(const Targaryen& other){
    if(this!=&other){
        Human::operator=(other);
        years=other.years;
    }
    return *this;
}

int Targaryen::getLoyalty(){
    return loyalty+years;}

void Targaryen::setLoyalty(int loyalty){
    cout<<"YOU HAVE NO POWER HERE!!"<<endl;
    return;
}

char* Targaryen::getSPecialAbility(){
    return "fire";}

int Targaryen::getGradeRevenge(){
    int sumP=0;
    for(int i=0;i<crrFr;i++){
        sumP+=friends[i]->getPower();}
    return sumP * 2;
}

Human* Targaryen::copy(){
    return new Targaryen(*this);}

char* Targaryen::getType() {return "Targaryen";}
