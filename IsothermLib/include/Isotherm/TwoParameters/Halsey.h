//==============================================================================
// Name        : Halsey.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
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
 *  @ingroup IsothermTwo_Parameters
 *  @brief Classe Halsey contem a equacao da isoterma de Halsey.
 *  @{
 */

/// @file Halsey.h
/// @brief Contém a definição da classe Halsey





#ifndef __HALSEY_H__
#define __HALSEY_H__

//==============================================================================
// include da isothermlib
//==============================================================================

#include <Error/IsoException.h>
#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {


    /**
 * @brief Classe com as equações da isoterma de Halsey.
 * 
 * Isoterma com dois parâmetros, \f$ K_1 \f$ e \f$ K_2 \f$, cujas fórmulas são as seguintes:
 * \f[
 * \ln(Q_e(C_e)) = \frac{1}{K_2}\ln\left(\frac{K_1}{C_e}\right)
 * \f]
 * 
 * Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1063/1.1746689).
 */
    
class Halsey : public virtual TwoParameters,
               public IsothermTemplate<Halsey> {

//==============================================================================
// ID da classe
//==============================================================================

public:

/// <summary>
/// Definição de ID para esta classe para fins de identificação de erros.
/// </summary>
/// <example>
    DefineIdentity("Halsey", ID::Halsey);

//==============================================================================
// Funções Construtoras/Destrutora
//==============================================================================

public:

/// <summary>
/// Construtora default.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var;
/// @endcode
/// </example>
/// @param " " Não há parâmetros para esta função
    Halsey() = default;

/// <summary>
/// Construtora de cópia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var;
///     Halsey var1(var);
/// @endcode
/// </example>
/// @param  _orig Variável do tipo Halsey original.
    Halsey(const Halsey& _orig) = default;

/// <summary>
/// Destrutora.
/// </summary>
    virtual ~Halsey() = default;

/// <summary>
/// Construtora com os parâmetros que definem a isoterma de Halsey.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real k1(1.0);
///     Real k2(1.0);
///     Halsey var1(k1, k2);
/// @endcode
/// </example>
/// @param _k1 Constante da isoterma de Halsey.
/// @param  _k2 Constante de ligação de equilíbrio isotérmica.
/// @exception _k1 <= 0.
/// @exception _k2 <= 0.
    Halsey(const Real& _k1, const Real& _k2);

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
///     Halsey var1(k1, k2);
///     Halsey var2 = var1;
/// @endcode
/// </example>
/// @param _orig Variável do tipo Halsey original.
/// @return Cópia de _orig.
    Halsey& operator = (const Halsey& _orig) = default;

//==============================================================================
// Acesso às constantes da classe inline
//==============================================================================

/// <summary>
/// Função que informa o valor da constante da isoterma de Halsey.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var1(k1, k2);
///     Real _k1 = var1.K1();
/// @endcode
/// </example>
/// @param " " Não há parâmetros.
/// @return Valor da constante da isoterma de Halsey.
inline Real K1() const { return Value(0); };

/// <summary>
/// Função que retorna o valor da constante de ligação de equilíbrio isotérmica.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var1(k1, k2);
///     Real _k2 = var1.K2();
/// @endcode
/// </example>
/// @param " " Não há parâmetros.
/// @return Valor da constante de ligação de equilíbrio isotérmica.
inline Real K2() const { return Value(1); };

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Função para alterar o valor da constante da isoterma de Halsey.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var1(k1, k2);
///     Real k11(3.0);
///     var1.K1(k11);
/// @endcode
/// </example>
/// @param _k1 Novo valor da constante da isoterma de Halsey.
/// @exception _k1 <= 0.
inline void K1(const Real& _k1) {
    *this = Halsey(_k1, Value(1));
};

/// <summary>
/// Função que altera o valor da constante de ligação de equilíbrio isotérmica.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var1(k1, k2);
///     Real _k22(2.0);
///     var1.K2(_k22);
/// @endcode
/// </example>
/// @param _k2 Novo valor da constante de ligação de equilíbrio isotérmica.
/// @exception _k2 <= 0.
inline void K2(const Real& _k2) {
    *this = Halsey(Value(0), _k2);
};

//==============================================================================
// Funções virtuais
//==============================================================================

    virtual Real Qe(const Real& _c, const Real& _temp) const;

/// <summary>
/// Função que calcula a quantidade de sorção no equilíbrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Halsey var1(k1, k2);
///     Real ce(1.0);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
/// @param _ce Concentração do soluto.
/// @return Valor da quantidade de sorção no equilíbrio.
/// @exception _ce < 0.
    [[nodiscard]] 
    inline Real Qe(const Real& _c) const override {
        return Qe(_c, 0);
    };

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override {
        return std::make_unique<Halsey>(*this);
    }
    
};


}

#endif /* __HALSEY_H__ */

/** @} */
