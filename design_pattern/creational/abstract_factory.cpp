#include <iostream>
using namespace std

class Button{
    public:
      virtual void paint() = 0;
}

class CheckBox{
    public:
      virtual void paint() = 0;
}

class WinButton : public Button {
    public:
      void create() override {
        cout<< "Windows button created";
      }
}

class MacButton : public Button {
    public:
      void create() override {
        cout<< "Mac button created";
      }
}

class winCheckBox : public CheckBox{
    public:
     void create() override {
        cout<<"Windows checkbox created";
     }
}

class MacCheckBox : public CheckBox{
    public:
     void create() override {
        cout<<"Mac checkbox created";
     }
}

class Factory{
    virtual Button* createButton() = 0;
    virtual CheckBox* createCheckBox() = 0;
}

class winFactory : public Factory{
    public:
      Button* createButton() override{
        return new WinButton();
      }

      CheckBox* createCheckBox() override {
        CheckBox* createCheckBox() override{
            return new WinChecKBox();
        }
      }
}

class MacFactory : public Factory{
    public:
      Button* createButton() override{
        return new MacButton();
      }

      CheckBox* createCheckBox() override {
        CheckBox* createCheckBox() override{
            return new MacChecKBox();
        }
      }
}

int main(){

    Factory* factory;
    factory = new WinFactory();
    Button* b1 = factory->createButton();
    CheckBox* c1 = factory->createCheckBox();

    b1->paint();
    c1->paint();

    delete b1;
    delet1 c1;
}



