//==============================================================================
// Name        : Temkin.h
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

/** @defgroup Temkin Temkin
 *  @ingroup Two_Parameters
 *  Classe Temkin e uma classe de dois parametros.
 */

/// <summary>
/// Classe com as equacoes da isoterma de Temkin.
/// </summary>
///  Isoterma com dois parametros, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas formulas sao as seguintes:
///\begin{align}
///     Q_e(C_e, T) = \frac{R T}{K_2}ln(K_1 C_e )
///\end{align}
///  Um artigo de referencia pode ser encontrado [aqui](https://doi.org/10.1016/0167-4838(95)00006-G).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///
///  \copyright GNU Public License.


#ifndef __TEMKIN_H__
#define	__TEMKIN_H__


//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {


class Temkin : public virtual TwoParameters,
                            public IsothermTemplate < Temkin > {

//==============================================================================
// ID da classe
//==============================================================================

public:


/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
/// <example>
    DefineIdentity ("Temkin", ID::Temkin);

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
///     Temkin  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Temkin() = default;

/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var;
///     Temkin  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Temkin original.
    Temkin(const Temkin& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Temkin() = default;

/// <summary>
/// Construtora com os parametros que definem a isoterma de Temkin.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real q1(1.0);
///     Real k2(1.0);
///     Real RGAS(62.363598221529);
///     Temkin  var1(k1, k2);              // Constante dos gases default
///     Temkin  var2(k1, k2, RGAS);        // Constante dos gases modificada
/// @endcode
/// </example>
///  @param _k1 Constante da isoterma de Temkin.
///  @param  _k2 Constante de ligacao de equilibrio isotermica.
///  @param _rgas Valor da constante universal dos gases diferente do padrao.
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
///  @exception _rgas <= 0.
    Temkin (const Real& _k1, const Real& _k2,  const Real& _rgas = Isotherm::RGASCONST);

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
///     Temkin  var1(k1, k2);
///     Temkin  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Temkin original.
///  @return Copia de _orig.
    Temkin& operator = (const Temkin& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Funcao que informa o valor da constante da isoterma de Temkin.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(k1, k2);
///     Real _k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da  constante da isoterma de Temkin.
    inline Real K1 () const {return  Value(0);};

/// <summary>
/// Funcao que retorna o coeficiente associado a constante de ligacao de equilibrio isotermica.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(k1, k2);
///     Real _k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de ligacao de equilibrio isotermica.
    inline Real K2 () const {return  Value(1);};


/// <summary>
/// Funcao que retorna o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(k1, k2);
///     Real rg = var1.Rgas();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da constante universal dos gases.
    inline Real Rgas () const {return  RGAS;};


//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar a constante da isoterma de Temkin.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(k1, k2);
///     Real _k1(3.0);
///     var1.K1(_k1);
/// @endcode
/// </example>
///  @param _k1 Novo valor da constante da isoterma de Temkin.
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = Temkin(_k1, Value(1), this->Rgas());};


/// <summary>
/// Funcao que alterao o coeficiente associado a constante de ligacao de equilibrio isotermica.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(k1, k2);
///     Real _k2(2.0);
///     var1.K2(_k2);
/// @endcode
/// </example>
///  @param _k2 Novo valor do coeficiente associado a constante de ligacao de equilibrio isotermica.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = Temkin(Value(0), _k2, this->Rgas());};

/// <summary>
/// Funcao para alterar o valor da constante universal dos gases.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(k1, k2);
///     Real rgas(62.363598221529);
///     var1.Rgas(rgas);
/// @endcode
/// </example>
///  @param _rgas Novo valor da constante universal dos gases.
///  @exception _rgas <= 0.
    void Rgas (const Real& _rgas) {*this = Temkin(Value(0), Value(1), _rgas);};

//==============================================================================
// Funcoes virtuais
//==============================================================================

/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Temkin  var1(q1, k2);
///     Real ce(1);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @param _temp Temperatura em K.
///  @return Valor da quantidade de sorcao no equilibrio.
///  @exception _c k1 < 1.
    [[nodiscard]] 
    Real Qe (const Real& _c, const Real& _temp) const;
    
    
    
    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Temkin>(*this);
    }    
    
private:

Real                    RGAS = Isotherm::RGASCONST;      /// Valor default da constante universal dos gases.


};


/// \example TesteTemkin.cpp
///Este e um arquivo com exemplos de aplicacao da classe Temkin.


}

#endif	/* TEMKIN_H */


/** @} */


