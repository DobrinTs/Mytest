#include "Human.h"

Human::Human() : power(0) , loyalty(1)
{
    this->name=new char[5];
    strcpy(this->name,"none");
    friends= new Human*[loyalty];
    crrFr=0;

}

/*Human* Human::copy(){
    return new Human(*this);
}*/

Human::Human(char* name,int power, int loyalty, Human** fr, int crrFr) : power(power) , loyalty(loyalty){
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
    friends=new Human*[loyalty];
    for(int i=0;i<loyalty;i++){
        friends[i]=fr[i];}
    for(int i=0;i<loyalty;i++){
        friends[i]=friends[i]->copy();}
    this->crrFr=crrFr;
}

Human::Human(const Human& other){
    this->name=new char[strlen(other.name)+1];
    strcpy(this->name,other.name);
    this->friends=new Human*[loyalty];
    for(int i=0;i<loyalty;i++){
        friends[i]=other.friends[i];}
    for(int i=0;i<loyalty;i++){
        friends[i]=friends[i]->copy();}
    this->crrFr=other.crrFr;
}

Human& Human::operator=(const Human& other){
    if(this!=&other){
        delete [] this->name;
        for(int i=0;i<loyalty;i++){
            delete this->friends[i];}
        delete [] friends;
        this->name=new char[strlen(other.name)+1];
        strcpy(this->name,other.name);
        friends=new Human*[loyalty];
        for(int i=0;i<loyalty;i++){
            friends[i]=other.friends[i];}
        for(int i=0;i<loyalty;i++){
            friends[i]=friends[i]->copy();}
        this->crrFr=other.crrFr;
    }
    return *this;
}

Human::~Human()
{
    delete [] name;
    for(int i=0;i<loyalty;i++){
        delete friends[i];}
    delete [] friends;

}


void Human::setName(char* name)
{
    delete [] this->name;
    this->name=new char[strlen(name)+1];
    strcpy(this->name,name);
}
void Human::setPower(int power){
    if(power<0)
        cout<<"Incorrect input"<<endl;
    else
        this->power=power;
}
void Human::setLoyalty(int loyalty){this->loyalty=loyalty;}

void Human::reducePower(){
    if(power==0){
        cout<<"Can't reduce power; already 0"<<endl;}
    else{
        power--;}
}

void Human::addFriend(Human* other){
    if(crrFr==loyalty){
        cout<<"Already have max friends.."<<endl;}
    else{
        friends[crrFr]=other;
        friends[crrFr]=friends[crrFr]->copy();
        crrFr++;}
}

void Human::removeFriend(char* name){
    int idx=-1;
    for(int i=0;i<crrFr;i++){
        if(!strcmp(name, friends[i]->name)){
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
