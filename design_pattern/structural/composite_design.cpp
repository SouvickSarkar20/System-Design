#include <iostream>
using namespace std;

//first make the task abstraction
class Task{
    public:
     virtual string getTitle() const = 0;
     virtual void setTitle(string title) const = 0;
     virtual void display() const = 0;
}

//make a simple task
class simple_task{
    private:
     string title;
    
    public:
     simple_task(string title){
        this->title = title;
     }

     string getTitle() const override{
        return this->title;
     }

     void setTitle(string title) const override{
        this->title = title;
     }

     void display() const override{
        cout<<"title"<<endl;
     }
}

//make a group of task
class group_task{

    string title;
    vector<Task*> tasks;

    public:
     group_task(string name){
        this->title = name;
     }

     string getTitle() const override{
        return this->title;
     }

     void setTitle(string title) const override{
        this->title = title;
     }

     void add_task(Task* t1){
        tasks.push_back(t1);
     }

     void display() const override{
        for(auto t :  tasks){
            t->display();
        }
     }
}

int main(){

    //make a ind task 
    Task t1 = new simple_task("wake up");
    Task t2 = new simple_task("Have the breakfast");

    //make a group of task(composite)
    Task morning_routine = new group_task("morning_routine");
    morning_routine->add(t1);
    morning_routine->add(t2);

    //goal here is that same function should work on both individual and composite class
    t1->setTitle("Sleep");
    t1->dispaly();

    morning_routine->setTitle("Night Routine");
    morning_routine->display();

}