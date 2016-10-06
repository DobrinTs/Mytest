#include "Normal_human.h"

Normal_human::Normal_human() : Human(){}
Normal_human::Normal_human(char* name,int power, int loyalty, Human** friends, int crrFr) : Human(name,power,loyalty,friends,crrFr){}
Normal_human::Normal_human(const Normal_human& other) : Human(other){}

Normal_human& Normal_human::operator=(const Normal_human& other){
    if(this!=&other){
        Human::operator=(other);}
    return *this;
}

Normal_human::~Normal_human(){}


char* Normal_human::getSPecialAbility(){ return "none";}
int Normal_human::getGradeRevenge(){
    int sum=0;
    for(int i=0;i<crrFr;i++){
        sum+=friends[i]->getPower();}
    return sum;
}

Human* Normal_human::copy(){
    return new Normal_human(*this);}

char* Normal_human::getType() {return "Normal_human";}

void Normal_human::addFriend(Human* other) {
    if( strcmp( other->getType(), "Normal_human") !=0 ){
        cout<<"This guy is not normal";
        return;
    }
    if(crrFr==loyalty){
        cout<<"Already have max friends.."<<endl;}
    else{
        friends[crrFr]=other;
        friends[crrFr]=friends[crrFr]->copy();
        crrFr++;}
}


void Normal_human::removeFriend(char* name){
    int idx=-1;
    for(int i=0;i<crrFr;i++){
        if(!strcmp(name, friends[i]->getName() )){
            idx=i;
            break;}
    }
    if(idx==-1){
        cout<<"No such friend"<<endl;
        return;}
    for(int i=idx;i<loyalty-1;i++){
        friends[i]=friends[i+1];}
    crrFr--;
}

