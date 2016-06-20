#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class OpinionatedEntity {
public:
  OpinionatedEntity(std::string name, std::vector<std::string> preferences) :
    n(name),
    prefs(preferences) {};
private:
  const std::string n;
  const std::vector<std::string> prefs;
};

typedef std::string::const_iterator strItr_t;

int main() {
  std::ifstream studentFile;
  studentFile.open("students.csv");
  std::vector<OpinionatedEntity> students;

  std::string line;
  for(studentFile >> line; !studentFile.eof(); studentFile >> line) {
    std::string elemBuff;
    std::string name;
    std::vector<std::string> preferences;
    for(strItr_t itr = line.begin(); itr != line.end(); itr++) {
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

      students.push_back(OpinionatedEntity(name, preferences));
    }
  }

  return 0;
}
