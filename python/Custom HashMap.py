class HashMap:
    def __init__(self, size=10):
        self.size = size
        self.map = [[] for _ in range(size)]

    def _get_hash(self, key):
        return hash(key) % self.size

    def add(self, key, value):
        key_hash = self._get_hash(key)
        bucket = self.map[key_hash]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                bucket[i] = (key, value)  # update value
                return
        bucket.append((key, value))

    def get(self, key):
        key_hash = self._get_hash(key)
        bucket = self.map[key_hash]

        for k, v in bucket:
            if k == key:
                return v
        return None  # key not found

    def remove(self, key):
        key_hash = self._get_hash(key)
        bucket = self.map[key_hash]

        for i, (k, v) in enumerate(bucket):
            if k == key:
                del bucket[i]
                return True
        return False

    def display(self):
        # Show hashmap contents
        for i, bucket in enumerate(self.map):
            if bucket:
                print(f"Bucket {i}: {bucket}")


# 🔹 Example Usage
hashmap = HashMap()

hashmap.add("name", "Gaurav")
hashmap.add("role", "Full Stack Developer")
hashmap.add("language", "Python")
hashmap.add("experience", 3)

print("Name:", hashmap.get("name"))
print("Role:", hashmap.get("role"))

hashmap.add("experience", 4)  # update value
print("Updated experience:", hashmap.get("experience"))

hashmap.remove("language")

print("\nHashMap Contents:")
hashmap.display()