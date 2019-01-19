#include <iostream>
#include <functional>

std::function <double ()> foo(std::function <double()>f1, std::function<double()>f2)
{
    double x=f1();
    double y=f2();

    if(x>y)
    {
        
        return f1;
    }
    else
    {
        return f2;
    }
}

int main()
{

    auto result = foo([](){return 2.5;}, [](){return 5.3;});
    std::cout << "Foo()=" << result() << std::endl;

}