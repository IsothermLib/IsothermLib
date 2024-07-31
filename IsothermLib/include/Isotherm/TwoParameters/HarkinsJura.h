//==============================================================================
// Name        : HarkinsJura.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Harkins-Jura
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

/** @defgroup HarkinsJura Harkins-Jura
 *  @ingroup IsothermTwo_Parameters
 *  @brief Classe HarkinsJura contém a equação da isoterma de Harkins-Jura.
 *  @{
 */

/// @file HarkinsJura.h
/// @brief Contém a definição da classe HarkinsJura

#ifndef __HARKIN_JURA_H__
#define __HARKIN_JURA_H__

//==============================================================================
// Include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {

/// @class HarkinsJura
/// @brief Classe com as equações da isoterma de Harkins-Jura
///
/// Isoterma com dois parâmetros, \f$ K_1 \f$ e \f$ K_2 \f$, cujas fórmulas são as seguintes:
/// \f[
/// \frac{1}{Q_e(C_e)^{2}} = \frac{K_2 - \log(C_e)}{K_1} 
/// \f]
/// Um artigo de referência pode ser encontrado [aqui](https://doi.org/10.1016/j.matpr.2022.04.533).
class HarkinsJura : public virtual TwoParameters, public IsothermTemplate<HarkinsJura> {
    
//==============================================================================
// ID da classe
//==============================================================================

private:    
    
    /// @brief Definição de ID para esta classe para fins de identificação de erros.
    DefineIdentity("HarkinsJura", ID::HarkinsJura);  
    
//==============================================================================
// Funções Construtoras/Destrutora
//==============================================================================

public:
    
    /// @brief Construtora default.
    /// @code
    /// HarkinsJura var;
    /// @endcode
    HarkinsJura() = default;
    
    /// @brief Construtora de cópia.
    /// @param _orig Variável do tipo HarkinsJura original.
    /// @code
    /// HarkinsJura var;
    /// HarkinsJura var1(var);
    /// @endcode
    HarkinsJura(const HarkinsJura& _orig) = default;
    
    /// @brief Destrutora.
    virtual ~HarkinsJura() = default;
    
    /// @brief Construtora com os parâmetros que definem a isoterma de Harkins-Jura.
    /// @param _k1 Constante da isoterma de Harkins-Jura.
    /// @param _k2 Constante da isoterma de Harkins-Jura.
    /// @exception _k1 <= 0.
    /// @exception _k2 <= 0.
    /// @code
    /// Real k1(1.0);
    /// Real k2(1.0);            
    /// HarkinsJura var1(k1, k2);              
    /// @endcode
    HarkinsJura(const Real& _k1, const Real& _k2);
    
//==============================================================================
// Sobrecarga de operadores
//==============================================================================

public:
    
    /// @brief Sobrecarga do operador =.
    /// @param _orig Variável do tipo HarkinsJura original.
    /// @return Cópia de _orig.
    /// @code
    /// HarkinsJura var1(k1, k2);              
    /// HarkinsJura var2 = var1;
    /// @endcode
    HarkinsJura& operator=(const HarkinsJura& _orig) = default;

//==============================================================================
// Acesso às constantes da classe inline
//==============================================================================

public:
    /// @brief Função que informa o valor da constante da isoterma de Harkins-Jura.
    /// @return Valor da constante da isoterma de Harkins-Jura.
    /// @code
    /// HarkinsJura var1(k1, k2);              
    /// Real _k1 = var1.K1();
    /// @endcode
    [[nodiscard]] inline Real K1() const { return Value(0); }

    /// @brief Função que informa o valor da constante da isoterma de Harkins-Jura.
    /// @return Valor da constante da isoterma de Harkins-Jura.
    /// @code
    /// HarkinsJura var1(k1, k2);              
    /// Real _k2 = var1.K2();
    /// @endcode
    [[nodiscard]] inline Real K2() const { return Value(1); }

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

public:
    /// @brief Função para alterar o valor da constante da isoterma de Harkins-Jura.
    /// @param _k1 Novo valor da constante da isoterma de Harkins-Jura.
    /// @exception _k1 <= 0.
    /// @code
    /// HarkinsJura var1(k1, k2);              
    /// Real k11(3.0);
    /// var1.K1(k11);
    /// @endcode
    inline void K1(const Real& _k1) { *this = HarkinsJura(_k1, Value(1)); }

    /// @brief Função para alterar o valor da constante da isoterma de Harkins-Jura.
    /// @param _k2 Novo valor da constante da isoterma de Harkins-Jura.
    /// @exception _k2 <= 0.
    /// @code
    /// HarkinsJura var1(k1, k2);              
    /// Real _k22(2.0);
    /// var1.K2(_k22);
    /// @endcode
    inline void K2(const Real& _k2) { *this = HarkinsJura(Value(0), _k2); }

//==============================================================================
// Funções virtuais
//==============================================================================
   
public:
    /// @brief Função que calcula a quantidade de sorção no equilíbrio.
    /// @param _c Concentração do soluto.
    /// @return Valor da quantidade de sorção no equilíbrio.
    /// @exception _c < 0.
    /// @code
    /// HarkinsJura var1(k1, k2);              
    /// Real ce(1.0);
    /// Real qe = var1.Qe(ce);
    /// @endcode
    [[nodiscard]] inline Real Qe(const Real& _c) const override {
        return Qe(_c, 0);
    }

private:
    [[nodiscard]] Real Qe(const Real& _c, const Real& _temp) const override;

    [[nodiscard]] std::unique_ptr<Isotherm> CloneImplementation() const override {
        return std::make_unique<HarkinsJura>(*this);
    }
};


}

#endif /* __HARKIN_JURA_H__ */

/** @} */
