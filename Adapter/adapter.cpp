#include <iostream>

class ProjectorSamgung 
{
public:
    void turnOn()
    {
        std::cout << "Samsung projector turned on.\n"
                  << std::endl;
    };
};

class ProjetorLG 
{
public:
    void enable(int timer)
    {
        if (timer == 0)
        {
            std::cout << "LG projector turned on immediately.\n";
        }
        else
            std::cout << "LG projector will turn on in " << timer << " minutes.\n";
    }
};

class Projector
{
private:
public:
    virtual void turnOn() = 0;
    virtual ~Projector() = default;
};

class AdapterSamsungProjector : public Projector{
    private:
        ProjectorSamgung* projector;
    public:
        AdapterSamsungProjector(ProjectorSamgung* p): projector(p){};

        void turnOn() override{
            projector->turnOn();
        }

};

class AdapterLG : public Projector{
    private:
        ProjetorLG* projector;
    public:
        void turnOn()override{
            projector->enable(0);
        }
        AdapterLG(ProjetorLG* p):projector(p){};
};

class ProjectorsController{
    private:

    public:
        void init(Projector* p){
            p->turnOn();
        }
};

int main()
{

    ProjectorSamgung* x =  new ProjectorSamgung();
    ProjetorLG* y = new ProjetorLG();
    
    AdapterSamsungProjector* z = new AdapterSamsungProjector(x);
    AdapterLG* u = new AdapterLG(y);




    ProjectorsController* controller = new ProjectorsController();
    controller->init(z);

    
    



    return 0;
}