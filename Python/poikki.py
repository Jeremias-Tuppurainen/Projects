def print_box(width, height, mark):
    for luku in range(height):
        print(mark * width)

def read_input():
    while True:
        str = input("Enter the width of a frame: ")
        try:
            width = int(str)
            break
        except ValueError:
            continue

    while True:
        str = input("Enter the height of a frame: ")
        try:
            height = int(str)
            break
        except ValueError:
            continue

    mark = input("Enter a print mark: ")
    print()
    return width, height, mark


def main():
    width, height, mark = read_input()
    print_box(width, height, mark)

if __name__ == "__main__":
    main()
'''
Enter the width of a frame: 
'''
