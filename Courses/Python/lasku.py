def main():
    filename = input("Enter the name of the score file: ")

    try:
        file = open(filename, mode="r")

    except OSError:
        print("There was an error in reading the file.")
        return

    dicti = {}
    for file_line in file:
        file_line = file_line.rstrip()
        try:
            name, score = file_line.split(" ")
            try:
                val = int(score)
                if name in dicti:
                    dicti[name] += int(score)
                else:
                    dicti[name] = int(score)
            except ValueError:
                print("There was an erroneous score in the file:")
                print(score)
                return
        except:
            print("There was an erroneous line in the file:")
            print(file_line)
            return


    print("Contestant score:")
    for name, score in sorted(dicti.items()):
        print(name, score)


main()
