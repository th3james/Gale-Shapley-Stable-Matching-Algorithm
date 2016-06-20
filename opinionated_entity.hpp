#ifndef OPINIONATED_ENTITY_H
#define OPINIONATED_ENTITY_H

#include <string>
#include <vector>

typedef std::string::const_iterator strItr_t;
typedef std::vector<std::string>::const_iterator strVecItr_t;

class OpinionatedEntity {
public:
  OpinionatedEntity(std::string name, std::vector<std::string> preferences) :
    n(name),
    prefs(preferences) {};

  static OpinionatedEntity buildFromCsvRow(std::string csvRow);

  const std::string toString() const;

  const std::string name() const { return n; }
  const std::vector<std::string> preferences() const { return prefs; }

private:
  const std::string n;
  const std::vector<std::string> prefs;
};

typedef std::vector<OpinionatedEntity>::const_iterator opEdItr_t;

#endif
