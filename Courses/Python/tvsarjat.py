def analyze_file(file):
    hakemisto = {}
    avaible_genres = []
    for row in file:

        # If the input row was correct, it contained two parts:
        # · the show name before semicolon (;) and
        # · comma separated list of genres after the semicolon.
        # If we know that a function (method split in this case)
        # returns a list containing two elements, we can assign
        # names for those elements as follows:
        name, genres = row.rstrip().split(";")

        genres = genres.split(",")
        for genre in genres:
            if genre not in avaible_genres:
                avaible_genres.append(genre)

        if name not in hakemisto:
            hakemisto[name] = genres

        # TODO add the name and genres data to the data structure
    avaible_genres = sorted(list(set(avaible_genres)))
    return hakemisto, avaible_genres


def main():
    filename = input("Enter the name of the file: ")
    try:
        file = open(filename, mode="r")
        genre_data, available_genres = analyze_file(file)

        print("Available genres are: ", end="")
        print(*available_genres, sep=", ")

        while True:
            genre = input("> ")

            if genre == "exit":
                return

            for movie, genret in sorted(genre_data.items()):
                if genre in genret:
                    print(movie)

        # print(name)
        # TODO print the series belonging to a genre.

    except ValueError:
        print("Error: rows were not in the format name;genres.")

    except IOError:
        print("Error: the file could not be read.")



if __name__ == "__main__":
    main()
