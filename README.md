# Gale Shapley Stable Matching Algorithm
In this challenge you are tasked with matching the universities in
universities.csv with the potential students in students.csv based on the
preferences included in those files.

## Steps

1. Each university offers a position with its most favoured student
2. Students who have received an offer then accept an offer based on their preferences
3. Universities who haven't had an offer accepted then make an offer to their next preference
4. Students accept the new proposals if:
  * they haven't received an offer or
  * the proposed offer is a higher preference university for them than their current offer
5. loop to 3 if there are universities that are unmatched

