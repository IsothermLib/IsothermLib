//==============================================================================
// Name        : DubininRadushkevich.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               João Flávio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Dubinin-Radushkevich
//
// Copyright   : Copyright (C) <2024>  João Flávio Vasconcellos
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
//==============================================================================

/** 
 * @defgroup DubininRadushkevich Dubinin-Radushkevich
 * @ingroup IsothermTwo_Parameters
 * @brief Classe DubininRadushkevich contém as equações da isoterma de Dubinin-Radushkevich.
 * @{
 */

/// @file DubininRadushkevich.h
/// @brief Contém a definição da classe DubininRadushkevich



#ifndef DUBININ_RADUSHKEVICH_H
#define DUBININ_RADUSHKEVICH_H

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {

/**
 * @brief Classe com as equações da isoterma de Dubinin-Radushkevich
 * 
 * Isoterma com dois parâmetros, \f$ q_{max} \f$ e \f$ K_1 \f$, cujas fórmulas são as seguintes:
 *
 * \f[
 *     Q_e (C_e, T) = q_{max} \exp( -K_1 \epsilon^2 )
 * \f]
 * \f[
 *     \epsilon = R T \ln \left(1 + \frac{1}{C_e} \right)
 * \f]
 * 
 * Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1021/cr60204a006).
 */
    
class DubininRadushkevich : public virtual TwoParameters, public IsothermTemplate<DubininRadushkevich> {
public:
    /**
     * @brief Definição de ID para esta classe para fins de identificação de erros.
     */
    DefineIdentity("DubininRadushkevich", ID::DubininRadushkevich);

    //==========================================================================
    // Construtores/Destrutor
    //==========================================================================

    /**
     * @brief Construtora default.
     */
    DubininRadushkevich() = default;

    /**
     * @brief Construtora de cópia.
     * @param _orig Variável do tipo DubininRadushkevich original.
     */
    DubininRadushkevich(const DubininRadushkevich& _orig) = default;

    /**
     * @brief Destrutora.
     */
    virtual ~DubininRadushkevich() = default;

    /**
     * @brief Construtora com os parâmetros que definem a isoterma de Dubinin-Radushkevich.
     * @param _qmax Constante de equilíbrio de Dubinin-Radushkevich.
     * @param _k1 Coeficiente associado à energia de adsorção.
     * @param _rgas Valor da constante universal dos gases diferente do padrão.
     * @exception std::invalid_argument se _qmax <= 0, _k1 <= 0, ou _rgas <= 0.
     */
    DubininRadushkevich(const Real& _qmax, const Real& _k1, const Real& _rgas = Isotherm::RGASCONST);

    /**
     * @brief Sobrecarga do operador =.
     * @param _orig Variável do tipo DubininRadushkevich original.
     * @return Cópia de _orig.
     */
    DubininRadushkevich& operator=(const DubininRadushkevich& _orig) = default;

    //==========================================================================
    // Acesso às constantes da classe
    //==========================================================================

    /**
     * @brief Retorna o valor da constante de equilíbrio de Dubinin-Radushkevich.
     * @return Valor da constante de equilíbrio de Dubinin-Radushkevich.
     */
    [[nodiscard]] Real Qmax() const { return Value(0); }

    /**
     * @brief Retorna o coeficiente associado à energia de adsorção.
     * @return Valor do coeficiente associado à energia de adsorção.
     */
    [[nodiscard]] Real K1() const { return Value(1); }

    /**
     * @brief Retorna o valor da constante universal dos gases.
     * @return Valor da constante universal dos gases.
     */
    [[maybe_unused]] [[nodiscard]] Real Rgas() const { return RGAS; }

    //==========================================================================
    // Alterando as constantes da classe
    //==========================================================================

    /**
     * @brief Altera a constante de equilíbrio de Dubinin-Radushkevich.
     * @param _qmax Novo valor da constante de equilíbrio de Dubinin-Radushkevich.
     * @exception std::invalid_argument se _qmax <= 0.
     */
    void Qmax(const Real& _qmax) {
        if (_qmax <= 0) throw std::invalid_argument("_qmax deve ser > 0");
        *this = DubininRadushkevich(_qmax, Value(1), this->Rgas());
    }

    /**
     * @brief Altera o coeficiente associado à energia de adsorção.
     * @param _k1 Novo valor do coeficiente associado à energia de adsorção.
     * @exception std::invalid_argument se _k1 <= 0.
     */
    void K1(const Real& _k1) {
        if (_k1 <= 0) throw std::invalid_argument("_k1 deve ser > 0");
        *this = DubininRadushkevich(Value(0), _k1, this->Rgas());
    }

    /**
     * @brief Altera o valor da constante universal dos gases.
     * @param _rgas Novo valor da constante universal dos gases.
     * @exception std::invalid_argument se _rgas <= 0.
     */
    [[maybe_unused]] void Rgas(const Real& _rgas) {
        if (_rgas <= 0) throw std::invalid_argument("_rgas deve ser > 0");
        *this = DubininRadushkevich(Value(0), Value(1), _rgas);
    }

    //==========================================================================
    // Funções virtuais
    //==========================================================================

    /**
     * @brief Calcula a quantidade de sorção no equilíbrio.
     * @param _c Concentração do soluto.
     * @param _temp Temperatura em K.
     * @return Valor da quantidade de sorção no equilíbrio.
     * @exception std::invalid_argument se _c <= 0 ou _temp <= 0.
     */
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp) const;

    /**
     * @brief Calcula a quantidade de sorção no equilíbrio.
     * @param _c Concentração do soluto.
     * @return Valor da quantidade de sorção no equilíbrio.
     * @exception std::invalid_argument se _c <= 0.
     */
    [[nodiscard]] inline Real Qe(const Real& _c) const override {
        return Qe(_c, 0);
    }

    /**
     * @brief Faz o clone da classe virtual.
     * @return Uma cópia da instância corrente.
     */
    [[maybe_unused]] [[nodiscard]] std::unique_ptr<Isotherm> CloneImplementation() const override {
        return std::make_unique<DubininRadushkevich>(*this);
    }

private:
    Real RGAS = Isotherm::RGASCONST; ///< Valor default da constante universal dos gases.
};

} // namespace ist

#endif // DUBININ_RADUSHKEVICH_H

/** @} */
