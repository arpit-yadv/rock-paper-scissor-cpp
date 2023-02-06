#ifndef SPOCKLIZARD_H
#define SPOCKLIZARD_H


#include <string>
#include <array>
#include <cmath>
#include "rockPaperScissors.h"

class SpockLizard : public RockPaperScissors
{
public:
    SpockLizard();       /// Constructor
    virtual ~SpockLizard() = default; /// Virtual destructor to prevent delete errors
    virtual void welcome() const override;        /// Options message 
    virtual void initializeResultMatrix() override;   
    virtual void initializeChoices() override;     /// Options message
};

#endif // SPOCKLIZARD_H
