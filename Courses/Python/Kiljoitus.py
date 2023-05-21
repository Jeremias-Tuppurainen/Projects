def main():
    filename = input("Enter the name of the file: ")
    try:
        write_file = open(filename, mode="w")

    except OSError:
        print("Writing the file", filename, "was not successful.")
        return

    print("Enter rows of text. Quit by entering an empty row.")
    texti = []

    while True:
        text_line = input()
        if text_line == "":
            break
        else:
            texti.append(text_line)
    i = 0
    x = 0
    for file_line in texti:
        x += 1
        file_line = file_line.rstrip()
        print(x, texti[i], file=write_file)
        i += 1

    write_file.close()
    print("File", filename, "has been written.")


if __name__ == "__main__":
    main()
