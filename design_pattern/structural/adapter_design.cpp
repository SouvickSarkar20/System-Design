#include<iostream>
using namespace std;

class Printer{
    public:
    virtual void print() = 0;
}

class legacyPrinter : public Printer{
    public:
      void print() override{
        cout<<"Legacy printer printing";
      }
}

class PrinterAdapter{
    private:
     legacyPrinter* printer;
    
    public:
     PrinterAdapter(Printer* printer){
        this->printer = printer;
     }

     void print(){
        printer->print();
     }
}

void client(Printer* printer){
  printer->print();
}

int main(){
    PrinterAdapter* adapter;
    client(adapter);
}