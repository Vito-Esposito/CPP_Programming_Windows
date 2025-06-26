#include <iostream>

using namespace std;

template <class dataType>
class node{
private:
    dataType item;
    int counter;
    node<dataType>* next;

public:
    node(dataType val): item(val), counter(0), next(nullptr){}
    void setData(dataType val){
        item= val;
    }
    dataType getData(){
        return item;
    }
    void inCounter(){
        counter+=1;
    }
    int getCounter(){
        return counter;
    }
    void decCounter(){
        counter-=1;
    }
    void setNext(node<dataType>*nodosucc){
        next= nodosucc;
    }
    node<dataType>* getNext(){
        return next;
    }
};

template <class dataType>
class list{
private:
    node<dataType>* head;

public:
    list(): head(nullptr){}
    ~list(){
        node<dataType> *tmp;

        while(head != nullptr){
            tmp= head;
            head= head->getNext();
            tmp->setNext(nullptr);
            delete tmp;
        }
    }
    void insert(dataType x){
        node<dataType>* newNode, *tmp;

        if(isEmpty()){
            newNode= new node<dataType>(x);
            head= newNode;
            return;
        }
        tmp= head;
        do{
            if(x == tmp->getData()){
                tmp->inCounter();
                return;
            }
            if(tmp->getNext() == nullptr)
                break;
            tmp= tmp->getNext();
        }while(tmp->getNext()!=nullptr);

        newNode= new node<dataType>(x);
        tmp->setNext(newNode);
    }
    dataType extract(){
        node<dataType>* tmp;
        dataType item;
        tmp=head;

        if(isEmpty()){
                cout << "Lista vuota!" << endl;
            return dataType();
        }

        if(tmp->getCounter() > 0){
            tmp->decCounter();
            return tmp->getData();
        }
        else{
            item = tmp->getData();
            head= tmp->getNext();
            tmp->setNext(nullptr);
            delete tmp;
        return item;
        }
    }
    bool isEmpty(){
        return head==nullptr;
    }


};

int main()
{
    list<int> lista;
    int item;

    lista.insert(10);
    lista.insert(10);
    lista.insert(20);
    lista.insert(30);
    lista.extract();
    lista.extract();

    while(!lista.isEmpty()){
        item= lista.extract();
        cout << item << " ";
    }

    return 0;
}
