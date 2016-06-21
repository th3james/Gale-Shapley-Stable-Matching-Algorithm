#include <iostream>
#include "uni_student_pair_set.hpp"
#include "opinionated_entity.hpp"

const std::vector<UniStudentPair> PairUp::pairUp() {
  std::vector<OpinionatedEntity> unpairedUniversities = universities;
  uint8_t round = 0;
  while(unpairedUniversities.size() > 0) {
    for(size_t i = 0; i < unpairedUniversities.size(); i++) {
      OpinionatedEntity university = unpairedUniversities[i];
      proposePair(
        UniStudentPair(university.name(), university.preferences()[round])
      );
    }
    unpairedUniversities = getUnpairedUniversities();
    round++;
  }
  return pairs;
};

void PairUp::proposePair(UniStudentPair pair) {
  std::cout << "\n"  << std::endl;
  std::cout << "### proposing pairing pairing between " << pair.studentName << " " << pair.universityName << std::endl;
  int32_t indexOfExistingPair = indexOfStudentPair(pair.studentName);
  if (indexOfExistingPair != -1) {
    UniStudentPair existingPair = getStudentPair(pair.studentName);
    std::cout << "existing pairing between " << existingPair.studentName << " " << existingPair.universityName << std::endl;
    OpinionatedEntity student = getStudentByName(pair.studentName);

    if (student.indexOfPreference(pair.universityName) < student.indexOfPreference(existingPair.universityName)) {
      std::cout << "removing pairing between " << existingPair.studentName << " " << existingPair.universityName << std::endl;
      pairs.erase(pairs.begin() + indexOfExistingPair);
      std::cout << "inserting pairing between " << pair.studentName << " " << pair.universityName << std::endl;
      pairs.push_back(pair);
    } else {
      std::cout << "^ pairing is better than " << pair.studentName << " " << pair.universityName << std::endl;
    }
  } else {
    std::cout << "inserting pairing between " << pair.studentName << " " << pair.universityName << std::endl;
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

int32_t PairUp::indexOfStudentPair(const std::string studentName) {
  for(size_t i = 0; i < pairs.size(); i++) {
    UniStudentPair pair = pairs[i];
    if (pair.studentName == studentName) {
      return i;
    }
  }
  return -1;
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
