def main():
    filename = input("Enter the name of the file: ")

    try:
        file = open(filename, mode="r")

    except OSError:
      #  print(f"Error: opening the file '{filename}' failed!")
        print("There was an error in reading the file.")
        return
    x = 0
    for file_line in file:
        x += 1
        file_line = file_line.rstrip()
        print(x, file_line)

    file.close()


main()
