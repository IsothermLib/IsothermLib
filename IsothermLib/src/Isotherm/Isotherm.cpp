//==============================================================================
// Name        : Isotherm.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base da biblioteca Isotherm++
//
// Copyright   : Copyright (C) <2022>  Joao Flavio Vasconcellos 
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
// include da IsothermLib
//==============================================================================

#include <Isotherm.h>

//==============================================================================
// include da lib c++ 
//==============================================================================

#include <iomanip>                  // std::setw
#include <fstream>                  // std::ofstream
#include <iterator>                 // std::ostream_iterator

namespace ist {

//==============================================================================
// Sobrecarga do operador <<
//==============================================================================

std::ostream& 
operator <<     (   std::ostream &              _os
                ,   const ist::Isotherm&        _tp
                ) 
{

//    std::_Ios_Fmtflags original_format(_os.flags());
//    _os << std::left << std::showpoint;
//
//
//        UInt       ipos(0);
//        _os     << "Isoterma de "
//                << _tp.className()
//                << " : ";
//
//        std::transform  (   std::begin(_tp)
//                        ,   std::end(_tp)
//                        ,   std::ostream_iterator<std::string>(_os, " ")
//                        ,   [&](auto _info)
//                        {
//                            std::stringstream sstr;
//                            sstr.setf (std::ios::fixed, std::ios::floatfield);
//                            sstr << std::left
//                                 << std::scientific
//                                 << _info.first
//                                 << " = "
//                                 << std::setw(10)
//                                 << _tp.Value(ipos);
//                            ipos++;
//
//                            return sstr.str();
//                        }
//                    );
                    
//    _os.flags(original_format);      // Voltando ao formato original
                
    return _os;
        
}

[[maybe_unused]] std::string
Isotherm :: CodeString (const UInt& _ncode) const
{
    return (std::begin(this->InfoIsotherm()) + _ncode)->first;
}

[[maybe_unused]] std::string
Isotherm :: NameString (const UInt& _ncode) const
{
    return (std::begin(InfoIsotherm()) + _ncode)->second;
}


//==============================================================================
//  Função utilizada para imprimir para imprimir os valores das isotermas para
//  elaboração posterior de gráficos
//==============================================================================

[[maybe_unused]] void
Isotherm ::  PlotGraph  (   const std::string&          _filename
                        ,   const FunctionEscala&             _eixoX
                        ,   const FunctionEscala&             _eixoY
                        ,   const UInt&                 _npto
                        ,   const Real&                 _xinit
                        ,   const Real&                 _xfim
                        ,   const Real&                 _temperature) const

{

const auto      DC((_xfim - _xinit) / (_npto - 1));
std::ofstream   output (_filename);
auto            ce(_xinit - DC);
auto            xFim(_xfim - 0.5 * DC);
Real            valorQe;

    output << std::scientific;


    do {

        ce      += DC;
        valorQe = Qe(ce, _temperature);

        output << std::setw(15) << _eixoX(valorQe, ce)
               << std::setw(15) << _eixoY(valorQe, ce)
               << std::endl;

    } while (ce < xFim);

    output.close();

}

}

