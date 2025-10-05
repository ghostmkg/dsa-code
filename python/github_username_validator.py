import re

def is_valid_github_username(username):
    # GitHub username rules:
    # 1. 1-39 characters
    # 2. Only alphanumeric or hyphens
    # 3. Cannot start or end with hyphen
    # 4. Cannot have consecutive hyphens
    pattern = r'^(?!-)(?!.*--)[A-Za-z0-9-]{1,39}(?<!-)$'
    return bool(re.match(pattern, username))

if __name__ == "__main__":
    username = input("Enter GitHub username: ")
    print("Valid" if is_valid_github_username(username) else "Invalid")
