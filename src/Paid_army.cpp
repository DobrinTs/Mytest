#include "Paid_army.h"

Paid_army::Paid_army() : Army()
{
    budget=100;
    warr_salary = ( (budget *8)/10 ) / numWarriors;
}

Paid_army::Paid_army(Human** warriors , int numWarriors, Human* leader, int budget) : Army(warriors,numWarriors,leader){
    this->budget=budget;
    warr_salary = ( (budget *8)/10 ) / numWarriors;
}

Paid_army::Paid_army(const Paid_army& other) : Army(other){
    budget=other.budget;
    warr_salary=other.warr_salary;
}

Paid_army& Paid_army::operator=(const Paid_army& other){
    if(this!=&other){
        Army::operator=(other);
        budget=other.budget;
        warr_salary=other.warr_salary;
    }
    return *this;
}

Paid_army::~Paid_army(){}

void Paid_army::addLeader(Human* other) {
    if( strcmp("Normal_human", other->getType())!=0 &&  strcmp("Targaryen", other->getType())!=0 ){
        cout<<"Invalid leader type"<<endl;
        return;
    }
    else{
        delete leader;
        leader=other->copy();}
}

int Paid_army::ArmyGrade() {
    int sumP=0 , sumL=0, total=0, sumSal=0;
    for(int i=0;i<numWarriors;i++){
        sumP+=warriors[i]->getPower();
        sumL+=warriors[i]->getLoyalty();
        sumSal+=warr_salary;}
    sumP+=leader->getPower();

    total = (leader->getLoyalty() * sumSal) + sumP;
    return total;
}

bool Paid_army::operator>(Army* other){
    if( this->ArmyGrade() > other->ArmyGrade() )
        return 1;
    return 0;
}





