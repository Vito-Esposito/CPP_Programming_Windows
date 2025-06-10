#include <iostream>

using namespace std;

class Nodo{
    public:
        int valore;
        Nodo* next;
        Nodo* prev;

    public:
        Nodo(int item): valore(item), next(nullptr), prev(nullptr){}
};

class ListaDP{
            protected:
                Nodo* head;
                Nodo* tail;
            public:
                ListaDP(): head(nullptr), tail(nullptr){}
                bool isEmpty()const{
                    return head==nullptr;
                }

                virtual ~ListaDP(){
                    Nodo* tmp;

                    while(head != nullptr){
                        tmp= head;
                        head= head->next;
                        delete tmp;
                    }
                }

                virtual ListaDP* insertback(int item){
                    Nodo* tmp= new Nodo(item);

                    if(isEmpty())
                        head=tail=tmp;
                    else{
                        tmp->prev= tail;
                        tail->next= tmp;
                        tail= tmp;
                    }
                    return this;
                }

                ListaDP* removefront(int &item) { // from front
                    Nodo *tmp, *newFront;

                    if(isEmpty()) {
                        return nullptr;
                    }

                    tmp= head;
                    if(head==tail){
                        head=tail=nullptr;
                    }else{
                        newFront= head->next;
                        newFront->prev= nullptr;
                        head= newFront;
                    }

                    item= tmp->valore;
                    delete tmp;

                    return this;
                }

                void stampa()const{
                    Nodo* current= head;

                    while(current != nullptr){
                        cout << current->valore << endl;
                        current= current->next;
                    }
                }
};

int main()
{
    int item;
    ListaDP list;

    list.insertback(2);
    list.insertback(10);
    list.insertback(13);
    list.insertback(9);
    list.stampa();
    list.removefront(item);
    cout << "rimosso: " << item << endl;
    list.stampa();

    return 0;
}
