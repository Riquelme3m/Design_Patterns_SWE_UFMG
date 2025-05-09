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
        std::cout << "UDP Channel in communication" << std::endl;
    }
    UDPChannel() : Channel(1) {};
};

class ChannelFactory
{
    public:
    virtual Channel* createChannel() = 0;

};

class TCPChannelFactory:public ChannelFactory{
    public:
        Channel* createChannel(){
            return new TCPChannel();
        }
};

class UDPChannelFactory:public ChannelFactory{
    public:
        Channel* createChannel(){
            return new UDPChannel();
        }
};


void f(ChannelFactory* p){
    Channel* c = p->createChannel();
    c->send();
    delete c;
}



int main()
{
    ChannelFactory* mychannel = new UDPChannelFactory();
    f(mychannel);
    return 0;
}