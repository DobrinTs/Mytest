#include "Army.h"

Army::Army()
{
    warriors=new Human*[100];
    numWarriors=0;
    leader=new Normal_human();
}

Army::Army(Human** warr , int numWarriors, Human* leader){
    warriors=new Human*[100];
    for(int i=0;i<numWarriors;i++){
        warriors[i]=warr[i];}
    for(int i=0;i<numWarriors;i++){
        warriors[i]=warriors[i]->copy();}
    this->numWarriors=numWarriors;

    this->leader=leader->copy();
}

Army::Army(const Army& other){
    this->warriors=new Human*[100];
    for(int i=0;i<other.numWarriors;i++){
        this->warriors[i]=other.warriors[i];}
    for(int i=0;i<other.numWarriors;i++){
        this->warriors[i]=warriors[i]->copy();}
    this->numWarriors=other.numWarriors;

    this->leader=other.leader->copy();
}

Army& Army::operator=(const Army& other){
    if(this!=&other){
        for(int i=0;i<100;i++){
            delete warriors[i];}
        delete [] warriors;
        delete leader;
        this->warriors=new Human*[100];
        for(int i=0;i<other.numWarriors;i++){
            this->warriors[i]=other.warriors[i];}
        for(int i=0;i<other.numWarriors;i++){
            this->warriors[i]=warriors[i]->copy();}
        this->numWarriors=other.numWarriors;

        this->leader=other.leader->copy();}
    return *this;
}

Army::~Army()
{
    for(int i=0;i<100;i++){
            delete warriors[i];}
    delete [] warriors;
    delete leader;
}


void Army::addWarrior(Human* other){
    if(numWarriors==100){
        cout<<"Already have max warriors.."<<endl;}
    else{
        warriors[numWarriors]=other;
        warriors[numWarriors]=warriors[numWarriors]->copy();
        numWarriors++;}
}


void Army::removeWarrior(char* name){
    int idx=-1;
    for(int i=0;i<numWarriors;i++){
        if(!strcmp(name, warriors[i]->getName() )){
            idx=i;
            break;}
    }
    if(idx==-1){
        cout<<"No such warrior"<<endl;
        return;}
    for(int i=idx;i<numWarriors-1;i++){
        warriors[i]=warriors[i+1];}
    numWarriors--;
}
