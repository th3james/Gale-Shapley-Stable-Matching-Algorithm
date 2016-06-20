#include "opinionated_entity.hpp"

OpinionatedEntity OpinionatedEntity::buildFromCsvRow(std::string csvRow) {
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
};

const std::string OpinionatedEntity::toString() const {
  std::string str(n + ": ");
  for(strVecItr_t prefItr = prefs.begin(); prefItr != prefs.end(); prefItr++) {
    str += (*prefItr) + ", ";
  }
  return str;
}

const size_t OpinionatedEntity::indexOfPreference(const std::string prefName) const {
  for(size_t i = 0; i < prefs.size(); i++) {
    if (prefs[i] == prefName) {
      return i;
    }
  }
  return 9001;
}
