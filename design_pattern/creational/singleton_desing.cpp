#include <iostream>
#include <mutex>
#include <string>
using namespace std;

class Logger{
    private:
     static *Logger instance;
     static mutex mtc;
     string loglevel;

     Logger(){
        loglevel = "INFO"
        cout<<"Logger initialized"<<endl;
     }  

     //delete any copy and assignment operator
     Logger(const Logger&) = delete;
     Logger& operator =(const Logger&) = delete;

    public:
     static Logger* getInstance(){
        if(instance == nullptr){
            lock_guard<mutex> lock(mtx);
            if(instance == nullptr){
                instance = new Logger();
            }
        }

        return instance;
     }

     void setLoglevel(const string& lvl){
        loglevel = lvl;
     }

     void log(const string& msg){
        cout<<msg<<endl;
     }
 
}

Logger* Logger :: instance = nullptr;
mutex Logger :: mtx;

int main(){
    Logger* logger1 = logger::getInstance();
    logger1->log("start");
}