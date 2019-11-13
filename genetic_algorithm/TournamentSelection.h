//
// Created by karla on 13. 11. 2019..
//

#ifndef GENETIC_ALGORITHM_TOURNAMENTSELECTION_H
#define GENETIC_ALGORITHM_TOURNAMENTSELECTION_H

#include "SelectionOperator.h"

class TournamentSelection : public SelectionOperator {
    public:
        TournamentSelection(int sample_size) : sample_size(sample_size) {}
        std::vector<Solution> get_members( std::vector<Solution> population );

    private:
        int sample_size;
};


#endif //GENETIC_ALGORITHM_TOURNAMENTSELECTION_H
