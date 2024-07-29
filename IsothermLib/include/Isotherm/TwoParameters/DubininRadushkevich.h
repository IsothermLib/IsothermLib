//==============================================================================
// Name        : DubininRadushkevich.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Dubinin-Radushkevich
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

/** @defgroup DubininRadushkevich Dubinin-Radushkevich
 *  @ingroup Two_Parameters
 *  Classe DubininRadushkevich contem as equacoes da isoterma de Dubinin Radushkevich.
 *  @{
 */

/// <summary>
/// Classe com as equacoes da isoterma de Dubinin-Radushkevich
/// </summary>
///  Isoterma com dois parametros, \f$ q_{max} \f$ e \f$ K_1 \f$,  cujas formulas sao as seguintes:
///\begin{align}
///     Q_e (C_e, T) &= q_{max} \exp( -K_1 \epsilon^2 ) \hfil  \\\ \\\
///     \epsilon &= R T \ln \left(1 + \frac{1}{C_e} \right)
///\end{align}
///  Um artigo de referencia pode ser encontrado [aqui](https://doi.org/10.1021/cr60204a006).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///  \copyright GNU Public License.

#ifndef __DUBININ_RADUSHKEVICH_H__
#define	__DUBININ_RADUSHKEVICH_H__

//==============================================================================
// include da isothermlib
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {


class DubininRadushkevich : public virtual TwoParameters,
                            public IsothermTemplate < DubininRadushkevich > {


//==============================================================================
// ID da classe
//==============================================================================

public:


/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
    DefineIdentity  (   "DubininRadushkevich"
                    ,   ID::DubininRadushkevich
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
///     DubininRadushkevich  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    DubininRadushkevich() = default;

/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var;
///     DubininRadushkevich  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo DubininRadushkevich original.
    DubininRadushkevich ( const DubininRadushkevich& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~DubininRadushkevich()  = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de DubininRadushkevich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real q1(1.0);
///     Real k1(1.0);
///     Real RGAS(62.363598221529);
///     DubininRadushkevich  var1(q1, k1);              // Constante dos gases default
///     DubininRadushkevich  var2(q1, k1, RGAS);        // Constante dos gases modificada
/// @endcode
/// </example>
///  @param _qmax Constante de equilibrio de Dubinin-Radushkevich.
///  @param  _k1 Coeficiente associado a energia de adsorcao.
///  @param _rgas Valor da constante universal dos gases diferente do padrao.
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
///  @exception _rgas <= 0.
    DubininRadushkevich (   const Real&     _qmax
                        ,   const Real&     _k1
                        ,   const Real&     _rgas = Isotherm::RGASCONST
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
///     DubininRadushkevich  var1(q1, k1);
///     DubininRadushkevich  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo DubininRadushkevich original.
///  @return Copia de _orig.
    DubininRadushkevich& operator = (const DubininRadushkevich& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Funcao que informa o valor da constante de equilibrio de Dubinin-Radushkevich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da  constante de equilibrio de Dubinin-Radushkevich.
[[nodiscard]] 
inline Real Qmax () const
{
    return  Value(0);
};

/// <summary>
/// Funcao que retorna o coeficiente associado a energia de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real vk1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a energia de adsorcao.
[[nodiscard]] 
inline Real K1 () const
{
    return  Value(1);
};


/// <summary>
/// Funcao que retorna o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real rg = var1.Rgas();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da constante universal dos gases.
[[maybe_unused]] [[nodiscard]] 
inline Real Rgas () const
{
    return  RGAS;
};


//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar  a constante de equilibrio de Dubinin-Radushkevich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real vq1(3.0);
///     var1.Qmax(vq1);
/// @endcode
/// </example>
///  @param _qmax Novo valor da constante de equilibrio de Dubinin-Radushkevich.
///  @exception _qmax <= 0.
inline void Qmax (const Real& _qmax)
{
    *this = DubininRadushkevich     (   _qmax
                                    ,   Value(1)
                                    , this->Rgas()
                                    );
};


/// <summary>
/// Funcao que altera o coeficiente associado a energia de adsorcao.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real vk1(2.0);
///     var1.K1(vk1);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a energia de adsorcao.
///  @exception _k1 <= 0. 
inline  void K1 (const Real& _k1)
{
    *this = DubininRadushkevich (   Value(0)
                                ,   _k1
                                ,   this->Rgas()
                                );
};

/// <summary>
/// Funcao para alterar o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real rgas(62.363598221529);
///     var1.Rgas(rgas);
/// @endcode
/// </example>
///  @param _rgas Novo valor da constante universal dos gases.
///  @exception _rgas <= 0.
[[maybe_unused]] 
inline  void Rgas (const Real& _rgas)
{
    *this = DubininRadushkevich     (   Value(0)
                                    ,   Value(1)
                                    ,   _rgas
                                    );

};

//==============================================================================
// Funcoes virtuais
//==============================================================================
//
/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real ce(1);
///     Real tempK(300);
///     Real qe = var1.Qe(ce, tempK);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @param _temp Temperatura em K.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _c <= 0.
///  @exception _temp <= 0.
    [[nodiscard]]  
    Real Qe     (   const Real& _c
                ,   const Real& _temp
                ) const;

/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     DubininRadushkevich  var1(q1, k1);
///     Real ce(1);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _c <= 0.
    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }


/// <summary>
/// Funcao que faz o clone da classe virtual.
/// </summary>
    

    [[maybe_unused]] [[nodiscard]] 
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<DubininRadushkevich>(*this);
    }


private:

Real                    RGAS = Isotherm::RGASCONST;      /// Valor default da constante universal dos gases.

};


/// \example TesteDubininRadushkevich.cpp


}

#endif
