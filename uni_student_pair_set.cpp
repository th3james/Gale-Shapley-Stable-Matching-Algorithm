#include "uni_student_pair_set.hpp"
#include "opinionated_entity.hpp"

const std::vector<UniStudentPair> PairUp::pairUp() {
  std::vector<OpinionatedEntity> unpairedUniversities = universities;
  while(unpairedUniversities.size() > 0) {
    for(size_t i = 0; i < universities.size(); i++) {
      OpinionatedEntity university = universities[i];
      proposePair(
        UniStudentPair(university.name(), university.preferences()[0])
      );
    }
    unpairedUniversities = std::vector<OpinionatedEntity>();
  }
  return pairs;
};

void PairUp::proposePair(UniStudentPair pair) {
};
