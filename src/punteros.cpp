#include <iostream>
#include <string>
#include <list>
using namespace std;

class Humano{
    private:
        string nombre;
        int edad;
    public:
        virtual string LeerNombre(){
            cin>>nombre;
            return nombre;
        }
        virtual int LeerEdad(){
            cin>>edad;
            return edad;
        }
        Humano(){
            nombre = "sin_nombre";
            edad = 0;
        }
         virtual ~Humano() {}
};

class Alumno : public Humano{
    private:
        int registro;
    public:
        int LeerRegistro(){
            cin>>registro;
            return registro;
        }
        Alumno(){registro = 0;}
};

class Empleado : public Humano{
    private:
        long noEmpleado;
    public:
        long LeerNumeroEmpleado(){
            cin>>noEmpleado;
            return noEmpleado;
        }
        Empleado(){noEmpleado = 0;}    
};

int main(int argc, char const *argv[])
{
    Humano* humano = NULL;
    Alumno* alumno = new Alumno();
    Empleado* empleado = new Empleado();

    humano = alumno;
    cout << "Edad alumno: ";
    humano->LeerEdad();
    cout << "Nombre alumno: ";
    humano->LeerNombre();

    humano = empleado;
    cout << "Edad empleado: ";
    humano->LeerEdad(); //cuando tienes muchos objetos y todos tienen una misma caracteristica
    cout << "Nombre emleado: ";
    humano->LeerNombre();

    list<Humano*> listaHumanos;
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Alumno());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());
    listaHumanos.emplace_back(new Empleado());

    for (auto &&h : listaHumanos)
    {
        cout << "Ingresa Nombre: ";
        cout << h->LeerNombre() << endl;
    }

    // Liberar memoria
    delete alumno;
    delete empleado;
    for (auto&& h : listaHumanos)
    {
        delete h;
    }
    
    return 0;
}