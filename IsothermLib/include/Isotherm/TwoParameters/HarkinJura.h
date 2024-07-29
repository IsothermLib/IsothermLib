//==============================================================================
// Name        : HarkinJura.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de HarkinJura
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

/** @defgroup HarkinJura Harkin-Jura
 *  @ingroup Two_Parameters
 *  Classe HarkinJura contem a equacao da isoterma de Harkin-Jura.
 */

/// <summary>
/// Classe com as equacoes da isoterma de HarkinJura
/// </summary>
///  Isoterma com dois parametros, \f$ K_1 \f$ e \f$ K_2 \f$,  cujas formulas sao as seguintes:
///\begin{align}
///     \[\frac{1}{Q_e(C_e, T)^{2}} = \frac{K_2 - 1}{K_1}log(C_e)\]
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

#ifndef __HARKIN_JURA_H__
#define __HARKIN_JURA_H__



//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {

class HarkinJura :  public virtual TwoParameters, 
                    public IsothermTemplate < HarkinJura > {
    
//==============================================================================
// ID da classe
//==============================================================================

private:    
    
 
/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
/// <example>
    DefineIdentity("HarkinJura", ID::HarkinJura);  
    

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
///     HarkinJura  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    HarkinJura() = default;
    
/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HarkinJura  var;
///     HarkinJura  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo HarkinJura original.
    HarkinJura(const HarkinJura& _orig) = default;
    
/// <summary>
/// Destrutora.
/// </summary>
    virtual ~HarkinJura() = default;
    
/// <summary>
/// Construtora com os parametros que definem a isoterma de HarkinJura.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real k1(1.0);
///     Real k2(1.0);            
///     HarkinJura  var1(k1, k2);              
/// @endcode
/// </example>
///  @param _k1 Constante da isoterma de Harkin-Jura.   
///  @param  _k2 Constante da isoterma de Harkin-Jura. 
///  @exception _k1 <= 0.
///  @exception _k2 <= 0.
    HarkinJura (const Real& _k1, const Real& _k2);
    
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
///     HarkinJura  var1(k1, k2);              
///     HarkinJura  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo HarkinJura original.
///  @return Copia de _orig. 
    HarkinJura& operator = (const HarkinJura& _orig) = default;

//==============================================================================
// Acesso as constantes da classe inline
//==============================================================================

/// <summary>
/// Funcao que informa o valor da constante da isoterma de Harkin-Jura.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HarkinJura  var1(k1, k2);              
///     Real _k1 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da constante da isoterma de Harkin-Jura.
inline Real K1 () const {return  Value(0);};

/// <summary>
/// Funcao que informa o valor da constante da isoterma de Harkin-Jura.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HarkinJura  var1(k1, k2);              
///     Real _k2 = var1.K2();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor da constante da isoterma de Harkin-Jura.
inline Real K2 () const {return  Value(1);};

//==============================================================================
// Alterando as constantes da classe
//==============================================================================
public:
    
/// <summary>
/// Funcao para alterar o valor da constante da isoterma de Harkin-Jura.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HarkinJura  var1(k1, k2);              
///     Real k11(3.0);
///     var1.K1(k11);
/// @endcode
/// </example>
///  @param _k1 Novo valor da constante da isoterma de Harkin-Jura.
///  @exception _k1 <= 0.
    void K1 (const Real& _k1)  {*this = HarkinJura(_k1, Value(1));};


/// <summary>
/// Funcao para alterar o valor da constante da isoterma de Harkin-Jura.
/// </summary>
/// <example>
/// Uso:
/// @code
///     HarkinJura  var1(k1, k2);              
///     Real _k22(2.0);
///     var1.K2(_k22);
/// @endcode
/// </example>
///  @param _k2 Novo valor da constante da isoterma de Harkin-Jura.
///  @exception _k2 <= 0.
    void K2 (const Real& _k2)  {*this = HarkinJura(Value(0), _k2);};

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
///     HarkinJura  var1(k1, k2);              
///     Real ce(1.0);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @return Valor da quantidade de sorcao no equilibrio.    
///  @exception _c < 0.
    
    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }    
    
    private: 
    [[nodiscard]] 
    Real Qe (const Real&_c, const Real& _temp) const override;
    
    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<HarkinJura>(*this);
    }       

 
    
};

/// \example TesteHarkinJura.cpp
///Este e um arquivo com exemplos de aplicacao da classe HarkinJura.
}
        
#endif /* __HARKIN_JURA_H__ */

/** @} */ 
        
   