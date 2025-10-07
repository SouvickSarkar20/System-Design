#include<iostream>
using namespace std;

class vechicle{
    protected workshop workshop1;
    protected workshop workshop2;

    protected vechicle(workshop w1,workshop w2){
        this->workshop1 = w1;
        this->workshop2 = w2;
    }

    abstract public void manufacture();
}

//now we will have two classes car and bike 
//car and bike will extend this vehicle class
//they will define their own workshop and manufacture method

class Car extends Vehicle {
    public Car(Workshop workShop1, Workshop workShop2)
    {
        super(workShop1, workShop2);
    }

    @Override
    public void manufacture()
    {
        System.out.print("Car ");
        workShop1.work();
        workShop2.work();
    }
}

class Bike extends Vehicle {
    public Bike(Workshop workShop1, Workshop workShop2)
    {
        super(workShop1, workShop2);
    }

    @Override
    public void manufacture()
    {
        System.out.print("Bike ");
        workShop1.work();
        workShop2.work();
    }
}

//we define a workshop interface now
interface workshop{
    abstract public void work();
}

class produce implements workshop{
    public void work() override{
      cout<<"Production";
    }
}

class assemble implements workshop{
    public void work() override{
        cout<<"Assembled";
    }
}

int main(){

    //we need two objects one for production workshop and another for assemble workshop
    workshop w1 = new produce;
    workshop w2 = new assemble;

    //now we need to make a object of car
    vehicle car = new Car(w1,w2);
    car->manufacture();

    //same can be done for bike

}