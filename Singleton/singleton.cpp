#include <iostream>

class Logger
{
private:
    static Logger* instance;
    Logger() {
        msgLog="";

    }
    std::string msgLog;

public:

    static Logger* getInstance()
    {
        if(instance==nullptr){
            instance = new Logger();
        }
        return instance;
    }

    void writeLog(std::string msg){
        msgLog+=msg;
    }
    void printLog(){
        std::cout<<msgLog<<std::endl;
    }
};

Logger* Logger::instance = nullptr;


int main(){

    Logger* x = Logger::getInstance();
    Logger* y = Logger::getInstance();

    x->writeLog("I do not know!");
    y->writeLog(" me neither");

    if(x==y){
        std::cout<<"Same address!"<<std::endl;
    }

    x->printLog();




    delete x,y;
    return 0;
}

