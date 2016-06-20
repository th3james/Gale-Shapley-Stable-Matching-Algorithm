#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef std::string::const_iterator strItr_t;
typedef std::vector<std::string>::const_iterator strVecItr_t;

class OpinionatedEntity {
public:
  OpinionatedEntity(std::string name, std::vector<std::string> preferences) :
    n(name),
    prefs(preferences) {};

  static OpinionatedEntity buildFromCsvRow(std::string csvRow) {
    std::string elemBuff;
    std::string name;
    std::vector<std::string> preferences;

    for(strItr_t itr = csvRow.begin(); itr != csvRow.end(); itr++) {
      if (*itr == ',') {
        if (name.length() == 0) {
          name = elemBuff;
        } else {
          preferences.push_back(elemBuff);
        }
        elemBuff = "";
      } else {
        elemBuff.push_back(*itr);
      }
    }
    if (elemBuff.length() > 0) {
      if (name.length() == 0) {
        name = elemBuff;
      } else {
        preferences.push_back(elemBuff);
      }
    }
    return OpinionatedEntity(name, preferences);
  }

  const std::string toString() const {
    std::string str(n + ": ");
    for(strVecItr_t prefItr = prefs.begin(); prefItr != prefs.end(); prefItr++) {
      str += (*prefItr) + ", ";
    }
    return str;
  }

  const std::string name() const { return n; }
  const std::vector<std::string> preferences() const { return prefs; }

private:
  const std::string n;
  const std::vector<std::string> prefs;
};

typedef std::vector<OpinionatedEntity>::const_iterator opEdItr_t;

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
  for(opEdItr_t itr = students.begin(); itr != students.end(); itr++) {
    std::cout << itr->toString() << std::endl;
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
  for(opEdItr_t itr = universities.begin(); itr != universities.end(); itr++) {
    std::cout << itr->toString() << std::endl;
  }

  return 0;
}
