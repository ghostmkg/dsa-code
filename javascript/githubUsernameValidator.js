function isValidGithubUsername(username) {
  // 1-39 chars, alphanumeric or hyphen, not start/end with hyphen, no consecutive hyphens
  const pattern = /^(?!-)(?!.*--)[A-Za-z0-9-]{1,39}(?<!-)$/;
  return pattern.test(username);
}
