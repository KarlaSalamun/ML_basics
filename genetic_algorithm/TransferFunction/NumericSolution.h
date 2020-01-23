//
// Created by karla on 18. 01. 2020..
//

#ifndef TRANSFERFUNCTION_NUMERICSOLUTION_H
#define TRANSFERFUNCTION_NUMERICSOLUTION_H

#include "../Solution.h"

template <typename T>
class NumericSolution : public Solution<T> {
    public:
        T data;
        double fitness;
};


#endif //TRANSFERFUNCTION_NUMERICSOLUTION_H
