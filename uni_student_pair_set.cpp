#include <iostream>
#include "uni_student_pair_set.hpp"
#include "opinionated_entity.hpp"

const std::vector<UniStudentPair> PairUp::pairUp() {
  std::vector<OpinionatedEntity> unpairedUniversities = universities;
  while(unpairedUniversities.size() > 0) {
    for(size_t i = 0; i < unpairedUniversities.size(); i++) {
      OpinionatedEntity university = unpairedUniversities[i];
      proposePair(
        UniStudentPair(university.name(), university.preferences()[0])
      );
    }
    unpairedUniversities = getUnpairedUniversities();
  }
  return pairs;
};

void PairUp::proposePair(UniStudentPair pair) {
  if (studentHasPair(pair.studentName)) {
    UniStudentPair existingPair = getStudentPair(pair.studentName);
    OpinionatedEntity student = getStudentByName(pair.studentName);
    pairs.push_back(pair);
  } else {
    pairs.push_back(pair);
  }
};

std::vector<OpinionatedEntity> PairUp::getUnpairedUniversities() {
  std::vector<OpinionatedEntity> unpaired;

  for(size_t i = 0; i < universities.size(); i++) {
    OpinionatedEntity university = universities[i];
    if (!universityHasPair(university.name())) {
      unpaired.push_back(university);
    }
  }

  return unpaired;
};

bool PairUp::universityHasPair(const std::string uniName) {
  for(size_t i = 0; i < pairs.size(); i++) {
    UniStudentPair pair = pairs[i];
    if (pair.universityName == uniName) {
      return true;
    }
  }
  return false;
}

bool PairUp::studentHasPair(const std::string studentName) {
  for(size_t i = 0; i < pairs.size(); i++) {
    UniStudentPair pair = pairs[i];
    if (pair.studentName == studentName) {
      return true;
    }
  }
  return false;
}

const UniStudentPair PairUp::getStudentPair(const std::string studentName) {
  for(size_t i = 0; i < pairs.size(); i++) {
    UniStudentPair pair = pairs[i];
    if (pair.studentName == studentName) {
      return pair;
    }
  }
  return UniStudentPair("", "");
}

const OpinionatedEntity PairUp::getStudentByName(const std::string studentName) {
  for(size_t i = 0; i < students.size(); i++) {
    OpinionatedEntity student = students[i];
    if (student.name() == studentName) {
      return student;
    }
  }
  return OpinionatedEntity("", std::vector<std::string>());
}
