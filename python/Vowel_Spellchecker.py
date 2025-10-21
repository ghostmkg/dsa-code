class Solution:
    def spellchecker(self, wordlist: List[str], queries: List[str]) -> List[str]:
        vowels = set("aeiou")
    
        def devowel(word):
            return ''.join('*' if c in vowels else c for c in word.lower())
        
        exact_words = set(wordlist)
        case_insensitive = {}
        vowel_insensitive = {}
        
        for word in wordlist:
            lower = word.lower()
            if lower not in case_insensitive:
                case_insensitive[lower] = word
            dev = devowel(word)
            if dev not in vowel_insensitive:
                vowel_insensitive[dev] = word
        
        result = []
        for q in queries:
            if q in exact_words:  
                result.append(q)
            elif q.lower() in case_insensitive:  
                result.append(case_insensitive[q.lower()])
            elif devowel(q) in vowel_insensitive: 
                result.append(vowel_insensitive[devowel(q)])
            else:
                result.append("")
        
        return result
        