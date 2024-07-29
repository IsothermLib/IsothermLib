//==============================================================================
// Name        : OneParameter.cpp
// Authors     : Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com 1 parametro
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
// include da isotherm++
//==============================================================================

#include <Isotherm/OneParameter/OneParameter.h>


namespace ist {
       
//==============================================================================
// Variaveis esttaticas
//==============================================================================

VecPairString       detailsOneParameter
    {
        PairString  ( "Nao definido"
                    , "Nao definido")
    };

template<>
VecPairString IsothermTemplate < OneParameter >::infoIsotherm = detailsOneParameter;

//==============================================================================
// Construtoras
//==============================================================================

#undef  __FUNCT__
#define __FUNCT__ "OneParameter :: OneParameter( const Real&)"
OneParameter :: OneParameter( const Real& _par_0) // Primeiro parametro
{
    coeffValue    = VecReal({_par_0});

}

}