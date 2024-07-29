//==============================================================================
// Name        : OneParameter.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe base para as isotermas com um PARAMETRO
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

/** @defgroup OneParameter 
 *  @ingroup Base
 *  Classe base das isotermas com um unico parametro.
 *  @{
 */


///  <summary>
///  Classe base para todas as classes com um unico parametro.
/// </summary>
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///  
///  \copyright GNU Public License.


#ifndef ONEPARAMETER_H
#define ONEPARAMETER_H

//==============================================================================
// include da isotherm++
//==============================================================================
#include <Isotherm.h>


namespace ist {

class OneParameter : public virtual Isotherm {

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
    DefineIdentity  (   "OneParameter"
                    ,   ID::OneParameter
                    );


public:

/// <summary>
/// Construtora de copia que sera  utilizada nas classes derivadas.
/// </summary>
    OneParameter(const OneParameter&) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~OneParameter() = default;

/// <summary>
/// Construtora de um parametro utilizada nas classes derivadas.
/// </summary>
    OneParameter (const Real& = 0.0);

};

}

        
#endif /* ONEPARAMETER_H */

/** @} */ 
        
       