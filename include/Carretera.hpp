#pragma once
#include <vector>
#include "Dibujo.hpp"

class Carretera {
public:
    int x, y, ancho, alto;
    Dibujo dibujo_carretera;
    std::vector<Dibujo> vehiculos;

    Carretera(int x, int y, int ancho, int alto, ftxui::Color color = ftxui::Color::White)
        : x(x), y(y), ancho(ancho), alto(alto),
          dibujo_carretera(x, y, GenerarFiguraCarretera(ancho, alto), color) {}

    static std::vector<std::u32string> GenerarFiguraCarretera(int ancho, int alto) {
        std::vector<std::u32string> figura;
        std::u32string top = U"+" + std::u32string(ancho-2, U'-') + U"+";
        std::u32string mid = U"|" + std::u32string(ancho-2, U' ') + U"|";
        figura.push_back(top);
        for (int i = 0; i < alto-2; ++i) figura.push_back(mid);
        figura.push_back(top);
        return figura;
    }

    void AgregarVehiculo(const Dibujo& vehiculo) {
        // Asegura que el animal esté dentro del corral
        int ax = vehiculo.x;
        int ay = vehiculo.y;
        if (ax < x+1) ax = x+1;
        if (ax > x+ancho-3) ax = x+ancho-3;
        if (ay < y+1) ay = y+1;
        if (ay > y+alto-3) ay = y+alto-3;
        Dibujo vehiculo_dentro(ax, ay, vehiculo.figura, vehiculo.color);
        vehiculos.push_back(vehiculo_dentro);
    }

    void Dibujar(ftxui::Screen& screen) const {
        dibujo_carretera.Dibujar(screen);
        for (const auto& vehiculo : vehiculos) {
            vehiculo.Dibujar(screen);
        }
    }
};