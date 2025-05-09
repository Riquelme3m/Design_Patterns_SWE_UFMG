#include <iostream>

class Shape
{
private:
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

class Circle:public Shape{
    private:

    public:
        Circle(){
            std::cout<<"Circle created!"<<std::endl;
        };
        void draw() override{
            std::cout<<"Draw a circle"<<std::endl;
        }
};

class Square:public Shape{
    private:

    public:
        Square(){
            std::cout<<"Square created!"<<std::endl;
        };
        void draw() override{
            std::cout<<"Draw a square"<<std::endl;
        }
};
class Rectangle:public Shape{
    private:

    public:
        Rectangle(){
            std::cout<<"Rectangle created"<<std::endl;
        };
        void draw() override{
            std::cout<<"Draw a rectangle"<<std::endl;
        }
};

class ShapeFactory{
    private:

    public:
        static Shape* createShape(std::string type){
            if(type=="circle"){
                return new Circle();
            }
            if(type=="square"){
                return new Square();
            }
            if(type=="rectangle"){
                return new Rectangle();
            }
            return nullptr;
        }
};



int main()
{
    Shape* myShape = ShapeFactory::createShape("circle");
    myShape->draw();

    return 0;
}