#include <iostream>

class Channel
{
protected:
    int id;

public:
    Channel(int id_) : id(id_) {};
    virtual void send() = 0;
    virtual ~Channel() = default;
};

class TCPChannel : public Channel
{

public:
    void send()
    {
        std::cout << "TCP Channel in communication" << std::endl;
    }
    TCPChannel() : Channel(1) {};
};

class UDPChannel : public Channel
{
public:
    void send()
    {
        std::cout << "TCP Channel in communication" << std::endl;
    }
    UDPChannel() : Channel(1) {};
};

class ChannelFactory
{

public:
    static Channel* create(){
        return new TCPChannel(); //This is the only place that needs change in case the protocol changes
    }
};


void f()
{
    Channel* c = ChannelFactory::create();
}
void g()
{
    Channel* c = ChannelFactory::create();
}
void h()
{
    Channel* c = ChannelFactory::create();
}

int main()
{
    g();
    h();
    f();
    return 0;
}