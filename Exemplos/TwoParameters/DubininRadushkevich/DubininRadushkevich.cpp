//==============================================================================
// Name        : DubininRadushkevich.cpp
// Authors     : Iasmim Barboza Storck
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Exemplo de uso da classe Dubinin-Radushkevich da biblioteca Isotherm++
//
// Copyright   : Copyright (C) <2024>  Joao Flavio Vasconcellos 
//                                      (jflavio at iprj.uerj.br)
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//==============================================================================

//==============================================================================
// Includes C++ Standard Library
//==============================================================================

#include <cmath>    // for std::log
#include <iomanip>  // for std::setw, std::setprecision
#include <iostream> // for std::cout
#include <string>   // for std::string

//==============================================================================
// Includes Isotherm++ Library
//==============================================================================

#include <Misc/Misc.h>  // for PrintLine
#include <Isotherm/TwoParameters/DubininRadushkevich.h>  // for ist::DubininRadushkevich

int main(int argc, char** argv) {

    //==============================================================================  
    // Impressão do cabeçalho
    //==============================================================================

    std::string msg("Exemplo da classe Dubinin-Radushkevich da biblioteca Isotherm++");
    PrintLine(std::cout);
    std::cout << "Início do " << msg << "\n";
    PrintLine(std::cout);

    //==============================================================================  
    // Definição dos parâmetros
    //==============================================================================

    const Real TEMP(400);        // Temperatura em Kelvin
    const Real CE(2e-3);         // Concentração de equilíbrio do adsorvato no adsorvente em mg/L
    const Real QMAX(150e-3);     // Quantidade de adsorvato em equilíbrio [mol/g]
    const Real K1(1e-8);         // Constante de Dubinin-Radushkevich

    // Criação do objeto Dubinin-Radushkevich com QMAX e K1
    const ist::DubininRadushkevich isoterma(QMAX, K1);
    const Real qe = isoterma.Qe(CE, TEMP);  // Cálculo da quantidade de adsorvato em equilíbrio

    //==============================================================================  
    // Imprimindo as informações sobre as constantes do modelo
    //==============================================================================

    std::cout << "\n";
    PrintLine(std::cout);
    std::cout << "Impressão de informações sobre as constantes\n";
    PrintLine(std::cout);

    std::cout << isoterma << std::endl;

    std::cout << "Número de constantes da isoterma: " << isoterma.NumberConst() << std::endl;

    std::cout << std::setfill(' ');
    std::cout << "Impressão de informações da isoterma\n"
              << std::setw(20) << std::left << "Parâmetro"
              << std::setw(40) << "Detalhe do parâmetro"
              << std::right << std::endl;

    for (const auto& x : isoterma) {
        std::cout << std::setw(20) << std::left << x.first
                  << std::setw(40) << x.second
                  << std::right << "\n";
    }

    std::cout << "\nPara a temperatura: " << TEMP
              << " e concentração de equilíbrio: " << CE
              << " tem-se que qe = " << qe << std::endl;

    //==============================================================================  
    // Imprimindo a curva da isoterma
    //==============================================================================

    const Real CMIN(1E-3);    // Valor mínimo da concentração
    const Real CMAX(1.5);     // Valor máximo da concentração
    const UInt NPTO(1001);    // Número de pontos gerados

    // Função de linearização da isoterma no eixo X
    auto EixoX = [](const Real& _qe, const Real& _ce) -> Real {
        Real auxi = std::log(1 + 1.0 / _ce);
        return auxi * auxi;
    };

    // Função de linearização da isoterma no eixo Y
    auto EixoY = [isoterma, TEMP](const Real& _qe, const Real& _ce) -> Real {
        auto auxi = 1.0 / (isoterma.Rgas() * TEMP);
        return -std::log(_qe) * auxi * auxi;
    };

    const std::string FILENAME("Figuras/CasoL400.dat");

    std::cout << "\n";
    PrintLine(std::cout);
    std::cout << "Impressão do gráfico no arquivo: " << FILENAME << "\n";
    PrintLine(std::cout);

    isoterma.PlotGraph(FILENAME, EixoX, EixoY, NPTO, CMIN, CMAX, TEMP);

    //==============================================================================  
    // Fim do programa exemplo
    //==============================================================================

    std::cout << "\n";
    PrintLine(std::cout);
    std::cout << "Fim do " << msg << "\n";
    PrintLine(std::cout);

    return 0;
}
