def calculate_angle(a, b=90):
    return int(180 - a - b)

def main():
    a = input(" 2")
    b = int(input(" 2"))
    calculate_angle(a, b)

    if __name__ == "__main__":
        main()
