#include <iostream>
#include <list>

using namespace std;

class Persona{
    public:
    char nombre[10];
    int edad;
};

class Empleado : public Persona{
    public:
    int noEmpleado;
};

class Alumno : public Persona{
    public:
    int registro;
}

int main (int argc, char const *argv[])
{
    cout<<"tamaño int: " << sizeof(int) << endl;
    cout<<"tamaño long: " << sizeof(long) << endl;
    cout<<"tamaño float: " << sizeof(float) << endl; 
    cout<<"tamaño double: " << sizeof(double) << endl; 
    cout<<"tamaño bool: " << sizeof(bool) << endl;
    cout<<"tamaño char: " << sizeof(char) << endl; 
    cout<<"tamaño byte: " << sizeof(byte) << endl;

    cout<<"Direcciones de memoria" << endl; 
    cout<<"Punteros en C: " << malloc(sizeof(int)) << endl; 
    cout<<"Punteros en C++: " << new int <<endl; 

    cout<<"tamaño de puntero: " <<endl; 
    cout<<"int* " <<sizeof(int*) <<endl; 
    cout<<"char* " <<sizeof(char*) <<endl;
    
    cout<< "Casteo de tipos" <<endl;
    //Casteo de punteros
    int* puntero = (int*)malloc(sizeof(int));
    
    //Casteo de variables
    int ejemplo =65;
    char letra = (char)ejemplo;
    cout << letra <<endl;

    //Casteo Polimorfismo
    Empleado* persona = new Empleado();
    Alumno* persona2 = new Alumno();

    list<Persona*> personas:
    personas.emplace_back(persona);
    personas.emplace_back(persona2);

    cout<< (*persona).edad <<endl;
    cout<< (*persona).nombre <<endl;
    cout<< (*persona).noEmpleado <<endl;
    cout<< persona ->edad <<endl;
    cout<< persona ->nombre <<endl;
    cout<< persona ->noEmpleado <<endl;

    //Tratar a todos como personas
    for (auto &&p : persona)
    {
        cout<< persona->nombre <<endl;
        cout<< persona->edad <<endl;
    }


    return 0;




}