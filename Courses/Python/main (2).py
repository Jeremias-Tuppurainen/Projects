def read_file(filename):
    hakemisto = {}
    try:
        file = open(filename, mode="r")

        for row in file:

            key, name, phone, email, skype = row.rstrip().split(";")

            if key not in hakemisto:
                rivi = {'name': name, 'phone': phone, 'email': email, 'skype': skype}
                hakemisto[key] = rivi

    except ValueError:
        print("Error: rows were not in the format name;genres.")

    except IOError:
        print("Error: the file could not be read.")

    return hakemisto

def main():
    filename = input("Enter the name of the file: ")
    avain = input("whaat yu want?")
    category = input("kategoria:")
    hakemisto = read_file(filename)
    print(hakemisto[avain][category])


main()