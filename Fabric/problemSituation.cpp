#include <iostream>

class TCPChannel
{
private:
    int id;

public:
    void send()
    {
        std::cout << "TCP Channel in communication" << std::endl;
    }
    TCPChannel() : id(1) {};
};

void f()
{
    TCPChannel *c = new TCPChannel();
    c->send();
    delete c;
}
void g()
{
    TCPChannel *c = new TCPChannel();
    c->send();
    delete c;
}
void h()
{
    TCPChannel *c = new TCPChannel();
    c->send();
    delete c;
}

int main()
{
    g();
    h();
    f();
    return 0;
}