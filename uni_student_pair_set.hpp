#ifndef UNI_STUDENT_PAIRUP_H
#define UNI_STUDENT_PAIRUP_H

#include <string>
#include <vector>

#include "opinionated_entity.hpp"

struct UniStudentPair {
  UniStudentPair(
    std::string un, std::string sn
  ) : universityName(un), studentName(sn) {}
  std::string universityName;
  std::string studentName;
};

class PairUp {
public:
  PairUp(
    std::vector<OpinionatedEntity> us,
    std::vector<OpinionatedEntity> ss
  ) : universities(us), students(ss) {};

  static const std::vector<UniStudentPair> pairUp(
    std::vector<OpinionatedEntity> us,
    std::vector<OpinionatedEntity> ss
  ) {
    PairUp pairer = PairUp(ss, us);
    return pairer.pairUp();
  }

  const std::vector<UniStudentPair> pairUp();

private:
  void proposePair(UniStudentPair pair);

  const std::vector<OpinionatedEntity> universities;
  const std::vector<OpinionatedEntity> students;
  std::vector<UniStudentPair> pairs;
};

#endif
