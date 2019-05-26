/*
Write a program:

with class hierarchy
objects are created by a factory function depends on user input
collect objects at a container
call a function special for a class of a object
print out properties of all elements

*/

#include <vector>
#include <iostream>

enum class material { wood, resistor, capacitor, sandPaper };

class WorkshopMaterial
{
   private:
     std::string materialName;

   public:
     WorkshopMaterial(){}
     virtual void printName() = 0;
     void setMaterialName( std::string name ) { materialName = name; };
     std::string getMaterialName() { return materialName; };
     virtual void specifyTheDetails( std::string detail ) = 0;
};


class Wood : public WorkshopMaterial
{
   private:
     std::string sortOfWood {"Oak"};
   public:
     Wood(){};
     Wood( std::string materialName)
     {
        WorkshopMaterial::setMaterialName( materialName );
     }
     void printName() {
        std::cout << WorkshopMaterial::getMaterialName() << " " 
                  << sortOfWood << std::endl; };
      void specifyTheDetails( std::string detail ) { sortOfWood = detail; };

};

class ElectronicPart : public WorkshopMaterial
{
   private:
     std::string typeOfElement;
     float ratedPower {2};
     int nominalVoltage {12};

   public:
     virtual void printName() = 0;
     virtual void specifyTheDetails( std::string detail ) = 0;
};

class SandPaper : public WorkshopMaterial
{
   private:
     std::string typesOfAbrasive  {"Glass"};
     std::string shape ;
     std::string gritDesignation;
     float volume;

   public:
     SandPaper(){};
     SandPaper ( std::string matNam )
     {
        WorkshopMaterial::setMaterialName( matNam );
     }
     void printName() {
        std::cout << WorkshopMaterial::getMaterialName() << " " 
                  << typesOfAbrasive << std::endl; };
     void specifyTheDetails( std::string detail ) { typesOfAbrasive = detail; };
};

class Resistor : public ElectronicPart 
{
   private:
     float nominalResistance { 430 };
     std::string typeOfResistor { "THT" };


   public:
     Resistor (){};
     Resistor ( std::string matNam )
     {
        WorkshopMaterial::setMaterialName( matNam );
     }
     void printName() {
        std::cout << WorkshopMaterial::getMaterialName() << " " 
                  << nominalResistance << " ohm" << std::endl; }
      void specifyTheDetails( std::string detail ) { nominalResistance = std::stof( detail ); };
};

class Capacitor : public ElectronicPart
{
   private:
     float nominalCapacity { 0.000018 };
     std::string typeOfCapacitor {"SMD"};
   
   public:
     Capacitor(){};
     Capacitor( std::string matNam )
     {
        WorkshopMaterial::setMaterialName( matNam );
     }
     void printName() {
        std::cout << WorkshopMaterial::getMaterialName() << " " 
                  << nominalCapacity << " farads" << std::endl; }
     void specifyTheDetails( std::string detail ) { nominalCapacity = std::stof( detail ); };
};

WorkshopMaterial *newMaterial( material typeOfMaterial )
{
   switch (typeOfMaterial) {
    case material::wood :
        return new Wood( "Wood" );
    case material::sandPaper :
        return new SandPaper( "Sandpaper");
    case material::resistor :
        return new Resistor( "Resistor" );
    case material::capacitor :
        return new Capacitor("Capacitor");
    default:
        return new Wood( "empty");
    }
};

int main()
{
   std::vector<WorkshopMaterial*> materials;

   materials.push_back( newMaterial( material::wood ) );
   materials.push_back( newMaterial( material::sandPaper ) );
   materials.push_back( newMaterial( material::resistor ) );
   materials.push_back( newMaterial( material::capacitor ) );

   for(auto element : materials )
   {
      element->printName();
   }
   std::cout << std::endl;

   materials.at(0)->specifyTheDetails( "Pine" );
   materials.at(1)->specifyTheDetails( "Flint" );
   materials.at(2)->specifyTheDetails( "220" );
   materials.at(3)->specifyTheDetails( "0.000027" );

   for(auto element : materials )
   {
      element->printName();
   }
   std::cout << std::endl;
}
