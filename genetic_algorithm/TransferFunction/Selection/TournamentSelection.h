//
// Created by karla on 13. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_TOURNAMENTSELECTION_H
#define GENETIC_ALGORITHM_TOURNAMENTSELECTION_H

#include "../../SelectionOperator.h"

template <typename T>
class TournamentSelection : public SelectionOperator<T> {
    public:
        TournamentSelection(int sample_size) : sample_size(sample_size) {}
        void get_members( std::vector<T> &population, std::vector<T> &members );

    private:
        int sample_size;
};


#endif //GENETIC_ALGORITHM_TOURNAMENTSELECTION_H
