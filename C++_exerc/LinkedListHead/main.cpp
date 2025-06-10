#include <iostream>

using namespace std;

// Nodo
class Nodo{
        protected:
                int valore;
                Nodo* next;
        public:
                Nodo(int item){
                    valore= item;
                }
                ~Nodo(){}
                void setValore(int item){
                    valore= item;
                }
                int getValore() const{
                    return valore;
                }
                void setNext(Nodo* newnodo){
                    next= newnodo;
                }
                Nodo* getNext() const{
                    return next;
                }
};

// Lista con solo head ed una direzione (simile a stack)
class List{
        protected:
                Nodo* head;
        public:
            List(): head(nullptr){};
            bool isEmpty(){
                return head == nullptr;
            }
            virtual bool insertAtHead(int item){
                Nodo* tmp= new Nodo(item);
                tmp->setNext(head);
                head= tmp;

                return true;
            }
            virtual bool deleteAtHead(int& item){
                if(isEmpty())
                    return false;

                Nodo* tmp= head;
                head= head->getNext();
                item= tmp->getValore();
                delete tmp;
                return true;
            }
            virtual ~List(){
                Nodo* current;
                while(head != nullptr){
                    current= head;
                    head= head->getNext();
                    delete current;
                }
            }
            void print() const {
                Nodo* current= head;
                while (current != nullptr) {
                    cout << current->getValore() << " ";
                    current = current->getNext();
                }
                std::cout << std::endl;
            }
};

// Stack di dimensione statica
class Stack{
    protected:
        int* stack;
        int size;
        int top;
    public:
        Stack(int size){
            this->size= size;
            stack= new int[size];
            top= -1;
        }
        ~Stack(){
            delete []stack;
        }
        bool isEmpty() const{
            return top == -1;
        }
        bool isFull(){
            return top == size-1;
        }
        Stack* push(int item){
            if(isFull())
                    cout << "Stack pieno" << endl;
            else
                stack[++top]= item;

            return this;
        }
        int pop(){
            int item;

            if(isEmpty())
                    cout << "Stack vuoto" << endl;
            else{
                item= stack[top--];
                return item;
            }
        }
};

class FrontBackList: public List{
                                protected:
                                    Nodo* back;
                                public:
                                    FrontBackList(): back(nullptr){}
                                    virtual ~FrontBackList() {}
                                    bool insertAtHead(int item) override{
                                        if(isEmpty()){
                                            head=back= new Nodo(item);
                                            return true;
                                        }
                                        return List::insertAtHead(item);
                                    }
                                    bool deleteAtHead(int &item) override{
                                        Nodo* tmp;

                                        if(isEmpty())
                                            return false;
                                        if(head==back){
                                                tmp= head;
                                                head=back=nullptr;
                                                delete tmp;
                                                return true;
                                        }
                                        else
                                            return List::deleteAtHead(item);
                                    }
                                    virtual bool insertAtBack(int item){
                                        Nodo* tmp= new Nodo(item);
                                        if(isEmpty()){
                                            head=back=tmp;
                                            return true;
                                        }
                                        back->setNext(tmp);
                                        back= tmp;
                                        return true;
                                    }
                                    bool removeFromBack(int &item){
                                        Nodo *tmp, *current;
                                        if(isEmpty())
                                            return false;
                                        tmp= back;
                                        if(head==back) {
                                            head=back=nullptr;
                                        }
                                        else{
                                            current=head;
                                            while(current->getNext()!= back)
                                                current=current->getNext();
                                            back= current;
                                            current->setNext(nullptr);
                                        }
                                        item=tmp->getValore();
                                        delete tmp;
                                        return true;
                                    }









};


int main()
{
    List lista;
    int item;

    lista.insertAtHead(3);
    lista.insertAtHead(5);
    lista.insertAtHead(11);
    cout << "Lista:" << endl;

    lista.print();

    item= lista.deleteAtHead(item);

    lista.print();

    return 0;
}
