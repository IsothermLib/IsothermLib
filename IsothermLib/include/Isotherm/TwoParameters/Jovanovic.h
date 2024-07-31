//==============================================================================
// Name        : Jovanovic.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Jovanovic
//
// Copyright   : Copyright (C) 2024 Joao Flavio Vasconcellos
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

/** @defgroup Jovanovic Jovanovic
 *  @ingroup IsothermTwo_Parameters
 *  @brief Classe Jovanovic contém a equação da isoterma de Jovanovic.
 */

/// @file Jovanovic.h
/// @brief Contém a definição da classe Jovanovic


#ifndef __JOVANOVIC_H__
#define __JOVANOVIC_H__

//==============================================================================
// include da isothermlib
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {

/**
 * @brief Classe com as equações da isoterma de Jovanovic
 * 
 * Isoterma com dois parâmetros, \f$ q_{max} \f$ e \f$ K_1 \f$, cuja fórmula é a seguinte:
 * \f[
 *  \ln( Q_e (C_e)) = \ln(q_{max}) - K_1 C_e
 * \f]
 * Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/B978-0-12-804609-8.00005-4).
 */
    


class Jovanovic : public virtual TwoParameters,
                  public IsothermTemplate<Jovanovic> {

//==============================================================================
// ID da classe
//==============================================================================

public:
    /// <summary>
    /// Definição de ID para esta classe para fins de identificação de erros.
    /// </summary>
    DefineIdentity("Jovanovic", ID::Jovanovic);

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
    ///     Jovanovic var;
    /// @endcode
    /// </example>
    /// @param " " Não há parâmetros para esta função
    Jovanovic() = default;

    /// <summary>
    /// Construtora de cópia.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Jovanovic var;
    ///     Jovanovic var1(var);
    /// @endcode
    /// </example>
    /// @param _orig Variável do tipo Jovanovic original.
    Jovanovic(const Jovanovic& _orig) = default;

    /// <summary>
    /// Destrutora.
    /// </summary>
    virtual ~Jovanovic() = default;

    /// <summary>
    /// Construtora com os parâmetros que definem a isoterma de Jovanovic.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Real q1(1.0);
    ///     Real k1(1.0);
    ///     Jovanovic var1(q1, k1);
    /// @endcode
    /// </example>
    /// @param _qmax Capacidade máxima de adsorção.
    /// @param _k1 Constante da isoterma de Jovanovic.
    /// @exception _qmax <= 0.
    /// @exception _k1 <= 0.
    Jovanovic(const Real& _k1, const Real& _qmax);

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
    ///     Jovanovic var1(q1, k1);
    ///     Jovanovic var2 = var1;
    /// @endcode
    /// </example>
    /// @param _orig Variável do tipo Jovanovic original.
    /// @return Cópia de _orig.
    Jovanovic& operator=(const Jovanovic&) = default;

//==============================================================================
// Acesso às constantes da classe
//==============================================================================

    /// <summary>
    /// Função que retorna a constante da isoterma de Jovanovic.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Jovanovic var1(q1, k1);
    ///     Real k2 = var1.K1();
    /// @endcode
    /// </example>
    /// @param " " Não há parâmetros.
    /// @return Valor da constante da isoterma de Jovanovic.
    [[nodiscard]]
    inline Real K1() const { return Value(1); }

    /// <summary>
    /// Função que informa o valor da capacidade máxima de adsorção.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Jovanovic var1(q1, k1);
    ///     Real q2 = var1.Qmax();
    /// @endcode
    /// </example>
    /// @param " " Não há parâmetros.
    /// @return Valor da capacidade máxima de adsorção.
    [[nodiscard]]
    inline Real Qmax() const { return Value(0); }

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

    /// <summary>
    /// Função para alterar a capacidade máxima de adsorção.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Jovanovic var1(q1, k1);
    ///     Real q2(3.0);
    ///     var1.Qmax(q2);
    /// @endcode
    /// </example>
    /// @param _qmax Novo valor da capacidade máxima de adsorção.
    /// @exception _qmax <= 0.
    void Qmax(const Real& _qmax) { *this = Jovanovic(_qmax, Value(1)); }

    /// <summary>
    /// Função que altera a constante da isoterma de Jovanovic.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Jovanovic var1(q1, k1);
    ///     Real k2(2.0);
    ///     var1.K1(k2);
    /// @endcode
    /// </example>
    /// @param _k1 Novo valor da constante da isoterma de Jovanovic.
    /// @exception _k1 <= 0.
    void K1(const Real& _k1) { *this = Jovanovic(Value(0), _k1); }

//==============================================================================
// Funções virtuais
//==============================================================================

    /// <summary>
    /// Função que calcula a quantidade de sorção no equilíbrio.
    /// </summary>
    /// <example>
    /// Uso:
    /// @code
    ///     Jovanovic var1(q1, k1);
    ///     Real ce(1);
    ///     Real qe = var1.Qe(ce);
    /// @endcode
    /// </example>
    /// @param _c Concentração do soluto.
    /// @return Valor da quantidade de sorção no equilíbrio.
    /// @exception _c < 0.
    [[nodiscard]]
    Real Qe(const Real& _c, const Real& _temp = 0) const;

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override {
        return std::make_unique<Jovanovic>(*this);
    }
};

} // namespace ist

#endif /* __JOVANOVIC_H__ */

/** @} */
