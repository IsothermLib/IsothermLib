//==============================================================================
// Name        : Halsey.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Halsey
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

/** @defgroup Halsey Isoterma de Helsey
 *  @ingroup Two_Parameters
 *  Classe Halsey contem a equacao da isoterma de Halsey.
 *  @{
 */

/// <summary>
/// Classe com as equacoes da isoterma de Halsey
/// </summary>
///  Isoterma com dois parametros, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas formulas sao as seguintes:
///\begin{align}
///     ln(Q_e(C_e)) = \frac{1}{K_2}ln\left(\frac{K_1}{C_e}\right)
///\end{align}
///  Um artigo de referencia pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///  \copyright GNU Public License.

#ifndef __HALSEY_H__
#define __HALSEY_H__

//==============================================================================
// include da isothermlib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {



class Halsey :  public virtual TwoParameters,
                public IsothermTemplate < Halsey >
{

//==============================================================================
// ID da classe
//==============================================================================

public:


/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
/// <example>
    DefineIdentity  (   "Halsey"
                    , ID::Halsey
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
///     Halsey  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Halsey() = default;

/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey  var;
///     Halsey  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Halsey original.
    Halsey(const Halsey& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Halsey() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de Halsey.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real k1(1.0);
///     Real k2(1.0);
///     Halsey  var1(k1, k2);
/// @endcode
/// </example>
///  @param _k1 Constante da isoterma de Halsey.
///  @param  _k2 Constante de ligacao de equilibrio isotermica.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    Halsey  (   const Real& _k1
            ,   const Real& _k2
            );

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
///     Halsey  var1(k1, k2);
///     Halsey  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Halsey original.
///  @return Copia de _orig.
    Halsey& operator = (const Halsey& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Funcao que informa o valor da constante da isoterma de Halsey.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey  var1(k1, k2);
///     Real _k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da constante da isoterma de Halsey.
inline Real K1 () const {return  Value(0);};

/// <summary>
/// Funcao que retorna o valor da constante de ligacao de equilibrio isotermica.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey  var1(k1, k2);
///     Real _k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da constante de ligacao de equilibrio isotermica.
inline Real K2 () const
{
    return  Value(1);
};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar o valor da constante da isoterma de Halsey.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey  var1(k1, k2);
///     Real k11(3.0);
///     var1.K1(k11);
/// @endcode
/// </example>
///  @param _k1 Novo valor da constante da isoterma de Halsey..
///  @exception _k1 <= 0.
inline void K1 (const Real& _k1)
{
    *this = Halsey(_k1, Value(1));
};


/// <summary>
/// Funcao que altera o valor da constante de ligacao de equilibrio isotermica.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey  var1(k1, k2);
///     Real _k22(2.0);
///     var1.K2(_k22);
/// @endcode
/// </example>
///  @param _k2 Novo valor da constante de ligacao de equilibrio isotermica.
///  @exception _k2 <= 0.
inline void K2 (const Real& _k2)
{
    *this = Halsey(Value(0), _k2);
};

//==============================================================================
// Funcoes virtuais
//==============================================================================

    virtual Real Qe         (   const Real& _c
                            ,   const Real& _temp
                            ) const;

    
/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey  var1(k1, k2);
///     Real ce(1.0);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _ce Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _ce < 0.
    [[nodiscard]] 
    inline Real Qe  (   const Real& _c
                    ) const override
                    {
                        return Qe(_c, 0);
                    };

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Halsey>(*this);
    }


    
};

/// \example TesteHalsey.cpp

}

#endif /* __HALSEY_H__ */

/** @} */