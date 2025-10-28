# Reverse Words in a String
# Hacktoberfest Contribution by <your_name>

def reverse_words(sentence: str) -> str:
    words = sentence.split()
    return " ".join(reversed(words))


if __name__ == "__main__":
    text = input("Enter a sentence: ")
    print("Reversed sentence:", reverse_words(text))
