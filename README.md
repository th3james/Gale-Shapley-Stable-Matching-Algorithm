# Gale Shapley Stable Matching Algorithm
In this challenge you are tasked with matching the universities with their
preferences in preferences.csv with the potential students with their
preferences in students.csv.

## Steps

1. Each university offers a position with its most favoured student
2. Students who have received an offer then pick one based on their preferences
3. Universities who haven't had an offer accepted then make an offer to their second preference
4. The second preference student accepts the proposal if:
  * they haven't received an offer or
  * the proposed offer is a higher preference university for them than their current offer
5. loop to 3 if there are universities that are unmatched

