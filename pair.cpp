#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <experimental/optional>

#include "opinionated_entity.hpp"
#include "uni_student_pair_set.hpp"

typedef std::string::const_iterator strItr_t;
typedef std::vector<std::string>::const_iterator strVecItr_t;

std::experimental::optional<OpinionatedEntity> findEntityByName(const std::vector<OpinionatedEntity> &entities, const std::string &name) {
  for(opEdItr_t itr = entities.begin(); itr != entities.end(); itr++) {
    if (itr->name() == name) {
      return std::experimental::optional<OpinionatedEntity>(*itr);
    }
  }
  return std::experimental::optional<OpinionatedEntity>();
}

int main() {
  std::ifstream studentFile;
  studentFile.open("students.csv");
  std::vector<OpinionatedEntity> students;

  std::string line;
  for(studentFile >> line; !studentFile.eof(); studentFile >> line) {
    students.push_back(
      OpinionatedEntity::buildFromCsvRow(line)
    );
  }
  studentFile.close();

  std::ifstream universityFile;
  universityFile.open("universities.csv");
  std::vector<OpinionatedEntity> universities;

  for(universityFile >> line; !universityFile.eof(); universityFile >> line) {
    universities.push_back(
      OpinionatedEntity::buildFromCsvRow(line)
    );
  }
  universityFile.close();

  std::vector<UniStudentPair> pairings = PairUp::pairUp(
    universities, students
  );

  for(uint8_t i = 0; i < pairings.size(); i++) {
    UniStudentPair pair = pairings[i];

    std::cout << pair.universityName << ", " << pair.studentName << std::endl;
  }

  return 0;
}
