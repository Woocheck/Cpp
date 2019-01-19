 //- calculator
 //- reads two numbers and a sign from stdin (RPN)

#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[])
{
    

    if(argc!=4)
    {
        std::cout << "Please give two numbers and operator!"<< std::endl;
        return 0;
    }
    else
    {
        float x = std::stof(argv[1]);
        float y = std::stof(argv[2]);
        char operation = argv[3][0];
        switch(operation)
        {
            case '+':
            std::cout<< x << " " << operation << " " << y << " = "<< x+y << std::endl;
            break;

            case '-':
            std::cout<< x << " " << operation << " " << y << " = "<< x-y << std::endl;
            break;

            case '*':
            std::cout<< x << " " << operation << " " << y << " = "<< x*y << std::endl;
            break;

            case '/':
            if(y==0) 
            {
                std::cout<<"Divider is 0!!!"<<std::endl;
                break;
            }
            std::cout<< x << " " << operation << " " << y << " = "<< x/y << std::endl;
            break;

            default:
            std::cout<<"Allowed operators: + - * /."<<std::endl;
        }
    }
    

    return 0;
}
