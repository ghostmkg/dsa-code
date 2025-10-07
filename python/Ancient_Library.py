# The Ancient Library Scroll Grouping Problem
# You've stumbled upon a collection of ancient scrolls in a long-forgotten library.
# Each scroll is represented by a string of symbols. You quickly realize that many
# scrolls are just different arrangements of the same set of symbols—meaning they are
# fragments of the same original manuscript.
#
# Your task is to group the scrolls that are anagrams of each other.
#
# For example, if you have the scrolls:
# ["arc", "car", "cat", "act", "race", "acre"]
#
# The correct grouping would be:
# [["arc", "car"], ["cat", "act"], ["race", "acre"]]
#
# The Question : Write a function that takes a list of scroll strings and returns a list of
# these groups. The order of the groups and the scrolls within them doesn't matter.

from collections import defaultdict

def ancient_scrolls_group(scrolls):
    groups = defaultdict(list)

    for scroll in scrolls:
        signature = "".join(sorted(scroll))
        groups[signature].append(scroll)
        
    return list(groups.values())

if __name__ == '__main__':
    discovered_scrolls = [
        "tea", "map", "eat", "ate", "pam", "pat", "tap"
    ]
    
    manuscripts = ancient_scrolls_group(discovered_scrolls)
    
    print("Discovered scrolls:", discovered_scrolls)
    print("\nGrouped into original manuscripts:")
    for group in manuscripts:
        print(group)

#this is my attempt , it can be improved.