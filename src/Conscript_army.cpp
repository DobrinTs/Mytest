#include "Conscript_army.h"

Conscript_army::Conscript_army() : Army()
{

}

Conscript_army::Conscript_army(Human** warriors , int numWarriors, Human* leader) : Army(warriors,numWarriors,leader){}

Conscript_army::Conscript_army(const Conscript_army& other) : Army(other){}

Conscript_army& Conscript_army::operator=(const Conscript_army& other){
    if(this!=&other){
        Army::operator=(other);
    }
    return *this;
}

Conscript_army::~Conscript_army(){}

void Conscript_army::addLeader(Human* other) {
   /* if( strcmp("Normal_human", other->getType())!=0 &&  strcmp("Targaryen", other->getType())!=0 ){
        cout<<"Invalid leader type"<<endl;
        return;
    }
    else{*/
        delete leader;
        leader=other->copy();
}


int Conscript_army::ArmyGrade() {
    int sumP=0 , sumL=0, total=0;
    for(int i=0;i<numWarriors;i++){
        sumP+=warriors[i]->getPower();
        sumL+=warriors[i]->getLoyalty();}
    sumP+=leader->getPower();

    total = (leader->getLoyalty() * sumL) + sumP;
    return total;
}

bool Conscript_army::operator>(Army* other){
    if( this->ArmyGrade() > other->ArmyGrade() )
        return 1;
    return 0;
}


