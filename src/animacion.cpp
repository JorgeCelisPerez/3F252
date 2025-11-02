#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <Dibujo.hpp>
#include <GestorDibujos.hpp>
#include <Carretera.hpp>
using namespace ftxui;

int main()
{
    // Crear la ventana
    auto screen = Screen::Create(
        Dimension::Fixed(80),
        Dimension::Fixed(24));

 // Edificio principal
    const std::vector<std::u32string> edificio1 = {
        U"   ||||   ",
        U"   ||||   ",
        U"   ||||   ",
        U"  _||||_  ",
        U" |______| "};

    // Segundo edificio más alto
    const std::vector<std::u32string> edificio2 = {
        U"   || ",
        U"   || ",
        U"   || ",
        U"  _||_",
        U" |____|"};

    // Coche pequeño
    const std::vector<std::u32string> coche1 = {
        U"     ______",
        U" ___/_____|_\\___",
        U"|_          _|",
        U"  O--------O"};

    // Camión
    const std::vector<std::u32string> camion = {
        U"     __________________",
        U" ___/   |_________|_\\___",
        U"|_              ____    _|",
        U"  O--------------O"};

    // Motocicleta
    const std::vector<std::u32string> moto = {
        U"   __o",
        U" _`\\<,_",
        U"(*)/ (*)"};

    // Poste de luz
    const std::vector<std::u32string> poste = {
        U"   |",
        U"  -O-",
        U"   |",
        U"   |",
        U"   |"};

    // ====== AGREGAR A GESTOR ======
    GestorDibujos gestor;
    gestor.Agregar(Dibujo(2, 3, edificio1, ftxui::Color::Blue));       // edificio azul
    gestor.Agregar(Dibujo(15, 1, edificio2, ftxui::Color::Cyan));      // edificio alto
    gestor.Agregar(Dibujo(28, 4, edificio1, ftxui::Color::BlueLight)); // otro edificio
    gestor.Agregar(Dibujo(5, 14, poste, ftxui::Color::Yellow));        // poste 1
    gestor.Agregar(Dibujo(20, 14, poste, ftxui::Color::Yellow));       // poste 2
    gestor.Agregar(Dibujo(35, 14, poste, ftxui::Color::Yellow));       // poste 3

    // Vehículos animados
    gestor.Agregar(Dibujo(10, 18, coche1, ftxui::Color::Red));         // coche rojo
    gestor.Agregar(Dibujo(30, 19, moto, ftxui::Color::Green));         // moto verde
    gestor.Agregar(Dibujo(45, 17, camion, ftxui::Color::GrayLight));   // camión

    // Carretera con autos en movimiento
    Carretera carretera(0, 20, 80, 23, ftxui::Color::White);
    carretera.AgregarVehiculo(Dibujo(10, 21, coche1, ftxui::Color::Red));
    
    carretera.AgregarVehiculo(Dibujo(60, 21, moto, ftxui::Color::GreenLight));

    // ====== ANIMACIÓN ======
    int frames = 200;
    for (int frame = 0; frame < frames; ++frame)
    {
        screen.Clear();

        // Movimiento de los vehículos
        gestor.dibujos[6].x = 10 + (frame % 50); // coche rojo se mueve a la derecha
        gestor.dibujos[7].x = 30 - (frame % 30); // moto se mueve a la izquierda
        gestor.dibujos[8].x = 45 - (frame % 25); // camión se mueve lentamente

        gestor.DibujarTodos(screen);
        carretera.Dibujar(screen);

        std::cout << screen.ToString();
        std::cout << screen.ResetPosition();
        std::cout << std::flush;

        std::this_thread::sleep_for(std::chrono::milliseconds(120));
    }

    return 0;
}