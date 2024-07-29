//==============================================================================
// Name        : Elovich.h
// Authors     : Iasmim Barboza Storck
//               Lara Botelho Brum
//               Luan Rodrigues Soares de Souza
//               Joao Flavio Vieira de Vasconcellos
// Version     : 1.0
// Description : Classe com as equacoes da isoterma de Elovich
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

/** @defgroup Elovich  Elovich
 *  @ingroup Two_Parameters
 *  Classe Elovich contem a equacao da isoterma de Elovich.
 *  @{
 */

/// <summary>
/// Classe com as equacoes da isoterma de Elovich
/// </summary>
///  Isoterma com dois parametros, \f$ K_1 \f$ e \f$ q_{max} \f$,  cujas formulas sao as seguintes:
///\begin{align}
///     Q_e (C_e) &= q_{max} \theta \hfil  \\\ \\\
///     \theta &= K_1 C_e e^{-\theta}
///\end{align}
///  Um artigo de referencia pode ser encontrado [aqui](https://doi.org/10.1007/BF00908016).
///  \authors   Iasmim Barboza Storck
///  \authors   Lara Botelho Brum
///  \authors   Luan Rodrigues Soares de Souza
///  \authors   Joao Flavio Vieira de Vasconcellos
///  \version   1.0
///  \date      2022
///  \bug       Nao ha bugs conhecidos.
///  
///  \copyright GNU Public License.

#ifndef __ISO_ELOVICH_H__
#define	__ISO_ELOVICH_H__

//==============================================================================
// include da isotherm++
//==============================================================================

#include <Isotherm/TwoParameters/TwoParameters.h>

namespace ist {


/** << NOTE
 * \brief Defines a class for stuff. 
 * \tparam Elovich  TTipo importante.
 */

class Elovich :  public virtual TwoParameters, 
                 public IsothermTemplate < Elovich > {
    
//==============================================================================
// ID da classe
//==============================================================================

public:    
    
/// <summary>
/// Definicao de ID para esta classe para fins de identificacao de erros.
/// </summary>
    DefineIdentity  (   "Elovich"
                    ,   ID::Elovich
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
///     Elovich  var;
/// @endcode
/// </example>
/// @param " " Nao ha parametros para esta funcao
    Elovich() = default;
    
/// <summary>
/// Construtora de copia.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Elovich  var;
///     Elovich  var1(var);
/// @endcode
/// </example>
/// @param  _orig Variavel do tipo Elovich original.
    Elovich(const Elovich& _orig) = default;
    
/// <summary>
/// Destrutora.
/// </summary>
    ~Elovich() override = default;
    
/// <summary>
/// Construtora com os parametros que definem a isoterma de Elovich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Real qmax(1.0);
///     Real k1(1.0);            
///     Elovich var1(qmax, k1);              
/// @endcode
/// </example>
///  @param _qmax Capacidade maxima de adsorcao.    
///  @param  _k1 Constante da isoterma de Elovich. 
///  @exception _qmax <= 0.
///  @exception _k1 <= 0.
    Elovich     (   const Real&     _qmax
                ,   const Real&     _k1
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
///     Elovich  var1(q1, k2);              
///     Elovich  var2 = var1;
/// @endcode
/// </example>
///  @param _orig Variavel do tipo Elovich original.
///  @return Copia de _orig.   
    Elovich& operator = (const Elovich& _orig) = default;

//==============================================================================
// Acesso as constantes da classe
//==============================================================================

/// <summary>
/// Funcao que informa o valor da capacidade maxima de adsorcao em [M /M ].
/// </summary>
/// <example>
/// Uso:
/// @code
///     Elovich  var1(q1, k1);              
///     Real q1 = var1.Qmax();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente de distribuicao em [M /M ].
[[nodiscard]] 
inline Real Qmax () const
{
    return  Value(0);
};


/// <summary>
/// Funcao que retorna o coeficiente associado a constante de equilibrio de Elovich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Elovich  var1(q1, k1);              
///     Real k2 = var1.K1();
/// @endcode
/// </example>
///  @param " " Nao ha parametros.
///  @return Valor do coeficiente associado a constante de equilibrio de Elovich.    
[[nodiscard]] 
inline Real K1 () const
{
    return  Value(1);
};
  
//==============================================================================
// Alterando as constantes da classe
//==============================================================================

/// <summary>
/// Funcao para alterar a capacidade maxima de adsorcao em [M /M ].   .
/// </summary>
/// <example>
/// Uso:
/// @code
///     Elovich  var1(q1, k1);              
///     Real q2(3.0);
///     var1.Qmax(q2);
/// @endcode
/// </example>
///  @param _qmax Novo valor da capacidade maxima de adsorcao em [M /M ].   .
///  @exception _qmax <= 0.   
inline void Qmax (  const Real& _qmax)  
{
    *this = Elovich(_qmax, Value(1));
};


/// <summary>
/// Funcao que altera o coeficiente associado a constante de equilibrio de Elovich.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Elovich  var1(q1, k1);              
///     Real k2(2.0);
///     var1.K1(k2);
/// @endcode
/// </example>
///  @param _k1 Novo valor do coeficiente associado a constante de equilibrio de Elovich.
///  @exception _k1 <= 0.
inline void K1 (const Real& _k1)  
{
    *this = Elovich(Value(0), _k1);
};

//==============================================================================
// Funcoes virtuais
//==============================================================================
    
/// <summary>
/// Funcao que calcula a quantidade de sorcao no equilibrio.
/// </summary>
/// <example>
/// Uso:
/// @code
///     Elovich  var1(q1, k1);              
///     Real ce(1);
///     Real qe = var1.Qe(ce);
/// @endcode
/// </example>
///  @param _c Concentracao do soluto.
///  @param _temp Variavel nao utilizada neste modelo e que pode ser omitida.
///  @return Valor da quantidade de sorcao no equilibrio.    
///  @exception _c < 0.
    [[nodiscard]] 
    Real Qe (const Real&_c, const Real& _temp) const override;

    [[nodiscard]] 
    inline Real Qe   (   const Real& _c
    ) const override
    {
        return Qe(_c, 0);
    }
    
    

    [[nodiscard]]
    virtual std::unique_ptr<Isotherm> CloneImplementation() const override
    {
        return std::make_unique<Elovich>(*this);
    }
    
    
//==============================================================================
// Dados da classe
//==============================================================================

private:
    
   [[nodiscard]] Real  FQe (const Real&) const;

private:
    
   Real                 auxiCe = 0;

};

/// \example TesteElovich.cpp

}
        

#endif	/* __ISO_ELOVICH_H__ */

/** @} */ 