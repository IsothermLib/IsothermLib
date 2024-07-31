//==============================================================================
// Name        : Henry.h
// Authors     : Aline Zuliani Lunkes
//               Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equações da isoterma de Henry
//
// Copyright   : Copyright (C) <2024>  Joao Flavio Vasconcellos
//                                      (jflavio at iprj.uerj.br)
//
// This program é software livre: você pode redistribuí-lo e/ou modificá-lo
// sob os termos da Licença Pública Geral GNU conforme publicada pela
// Free Software Foundation, na versão 3 da Licença.
//
// Este programa é distribuído na esperança de que seja útil,
// mas SEM NENHUMA GARANTIA; sem mesmo a garantia implícita de
// COMERCIABILIDADE ou ADEQUAÇÃO A UM DETERMINADO FIM. Veja a
// Licença Pública Geral GNU para mais detalhes.
//
// Você deve ter recebido uma cópia da Licença Pública Geral GNU
// junto com este programa. Se não, veja <http://www.gnu.org/licenses/>.
//
//==============================================================================

/** @defgroup Henry Henry
 *  @ingroup IsothermOne_Parameter
 *  @brief Classe Henry contém a equaçção da isoterma de Henry.
 *  @{
 */

/// @file Henry.h
/// @brief Contém a definição da classe Henry

#ifndef __HENRY_H__
#define __HENRY_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/OneParameter/OneParameter.h>

namespace ist {

/// <summary>
/// @brief Classe com as equações da isoterma de Henry.
/// </summary>
/// Isoterma com um parâmetro, \f$ K_1 > 0 \f$, cuja fórmula é a seguinte:
/// \f[
/// Q_e(C_e) = K_1 C_e
/// \f]
/// O artigo em que esta isoterma foi definida pode ser encontrado [aqui](https://doi.org/10.1098/rstl.1803.0004).
class Henry : public virtual OneParameter, public IsothermTemplate<Henry> {
    
//==============================================================================
// ID da classe
//==============================================================================

public:
    /// @brief Definição de ID para esta classe para fins de identificação de erros.
    DefineIdentity("Henry", ID::Henry);

//==============================================================================
// Funções Construtoras/Destrutora
//==============================================================================

public:
    /// @brief Construtora default.
    /// @code
    /// Henry var;
    /// @endcode
    Henry() = default;

    /// @brief Construtora de cópia.
    /// @param _orig Variável do tipo Henry original.
    /// @code
    /// Henry var;
    /// Henry var1(var);
    /// @endcode
    Henry(const Henry& _orig) = default;

    /// @brief Destrutora.
    virtual ~Henry() = default;

    /// @brief Construtora com o parâmetro que define a isoterma de Henry.
    /// @param _k1 Coeficiente de distribuição.
    /// @exception _k1 <= 0.
    /// @code
    /// Real k1(1.0);
    /// Henry var1(k1);
    /// @endcode
    Henry(const Real& _k1);

//==============================================================================
// Sobrecarga de operadores
//==============================================================================

public:
    /// @brief Sobrecarga do operador =.
    /// @param _orig Variável do tipo Henry original.
    /// @return Cópia de _orig.
    /// @code
    /// Henry var1(k1);
    /// Henry var2 = var1;
    /// @endcode
    Henry& operator=(const Henry& _orig) = default;

//==============================================================================
// Acesso às constantes da classe
//==============================================================================

public:
    /// @brief Função que informa o valor do coeficiente de distribuição.
    /// @return Valor do coeficiente de distribuição.
    /// @code
    /// Henry var1(k1);
    /// Real k1 = var1.K1();
    /// @endcode
    [[nodiscard]] inline Real K1() const {
        return Value(0);
    }

//==============================================================================
// Alterando as constantes da classe
//==============================================================================

public:
    /// @brief Função para alterar o valor do coeficiente de distribuição.
    /// @param _k1 Novo valor do coeficiente de distribuição.
    /// @exception _k1 <= 0.
    /// @code
    /// Henry var1(k1);
    /// Real k11(3.0);
    /// var1.K1(k11);
    /// @endcode
    inline void K1(const Real& _k1) {
        *this = Henry(_k1);
    }

//==============================================================================
// Funções virtuais
//==============================================================================

public:
    /// @brief Função que calcula a quantidade de sorção no equilíbrio.
    /// @param _c Concentração do soluto.
    /// @return Valor da quantidade de sorção no equilíbrio.
    /// @exception _c < 0.
    /// @code
    /// Henry var1(k);
    /// Real ce(1.0);
    /// Real qe = var1.Qe(ce);
    /// @endcode
    [[nodiscard]] inline Real Qe(const Real& _c) const override {
        return Qe(_c, 0);
    }

protected:
    [[nodiscard]] Real Qe(const Real& _c, const Real&) const override;

    [[nodiscard]] std::unique_ptr<Isotherm> CloneImplementation() const override {
        return std::make_unique<Henry>(*this);
    }
};

}

#endif /* __HENRY_H__ */

/** @} */
