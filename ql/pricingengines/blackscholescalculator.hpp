/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2006 Ferdinando Ametrano

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/reference/license.html>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

/*! \file blackscholescalculator.hpp
    \brief Black-Scholes formula calculator class
*/

#ifndef quantlib_blackscholescalculator_hpp
#define quantlib_blackscholescalculator_hpp

#include <ql/pricingengines/blackcalculator.hpp>

namespace QuantLib {

    //! Black-Scholes 1973 calculator class
    class BlackScholesCalculator : public BlackCalculator {
      public:
        BlackScholesCalculator(
                        const boost::shared_ptr<StrikedTypePayoff>& payoff,
                        Real spot,
                        DiscountFactor growth,
                        Real stdDev,
                        DiscountFactor discount);
        virtual ~BlackScholesCalculator() {}
        /*! Sensitivity to change in the underlying spot price. */
        Real delta() const;
        /*! Sensitivity in percent to a percent change in the
            underlying spot price. */
        Real elasticity() const;
        /*! Second order derivative with respect to change in the
            underlying spot price. */
        Real gamma() const;
        /*! Sensitivity to time to maturity. */
        Real theta(Time maturity) const;
        /*! Sensitivity to time to maturity per day
            (assuming 365 day in a year). */
        Real thetaPerDay(Time maturity) const;
      protected:
        Real spot_;
        DiscountFactor growth_;
    };

}

#endif