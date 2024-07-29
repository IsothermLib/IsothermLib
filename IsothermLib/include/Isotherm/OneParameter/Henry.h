//==============================================================================
// Name        : Henry.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Henry
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

/** @defgroup Henry  Henry
 *  @ingroup One_Parameter
 *  Classe Henry e uma classe de um parametro
 *  @{
 */

/// <summary>
/// Classe com as equacoes da isoterma de Henry.
/// </summary>
///  Isoterma com um parametro, \f$ K_1 > 0 \f$, cuja formula e a seguinte:
///\begin{align}
///     Q_e(C_e) = K_1 C_e
///\end{align}
///  O artigo em que esta isoterma foi definida pode ser encontrado [aqui](https://doi.org/10.1098/rstl.1803.0004 ).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///  \copyright GNU Public License.

#ifndef __HENRY_H__
#define	__HENRY_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/OneParameter/OneParameter.h>

namespace ist {

class Henry :   public virtual OneParameter,
                public IsothermTemplate < Henry >
{
//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
    DefineIdentity  (   "Henry"
                    ,   ID::Henry
                    );

//==============================================================================
// Funcoes Construtoras/Destrutora
//==============================================================================

public:

/// <summary>
/// Construtora default.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Henry() = default;

/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var;
///     Henry  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Henry original.
    Henry(const Henry& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Henry() = default;

/// <summary>
/// Construtora com o parametros que define a isoterma de Henry.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real k1(1.0);
///     Henry  var1(k1);
/// @endcode
/// </example>
///  @param _k1 Coeficiente de distribuicao.
///  @exception _k1 <= 0.
    Henry (const Real& _k1);

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

public:

/// <summary>
/// Sobrecarga do operador =.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(k1);
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Henry original.
///  @return Copia de _orig.
    Henry& operator = (const Henry& _orig) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funcao que informa o valor do coeficiente de distribuicao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(k1);
///     Real   k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente de distribuicao.
    [[nodiscard]]
    inline Real K1 () const
    {
        return  Value(0);
    };

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar o valor do coeficiente de distribuicao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(_k1);
///     Real   k11(3.0);
///     var1.K1(k11);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente de distribuicao.
///  @exception _k1 <= 0.
    inline void K1 (const Real& _k1)
    {
        *this = Henry(_k1);
    };

//==============================================================================
// Funcoes virtuais
//==============================================================================

public:

/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Henry  var1(k);
///     Real ce(1.0);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _c < 0.
    
public:
    
    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }
      
    
protected:

    [[nodiscard]]
    virtual Real Qe     (   const Real&  _c
                        ,   const Real&) const ;

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Henry>(*this);
    }
    
};

/**
 *  @example TesteHenry.cpp
 *  Exemplo de utilizacao da classe Henry
 */

}

#endif	/* __HENRY_H__ */

/** @} */
