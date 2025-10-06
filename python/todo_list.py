# todo_list.py
tasks = []

def show_tasks():
    if not tasks:
        print("No tasks yet!")
    else:
        for i, task in enumerate(tasks, start=1):
            print(f"{i}. {task}")

def add_task(task):
    tasks.append(task)
    print(f"Task '{task}' added!")

def delete_task(index):
    if 0 < index <= len(tasks):
        removed = tasks.pop(index-1)
        print(f"Task '{removed}' removed!")
    else:
        print("Invalid task number.")

def menu():
    while True:
        print("\n1. Show Tasks\n2. Add Task\n3. Delete Task\n4. Exit")
        choice = input("Choose an option: ")
        if choice == '1':
            show_tasks()
        elif choice == '2':
            add_task(input("Enter task: "))
        elif choice == '3':
            delete_task(int(input("Enter task number to delete: ")))
        elif choice == '4':
            print("Goodbye!")
            break
        else:
            print("Invalid choice!")

if __name__ == "__main__":
    menu()
