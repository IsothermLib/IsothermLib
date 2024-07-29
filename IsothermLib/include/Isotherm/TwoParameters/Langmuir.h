//==============================================================================
// Name        : Langmuir.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Langmuir
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


/** @defgroup Langmuir Langmuir
 *  @ingroup Two_Parameters
 *  Classe Langmuir e uma classe de dois parametros.
 */

/// <summary>
/// Classe com a equacao da isoterma de Langmuir
/// </summary>
///  Isoterma com dois parametros, \f$ q_{max} \f$ e \f$ K_1 \f$,  cujas formulas sao as seguintes:
///\begin{align}
///     \[Q_e(C_e, T) = q_{max}\frac{K_1C_e}{1+K_1C_e}\]
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


#ifndef __LANGMUIR_H__
#define	__LANGMUIR_H__


//==============================================================================
// include da isothermlib
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {


class Langmuir :    public virtual TwoParameters,
                    public IsothermTemplate < Langmuir >
{

//==============================================================================
// ID da classe
//==============================================================================

public:


/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
/// <example>
    DefineIdentity  (   "Langmuir"
                    ,   ID::Langmuir
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
///     Langmuir  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Langmuir() = default;

/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var;
///     Langmuir  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Langmuir original.
    Langmuir(const Langmuir& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Langmuir() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de Langmuir.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real q1(1.0);
///     Real k1(1.0);

/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorcao em [M /M ].
///  @param  _k1 Constante de equilibrio de Langmuir.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
    Langmuir    (   const Real& _qmax
                ,   const Real& _k1
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
///     Langmuir  var1(q1, k1);
///     Langmuir  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Langmuir original.
///  @return Copia de _orig.
    Langmuir& operator = (const Langmuir& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Funcao que informa o valor da capacidade maxima de adsorcao em [M /M ].   .
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da capacidade maxima de adsorcao em [M /M ].
    [[nodiscard]] 
    inline Real Qmax () const {return  Value(0);};

/// <summary>
/// Funcao que retorna o coeficiente associado a constante de equilibrio de Langmuir.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real k2 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de equilibrio de Langmuir.
    [[nodiscard]] 
    inline Real K1 () const {return  Value(1);};


//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar a capacidade maxima de adsorcao em [M /M ].   .
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real q2(3.0);
///     var1.Qmax(q2);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorcao em [M /M ].   .
///  @exception _qmax <= 0.
    void Qmax (const Real& _qmax)  {*this = Langmuir(_qmax, Value(1));};


/// <summary>
/// Funcao que altera o coeficiente associado a constante de equilibrio de Langmuir.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real k2(2.0);
///     var1.K1(k2);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de equilibrio de Langmuir.
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = Langmuir(Value(0), _k1);};


//==============================================================================
// Funcoes virtuais
//==============================================================================

/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Langmuir  var1(q1, k1);
///     Real ce(1);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _c < 0.
    [[nodiscard]] 
    Real Qe (const Real& _c, const Real&) const;
    
    [[nodiscard]] 
    inline Real Qe   (const Real& _c) const override
    {
        return Qe(_c, 0);
    }
    

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Langmuir>(*this);
    }

  

};


/// \example TesteLangmuir.cpp
///Este e um arquivo com exemplos de aplicacao da classe Langmuir.


}

#endif	/* LANGMUIR_H */

/** @} */

